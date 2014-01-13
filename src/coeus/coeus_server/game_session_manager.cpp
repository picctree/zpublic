#include "venus_net/venus_net.h"
#include "game_session_manager.h"
#include "game_session.h"

bool GameSessionManager::init()
{
    return true;
}

void GameSessionManager::destroy()
{
    for (auto iter = _sessions.begin(); iter != _sessions.end(); ++iter)
    {
        // close the session
        iter->second->close();

        // remove the session
        _sessions.erase(iter);

        // give back the session object to the session pool
        _sessionPool.release(iter->second);
    }

    _sessions.clear();
}

GameSession* GameSessionManager::createSession()
{
    _sessionIdSequence++;
    GameSession* session = _sessionPool.acquire(_sessionIdSequence);
    if (session != nullptr && add(session))
    {
        return session;
    }
    return nullptr;
}

void GameSessionManager::destroySession(GameSession* session)
{
    RETURN_IF_NULLPTR(session, "destroy session failed, session == nullptr");

    //�ӹ������Ƴ���session
    remove(session->session_id());

    //��session��ԭ���ڴ��
    _sessionPool.release(session);
}

bool GameSessionManager::add(GameSession* session)
{
    if (_sessions.size() >= MAX_SESSIONS) 
    {
        warning_log("Session count already at the limit.");
        return nullptr;
    }

    if (getSession(session->session_id()) != nullptr)
    {
        return false;
    }

    _mutex.lock();
    _sessions.insert(std::make_pair(session->session_id(), session));
    _mutex.unlock();

    return true;
}

void GameSessionManager::remove(const uint64& id)
{
    auto iter = _sessions.find(id);
    if (iter != _sessions.end())
    {
        _mutex.lock();
        _sessions.erase(iter);
        _mutex.unlock();
    }
}

GameSession* GameSessionManager::getSession(const uint64& id)
{
    auto iter = _sessions.find(id);
    return iter != _sessions.end() ? iter->second : nullptr;
}

int32 GameSessionManager::sessionCount() const
{
    return _sessions.size();
}

void GameSessionManager::send_error(uint64 guid, uint32 error_code)
{
    auto iter_session = _sessions.find(guid);
    if (iter_session != _sessions.end())
    {
        GameSession* session = iter_session->second;
        if (session != nullptr)
        {
            session->send_error(error_code);
        }
    }
}

void GameSessionManager::send_error(uint64 guid, uint32 error_code, const std::string& error_reason)
{
    auto iter_session = _sessions.find(guid);
    if (iter_session != _sessions.end())
    {
        GameSession* session = iter_session->second;
        if (session != nullptr)
        {
            session->send_error_ex(error_code, error_reason);
        }
    }
}