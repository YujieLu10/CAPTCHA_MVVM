## `基于MVVM模式的复杂验证码识别`
### `使用说明`

### `功能`
实现验证码的识别

### `实现步骤`
* 图像采集：本项目通过本地选取的方式读入图片。
    
* 预处理：检测是否为正确的图像格式，转换到合适的格式，压缩，去除噪音，灰度
化，转换色彩空间。
    
* 检测：定位验证码文字所在的主要区域。
    
* 前处理：验证码文字的切割
    
* 训练：通过各种模式识别，机器学习算法，来挑选和训练合适数量的训练集。
    
* 识别：输入待识别的处理后的图片，转换成分类器需要的输入格式，然后通过输出的类
和置信度，来判断大概可能是哪个字母。识别本质上就是分类。
### `功能模式协作图`
![](https://github.com/cubeFUN/Sum/blob/master/img/Frame.jpg)
### `MVVM模式`
MVVM模式由视图(View)、视图模型 (ViewModel)、模型(Model)三部分组成，通 过这三部分实现UI逻辑、呈现逻辑和状态控 制、数据与业务逻辑的分离。 
### `Model`
*数据访问层
* para
    * Mat m
* func
    * Mat getMat()
    * void loadPicture(string)

### `View`
*UI界面
* para
    * filename :QString
    * originScene : QGraphicsScene*
    * loadPictureCommand : BaseCommand*
    * pImg : QImage*
* func
    * setLoadPictureCommand(BaseCommand*) : void
    * setImg(Qimage*) : void
    * update(string) : void
    * commandSucceed(bool) : void

### `View-Model`
*View的抽象，负责View与 Model之间信息转换，同时将View的 Command传送到Model
* para
    * pImg : QImage*
    * loadPictureCommand : BaseCommand*
    * model : Model*
* func
    * getLoadPictureCommand() : BaseCommand*
    * setModel(Model*) : void
    * loadPicture(string) : void
    * getpImg() : Qimage*
    * cvMatToQImage(Mat&) : void
    * update(string) : void
    * commandSucceed(bool) : void
### `功能效果图`

