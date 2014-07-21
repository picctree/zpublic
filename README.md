zpublic
=======
  
  
项目简介：
----------
zpublic是一个主要用于代码尝试和代码收集的c++开源项目。  
代码尝试，意味着zpublic会使用到c++11、boost、poco等较激进的c++技术和开源代码，并且使用了大量的开源第三方库。zpublic里有各种编程方向的尝试，譬如界面开发、调试器、游戏等，同时，也意味着这部分代码的质量是无法完全保证的。  
代码收集，意味着zpublic里有参与的几个人在工作、平时写的很多可重用代码，这些代码的质量是可以保证的，部分已用到千万用户级产品中。  

目录结构：
----------
3rdparty：第三方库代码和lib  
doc：文档  
output：zeus游戏的c++客户端circe的输出目录  
pellets：一些相对独立的代码模块  
public：基础代码  
res：一些工程使用到的资源，在别的代码库  
sln：所有工程的解决方案文件都在这  
src：代码  
zlui：界面尝试相关的代码  

使用IDE：VS2012（VS2013也行？）

开发模式：
----------
1，非成员  
	fork主干 -> 在自己的分支上修改 -> 提交pull request  
2，新人开发  
	push到自己的branch，提交pull request，待核心开发审核后合并到master  
3，核心开发  
	一般直接提交到master  
请自行学习git！

提交要求
----------
1，文件名全小写，下划线分割单词(界面相关文件可以用驼峰法)  
2，代码整洁规范，文件内保持风格统一  
3，尽可能少的依赖，KISS  

zpublic\winutils文档：http://www.laorouji.com/zpublic/  
zpublic（c++11、boost、poco、gui等讨论）交流讨论QQ群：240978546  
coeus（火热进行中的游戏）交流讨论群：37723482  
coeus的丰富文档：http://wiki.powman.org/pages/viewpage.action?pageId=4849675  
交流论坛 [http://gamediary.org/]  
