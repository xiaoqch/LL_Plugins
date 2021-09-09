# OperationAgent
操作代理v1.1.2 - 配合假人客户端使用效果极佳

## 简介
此插件能让实体（主要是玩家）代替实体（主要用于假人）执行某些操作，目前支持的操作有：
* 投掷三叉戟（两种模式，最终效果都是实现改变三叉戟归属，仅限生物实体）
* 骑乘（注：顺带的附带了骑乘记录和上线自动骑乘，仅限生物实体）
* 睡觉（注：顺带的附带了睡觉记录和有玩家睡觉时自动睡觉，仅限玩家）
* 攻击（注：实际效果是改变近战攻击伤害源，仅限玩家）

## 安装
1. 前往 [MineBBS](https://www.minebbs.com/resources/operation-agent.2941/) 下载插件
2. 将插件文件复制到 Minecraft Dedicated Server 目录下 plugins 文件夹中
3. 可选的修改配置
4. 开服

## 使用
```
opagent help                      // 显示帮助信息
opagent version                   // 显示插件版本
opagent set 被代理实体 [操作实体] // 设置操作代理，如果没有设置操作实体，将默认执行命令的玩家为操作实体
opagent query [操作实体]          // 查询代理设置
opagent list                      // 列出当前代理设置，格式：操作实体 -> 被代理实体
opagent clear [操作实体]          // 清除某（些）实体的代理设置，如果没有设置操作实体，将默认执行命令的玩家为操作实体
opagent clearall                  // 清除所有实体的代理设置，效果同 opagent clear @e
```

## 用法示例
* 代理假人投掷三叉戟后给假人一把附魔抢夺III的武器，再代理假人乘坐矿车，挂机堆叠村庄印钞机，产量直接爆仓
* 主世界假人挂机点放置床，代理假人睡觉即可记录床坐标，此后每当有玩家睡觉时假人均会自动睡觉，挂机睡觉两不误
* （娱乐玩法）代理骷髅投掷三叉戟到刷怪塔的三叉戟杀手处，量产唱片，闪电苦力怕同理
* 由你发现

## 支持的版本
* Minecraft Dedicated Server 1.17.10.04 with [LiteLoaderBDS](https://www.minebbs.com/resources/liteloader.2059/) 1.1.1

## 配置文件(config.json)
```json
{
    "autoClean": true,          // 当执行代理操作失败时自动取消该代理
    "cancelAfterSleep": true,   // 执行代理睡觉成功后自动取消该代理
    "cancelAfterRide": true,    // 执行代理睡觉成功后自动取消该代理
    "autoSleep": true,          // 有玩家睡觉时自动睡觉
    "autoRideWhenJoin": true,   // 上线自动骑乘
    "useNewProjectMode": false, // 使用新的代理生成投掷物模式
    "forProjectile": true,      // 是否代理生成投掷物操作
    "forAttack": true,          // 是否代理攻击操作
    "forSleep": true,           // 是否代理睡觉操作
    "forMove": false,           // 是否代理移动操作，千万别开
    "forRide": true             // 是否代理骑乘操作
}
```

## 数据文件格式(data.json)
```json
{
    {
        "-253403070460": {                          // 记录的实体的uid
        "type": "Sleep",                            // 记录的操作类型
        "bedPos": [560, 72, -12],                   // 记录的床的坐标
        "remark": "player_name1->Bed(560,72,-12)"   // 记录的操作的注释，
    },
    "-51539607551": {
        "type": "Ride",
        "mounts": -1348619730941,                   // 此处为被骑乘实体的uid
        "remark": "player_name2->矿车"
    }
}
```

## 注意事项
* 代理投掷的两种模式：
** useNewProjectMode 为 false：生成投掷物位置和朝向均为操作实体的位置和朝向，仅改变投掷物的拥有者，此模式下某些含有特定功能的投掷物效果会无法被代理，如投掷末影珍珠不会传送被代理的实体
** useNewProjectMode 为 true：将操作转移成被代理实体的操作，位置为被代理实体的位置，方向为操作实体的方向，此模式下某些操作会忽略实体朝向，如掷末影珍珠的朝向为被代理实体的朝向，此模式会传送被代理的实体
* 指令支持目标选择器，但某些指令只支持选择一个实体，此时可以使用按数量筛选来限制选择实体数量，如：opagent set @e[type=cow,c=1]
