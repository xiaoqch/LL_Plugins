# GhostPortalCleaner
幽灵地狱门清理

## 简介
用于自动发现并清理幽灵地狱门，幽灵地狱门指由于删除区块或区块数据损坏而出现的有地狱门记录却没有实际地狱门方块的地狱门

## 功能
1. 当有实体穿过地狱门时，如果判断出幽灵地狱门，则启动幽灵地狱门检测与清理
2. /cleanportal 指令手动启动幽灵地狱门检测与清理

### 已支持检测范围
1. 已加载区到内存的区块中存在的地狱门
2. 从未被加载或已被删除的区块中存在的地狱门

### 暂未支持检测范围
* 已被加载过但当前未加载区块中的地狱门

## 安装及使用
1. 前往 [MineBBS](https://www.minebbs.com/resources/ghostportalcleaner.2986/) 下载插件
2. 将插件文件复制到 Minecraft Dedicated Server 目录下 plugins 文件夹中
3. 开服

## 支持的版本
* Minecraft Dedicated Server 1.17.40.06 with [LiteLoaderBDS](https://www.minebbs.com/resources/liteloader.2059/) 1.2.5 或以上
