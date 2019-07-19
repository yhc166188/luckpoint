# luckpoint
幸运点游戏

项目介绍:休闲娱乐的小游戏，界面简单明了，适用于两人之间的对局，首先创建一局游戏，由两人各选一个角色，分别开牌，通过链上随机数，选出一名幸运者，简称幸运点小游戏。幸运者可以根据双方先前达成的共识，给予一定的奖励或特权等。

源码说明：
实现了一个用户界面及智能合约。www_luckpoint目录为web服务目录,contract为合约源码和编译后可部署的合约目录(合约已部署至ultrain 测试网先锋链luckpoint1账号上)

使用说明：
1、控制台进入到www_luckpoint目录，安装依赖包：npm install --save
2、启动web服务：
在所在的www_luckpoint目录下执行
npm run start

3、用浏览器打开：http://localhost:8080/
4、开始游戏。((因ultrain链是十秒共识，所以每次点击开牌时，需要延迟十秒左右))

命令行执行合约接口及查询表数据：
// 创建一个新游戏
clultrain push action luckpoint1 creategame '["banker"]' -p banker
// 玩家开牌命令（第一个参数为游戏id，需要与实际的游戏id对应）
clultrain push action luckpoint1 opencard '[1,1]' -p player1
clultrain push action luckpoint1 opencard '[1,2]' -p player2
// 查询表数据
clultrain get table luckpoint1 luckpoint1 game



