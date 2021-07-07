# Pellets 弹弹球	

​		弹弹球是一款（古老的）益智游戏。玩家需要控制弹球发射的角度，弹球发射后与方块或游戏板的上、左和右边界碰撞会反弹，弹球会从下边界离开游戏区域，弹球与方块发生碰撞时会减少方块的生命值。当所有弹球离开游戏区域后，所有的方块向下移动一个单位，并生成新的方块，开启下一关。游戏难度会随着关数增加而上升。

​		这是一个C++的复刻版，使用Qt框架，主要使用了`QGraphicsScene`和`QGraphicsItem`，没有使用游戏框架，自己实现了游戏画面的逐帧更新。相比于原始的弹弹球游戏，这里增加了额外的弹球和方块，以增加游戏性。



## TODO

- [x] 更多类型方块
  - [x] 爆炸方块
  - [x] 吸收方块
  - [x] 随机方块
- [x] 更多类型弹球
  - [x] 爆炸弹球
  - [x] 随机弹球
- [x] 碰撞动画
  - [x] 方块回收动画
  - [x] 弹球碰撞动画
- [ ] 音效系统
- [ ] 视觉效果改进
  - [ ] UI
  - [ ] 贴图
- [ ] 方块生成算法改进
- [ ] 分离画面刷新与弹球轨迹计算

*近期没有更新的计划，如果你对这个项目感兴趣，欢迎发PR*



## 平台兼容性 Compatibility

项目是基于Qt5+MSVC2019_64编写的，使用cmake构建工具。在项目编写过程中，没有Windows相关的库，可以经过少量修改移植到其他平台。



## 项目结构 Structure

大部分头文件在`include`中，唯一的例外是Qt相关的窗体，由于Qt Designer自动生成C++代码，`.ui`、`.h`和`.cpp`文件放在了同一个目录下。所有的具体实现都在`src`文件夹中，其中`main.cpp`定义了程序的入口。

![项目的结构](image\ProjectStructure.png)

项目的结构如图所示，主要实现分为5个模块：

- Board：游戏区域绘制、弹球位置的计算
- Pellet：弹球具体实现
- Grid：方块具体实现
- Windows：游戏窗体相关
- Backend：一些用到的算法，由于多处使用，单独抽取出来以提高代码复用

这个项目的设计遵循变量对象原则，Pellet和Grid都由接口、抽象类、普通类的层次结构；Board也有类似的设计。Pellet和Grid主要依据游戏的元素特性来划分类的层次结构，而Board的划分则是考虑了功能，Board主要维护了游戏区域与绘图无关的数据结构、和GameBoard主要负责使用Qt提供的API来绘图。

这个项目的设计核心的的逐帧更新，相关的结构如下：

![逐帧更新](image\UpdateByFrame.png)

QTimer会周期性地调用`doTick`，而`doTick`方法会对游戏区域内的元素位置进行更新。

![状态机](image\StateMachine.png)

每一关，游戏都要经过Wait、In progress、End三个状态，说明如下：

- Wait：等待玩家点击游戏区域，发射弹球
- In progress：弹球已经发射，游戏区域中还有弹球，这个状态分为三个子状态，他们是可以叠加的，三个子状态分别为：
  - Shoot：弹球发射中，绘制发射动画
  - Update：弹球在游戏区域中，检测碰撞
  - Recycle：弹球回收中，绘制回收动画
- End：所有弹球已经离开游戏界面，需要判断是否能进入下一关



## 许可证 License

[GNU General Public License version 3](https://github.com/ColorsWind/Pellets/blob/master/LICENSE)

这是一个学习性质的项目，二次开发请遵守GPLv3协议，并保留作者署名。

This project is for learning, please observe GPLv3 and keep the author's signature.



## 下载 Download

目前仅提供Windows x64版本的二进制文件，其他平台可以自行编译。

https://github.com/ColorsWind/Pellets/releases/





## 游戏截图  Screenshot 

![游戏过程中](D:\ClionProjects\Pellets\image\GameWindows.png)

![游戏结束](D:\ClionProjects\Pellets\image\GameWindowsEnd.png)