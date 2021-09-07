# AntiCutter
反切石机修物

## 简介
此插件能防止玩家通过某些非正规手段修改切石机来修改物品

## 安装
1. 前往 [MineBBS](https://www.minebbs.com/resources/anticutter.2938/) 下载插件
2. 将插件文件复制到 Minecraft Dedicated Server 目录下 plugins 文件夹中
3. 可选的修改配置
4. 开服

## 原理
合成监听并验证合成是否合法

## 支持的版本
* Minecraft Dedicated Server 1.17.10.04 with [LiteLoaderBDS](https://www.minebbs.com/resources/liteloader.2059/) 1.1.1 及以上

## 配置文件(config.json)
```json
{
    "autoKick":true,//检测到玩家后自动踢出被检测到的玩家
    "kickMessage":"Bad kids are not welcome on this server.",//踢出消息
    "autoCmd":true,//检测到玩家后自动执行控制台命令
    "cmds":["ban %player%"]//自动执行控制台命令内容
}
```

## 注意事项
* 请勿删除“cutter_recipes.json”文件，否则无法使用切石机进行任何合成