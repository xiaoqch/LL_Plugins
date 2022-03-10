# LimboEntitiesCleaner
跨纬度实体清理插件
> Limbo Entities: 跨纬度实体（边缘实体？），即已经进入传送门但对面区块未加载而仍未保存进区块数据的实体
***

## 简介
清理过多的跨纬度实体，如当双维度农场实体传送目标维度意外未加载时，进入传送门的实体会储存进跨纬度实体列表，如果该列表实体过多，目标区块加载时会产生多种问题

## 功能
* 当服务器启动时检查所有维度的跨纬度实体列表，当某区块跨纬度实体列表中实体超过一定数量时清除该区块所有跨纬度实体

## TODO
* ...

# 配置文件
```jsonc
{
    "CountThreshold": 500, // 清理阈值，当某区块跨纬度实体数量超过阈值时清理该区块跨纬度实体
}
```

## 安装及使用
1. 前往 [MineBBS](https://www.minebbs.com/resources/authors/xiaoqch.21476/) 下载插件文件
2. 将插件文件复制到 Minecraft Dedicated Server 目录下 plugins 文件夹中
3. 开服

## 支持的版本
* Minecraft Dedicated Server 1.18.10 和 [LiteLoaderBDS](https://www.minebbs.com/resources/liteloader.2059/) 2.1.3

## 注意事项
* 如发现已经有过多实体进入地狱门，不要尝试加载对面区块，安装此插件并重启服务器
