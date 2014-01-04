#include "tcp_client.h"
#include "message_notification.h"

TcpClient::TcpClient(MessageHandler& handler)
    : _blockPacketization(std::bind(&TcpClient::finishedPacketCallback, this, std::placeholders::_1)),
    _buffer(new byte[MAX_RECV_LEN]), _handler(handler), _socket(nullptr), _reactor(nullptr), _reactorThread(nullptr)
{

}

TcpClient::~TcpClient()
{
    resetNetwork();
}

bool TcpClient::connect(Poco::Net::SocketAddress& address, const Poco::Timespan& timeout/* = Poco::Timespan(50000)*/)
{
    try
    {
        resetNetwork();

        _socket = new Poco::Net::StreamSocket;
        _reactor = new Poco::Net::SocketReactor;

        _reactor->addEventHandler(*_socket, Poco::NObserver<TcpClient, Poco::Net::WritableNotification>(*this, &TcpClient::onWritable));
        _reactor->addEventHandler(*_socket, Poco::NObserver<TcpClient, Poco::Net::ReadableNotification>(*this, &TcpClient::onReadable));
        _reactor->addEventHandler(*_socket, Poco::NObserver<TcpClient, Poco::Net::ShutdownNotification>(*this, &TcpClient::onShutdown));

        _reactorThread = new Poco::Thread("default_reactor");
        _reactorThread->start(*_reactor);

        _socket->connect(address);
    }
    catch (Poco::TimeoutException& e)
    {
        std::cout << e.displayText() << std::endl;
        return false;
    }
    catch (Poco::Exception& e)
    {
        std::cout << e.displayText() << std::endl;
        return false;
    }

    return true;
}


void TcpClient::close()
{
    resetNetwork();
}

void TcpClient::sendMessage(const BasicStreamPtr& stream)
{
    bool writeable = _socket->poll(0, Poco::Net::Socket::SelectMode::SELECT_WRITE);
    bool error = _socket->poll(0, Poco::Net::Socket::SelectMode::SELECT_ERROR);

    if (writeable && !error)
    {
        _socket->sendBytes((const void*)stream->b.begin(), stream->b.size());
    }
}

void TcpClient::sendMessage(int16 opcode, const byte* buff, size_t size)
{
    BasicStreamPtr streamPtr(new BasicStream());

    streamPtr->write((int32)0); //����Ԥ��
    streamPtr->write(opcode);   //������
    // ...
    // TODO: ��ѹ���ͼ��ܱ�־Ԥ��

    streamPtr->append((const byte*)buff, size);
    streamPtr->rewriteSize(streamPtr->b.size(), streamPtr->b.begin());

    sendMessage(streamPtr);
}

void TcpClient::sendMessage(uint16 opcode, NetworkMessage& message)
{
    BasicStreamPtr streamPtr(new BasicStream());
    streamPtr->write((int32)0);
    streamPtr->write(opcode);
    // ...
    // TODO: ��ѹ���ͼ��ܱ�־Ԥ��

    streamPtr->resize(NetworkParam::kHeaderLength + message.byteSize());
    message.encode((byte*)streamPtr->b.begin() + NetworkParam::kHeaderLength, message.byteSize());
    streamPtr->rewriteSize(streamPtr->b.size(), streamPtr->b.begin());

    sendMessage(streamPtr);
}

void TcpClient::onWritable(const Poco::AutoPtr<Poco::Net::WritableNotification>& notification)
{
}

void TcpClient::onReadable(const Poco::AutoPtr<Poco::Net::ReadableNotification>& notification)
{
    int bytes_transferred = _socket->receiveBytes(_buffer, MAX_RECV_LEN, 0);
    printf("received %d bytes.", bytes_transferred);
    if (bytes_transferred == 0)
    {
        _socket->close();
    }

    if (_blockPacketization.appendBlock(_buffer, bytes_transferred) == false)
    {
        _socket->close();
    }
}

void TcpClient::onShutdown(const Poco::AutoPtr<Poco::Net::ShutdownNotification>& notification)
{
    _handler.onShutdown();
}

void TcpClient::onTimeout(const Poco::AutoPtr<Poco::Net::TimeoutNotification>& notification)
{

}

void TcpClient::finishedPacketCallback(BasicStreamPtr& packet)
{
    //����������Ϣ����Ӧ�ò�
    uint16 opcode = 0;
    packet->read(opcode);

    NetworkPacket::Ptr packetPtr(new NetworkPacket);
    packetPtr->opcode = opcode;
    packetPtr->messageBody = NetworkPacket::PDU(packet->b.begin() + NetworkParam::kHeaderLength, packet->b.end());
    _handler.onMessage(opcode, packetPtr);
}

void TcpClient::resetNetwork()
{
    if (_reactor != nullptr)
    {
        _reactor->stop();
    }

    if (_reactorThread != nullptr && _reactorThread->isRunning())
    {
        _reactorThread->join();
    }

    if (_socket != nullptr)
    {
        _socket->close();
    }

    SAFE_DELETE(_socket);
    SAFE_DELETE(_reactor);
    SAFE_DELETE(_reactorThread);
}