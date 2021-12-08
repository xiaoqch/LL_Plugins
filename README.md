# LL_Plugins
适用于 Minecraft LiteLoader 加载器的插件

***

[![License](https://img.shields.io/badge/license-GPL3-blue)](LICENSE)

## 简介
适用于 Minecraft LiteLoader 加载器的插件

## 插件目录
* [AntiMinecartCopy](AntiMinecartCopy#readme)
* [AntiCutter](AntiCutter#readme)
* [GhostPortalCleaner](CleanGhostPortal#readme)
* [AllVoidWorld](AllVoidWorld)
* [OperationAgent](OperationAgent#readme)

## 安装及使用
1. 前往 [MineBBS](https://www.minebbs.com/resources/authors/xiaoqch.21476/) 或 [Release文件夹](Release) 寻找并下载需要的插件
1. 将插件文件复制到 Minecraft Dedicated Server 目录下 plugins 文件夹中
2. 配置好可能存在的配置文件
3. 开服

## 编译及调试
1. 使用 [Visual Studio](https://visualstudio.microsoft.com/) 打开 LL_Plugins.sln 解决方案
2. 更改项目配置为 Realese x64
3. 生成项目

### 调试注意事项
若想启用本地调试功能，请执行以下操作
1. 修改 配置属性 > 调试 > 工作目录 为bds根目录
2. 启动 本地 windows 调试器


## 支持的版本
* Minecraft Dedicated Server 1.17.10.04 with [LiteLoaderBDS](https://www.minebbs.com/resources/liteloader.2059/) 1.1.1


## 许可协议
在使用我们的产品的时候，我们默认您已经承认并遵守了[Mojang Studios EULA](https://account.mojang.com/documents/minecraft_eula)协议。  
这意味着你不能对本项目进行任何违反EULA的商业性使用。违反EULA协议造成的一切后果由违反者自行承担。  

* [LL_Plugins](https://github.com/xiaoqch/LL_Plugins) MIT
* [LiteLoader](https://github.com/LiteLDev/LiteLoader) GPLv3 with extra restrictions&exceptions

### Extra Restrictions & Exceptions
If you provides a server hosting service,you can use this framework for free, but you SHOULD NOT make PRIVATE changes to this framework as a selling point. If you fixed or tweaked the code, please pull request, instead of making it private for commercial use. 

## 鸣谢
- LiteLDev 开发组 [LiteLoader](https://github.com/LiteLDev/LiteLoaderBDS) 项目提供的加载服务与基础API  
- [LiteXLoader](https://github.com/LiteLDev/LiteXLoader)项目提供的底层接口实现
