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
数据访问层
* para
    * Mat m
* func
    * Mat getMat()
    * void loadPicture(string)

### `View`
UI界面
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
    UI
    <?xml version="1.0" encoding="UTF-8"?>
<ui version="4.0">
 <class>ViewClass</class>
 <widget class="QMainWindow" name="ViewClass">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>1071</width>
    <height>790</height>
   </rect>
  </property>
  <property name="windowTitle">
   <string>App</string>
  </property>
  <widget class="QWidget" name="centralWidget">
   <widget class="QGroupBox" name="groupBox">
    <property name="geometry">
     <rect>
      <x>40</x>
      <y>20</y>
      <width>460</width>
      <height>701</height>
     </rect>
    </property>
    <property name="title">
     <string/>
    </property>
    <widget class="QGraphicsView" name="leftOriginView">
     <property name="geometry">
      <rect>
       <x>110</x>
       <y>50</y>
       <width>256</width>
       <height>192</height>
      </rect>
     </property>
    </widget>
    <widget class="QPushButton" name="recognizeButton">
     <property name="geometry">
      <rect>
       <x>190</x>
       <y>270</y>
       <width>93</width>
       <height>28</height>
      </rect>
     </property>
     <property name="styleSheet">
      <string notr="true">font: 12pt &quot;Agency FB&quot;;</string>
     </property>
     <property name="text">
      <string>开始识别</string>
     </property>
    </widget>
    <widget class="QTextBrowser" name="resultText">
     <property name="geometry">
      <rect>
       <x>110</x>
       <y>450</y>
       <width>261</width>
       <height>201</height>
      </rect>
     </property>
    </widget>
    <widget class="QLabel" name="label">
     <property name="geometry">
      <rect>
       <x>190</x>
       <y>390</y>
       <width>91</width>
       <height>31</height>
      </rect>
     </property>
     <property name="styleSheet">
      <string notr="true">font: 12pt &quot;Agency FB&quot;;</string>
     </property>
     <property name="frameShape">
      <enum>QFrame::Box</enum>
     </property>
     <property name="text">
      <string>识别结果</string>
     </property>
    </widget>
   </widget>
   <widget class="QGroupBox" name="groupBox_2">
    <property name="geometry">
     <rect>
      <x>570</x>
      <y>20</y>
      <width>460</width>
      <height>701</height>
     </rect>
    </property>
    <property name="title">
     <string/>
    </property>
    <widget class="QGraphicsView" name="removeBgView">
     <property name="geometry">
      <rect>
       <x>160</x>
       <y>370</y>
       <width>256</width>
       <height>81</height>
      </rect>
     </property>
    </widget>
    <widget class="QGraphicsView" name="denoiseView">
     <property name="geometry">
      <rect>
       <x>160</x>
       <y>480</y>
       <width>256</width>
       <height>81</height>
      </rect>
     </property>
    </widget>
    <widget class="QGraphicsView" name="grayView">
     <property name="geometry">
      <rect>
       <x>160</x>
       <y>260</y>
       <width>256</width>
       <height>81</height>
      </rect>
     </property>
    </widget>
    <widget class="QGraphicsView" name="binaryzationView">
     <property name="geometry">
      <rect>
       <x>160</x>
       <y>590</y>
       <width>256</width>
       <height>81</height>
      </rect>
     </property>
    </widget>
    <widget class="QGraphicsView" name="rightOriginView">
     <property name="geometry">
      <rect>
       <x>160</x>
       <y>41</y>
       <width>256</width>
       <height>171</height>
      </rect>
     </property>
    </widget>
    <widget class="QLabel" name="label_4">
     <property name="geometry">
      <rect>
       <x>35</x>
       <y>380</y>
       <width>101</width>
       <height>51</height>
      </rect>
     </property>
     <property name="styleSheet">
      <string notr="true">font: 14pt &quot;Agency FB&quot;;</string>
     </property>
     <property name="frameShape">
      <enum>QFrame::Box</enum>
     </property>
     <property name="text">
      <string>去背景</string>
     </property>
     <property name="alignment">
      <set>Qt::AlignCenter</set>
     </property>
    </widget>
    <widget class="QLabel" name="label_3">
     <property name="geometry">
      <rect>
       <x>35</x>
       <y>490</y>
       <width>101</width>
       <height>51</height>
      </rect>
     </property>
     <property name="styleSheet">
      <string notr="true">font: 14pt &quot;Agency FB&quot;;</string>
     </property>
     <property name="frameShape">
      <enum>QFrame::Box</enum>
     </property>
     <property name="text">
      <string>去噪点</string>
     </property>
     <property name="alignment">
      <set>Qt::AlignCenter</set>
     </property>
    </widget>
    <widget class="QLabel" name="label_2">
     <property name="geometry">
      <rect>
       <x>35</x>
       <y>600</y>
       <width>101</width>
       <height>51</height>
      </rect>
     </property>
     <property name="styleSheet">
      <string notr="true">font: 14pt &quot;Agency FB&quot;;</string>
     </property>
     <property name="frameShape">
      <enum>QFrame::Box</enum>
     </property>
     <property name="text">
      <string>二值化</string>
     </property>
     <property name="alignment">
      <set>Qt::AlignCenter</set>
     </property>
    </widget>
    <widget class="QLabel" name="label_5">
     <property name="geometry">
      <rect>
       <x>35</x>
       <y>280</y>
       <width>101</width>
       <height>50</height>
      </rect>
     </property>
     <property name="styleSheet">
      <string notr="true">font: 14pt &quot;Agency FB&quot;;</string>
     </property>
     <property name="frameShape">
      <enum>QFrame::Box</enum>
     </property>
     <property name="frameShadow">
      <enum>QFrame::Plain</enum>
     </property>
     <property name="lineWidth">
      <number>1</number>
     </property>
     <property name="text">
      <string>灰度</string>
     </property>
     <property name="textFormat">
      <enum>Qt::AutoText</enum>
     </property>
     <property name="alignment">
      <set>Qt::AlignCenter</set>
     </property>
     <property name="wordWrap">
      <bool>false</bool>
     </property>
    </widget>
    <widget class="QRadioButton" name="aveButton">
     <property name="geometry">
      <rect>
       <x>30</x>
       <y>120</y>
       <width>115</width>
       <height>19</height>
      </rect>
     </property>
     <property name="styleSheet">
      <string notr="true">font: 12pt &quot;Agency FB&quot;;</string>
     </property>
     <property name="text">
      <string>平均值法</string>
     </property>
    </widget>
    <widget class="QRadioButton" name="maxbutton">
     <property name="geometry">
      <rect>
       <x>30</x>
       <y>150</y>
       <width>115</width>
       <height>19</height>
      </rect>
     </property>
     <property name="styleSheet">
      <string notr="true">font: 12pt &quot;Agency FB&quot;;</string>
     </property>
     <property name="text">
      <string>最大值法</string>
     </property>
    </widget>
    <widget class="QRadioButton" name="weightAveButton">
     <property name="geometry">
      <rect>
       <x>30</x>
       <y>180</y>
       <width>115</width>
       <height>19</height>
      </rect>
     </property>
     <property name="styleSheet">
      <string notr="true">font: 12pt &quot;Agency FB&quot;;</string>
     </property>
     <property name="text">
      <string>加权平均</string>
     </property>
    </widget>
    <widget class="QLabel" name="label_6">
     <property name="geometry">
      <rect>
       <x>50</x>
       <y>50</y>
       <width>81</width>
       <height>21</height>
      </rect>
     </property>
     <property name="styleSheet">
      <string notr="true">font: 12pt &quot;Agency FB&quot;；</string>
     </property>
     <property name="text">
      <string>灰度方式</string>
     </property>
    </widget>
    <widget class="QPushButton" name="confirmButton">
     <property name="geometry">
      <rect>
       <x>40</x>
       <y>210</y>
       <width>93</width>
       <height>28</height>
      </rect>
     </property>
     <property name="text">
      <string>确定</string>
     </property>
    </widget>
   </widget>
  </widget>
  <widget class="QMenuBar" name="menuBar">
   <property name="geometry">
    <rect>
     <x>0</x>
     <y>0</y>
     <width>1071</width>
     <height>26</height>
    </rect>
   </property>
   <widget class="QMenu" name="menu">
    <property name="title">
     <string>文件</string>
    </property>
    <addaction name="importPicAction"/>
    <addaction name="separator"/>
    <addaction name="action_2"/>
   </widget>
   <widget class="QMenu" name="menu_2">
    <property name="title">
     <string>设置</string>
    </property>
   </widget>
   <widget class="QMenu" name="menu_3">
    <property name="title">
     <string>帮助</string>
    </property>
   </widget>
   <addaction name="menu"/>
   <addaction name="menu_2"/>
   <addaction name="menu_3"/>
  </widget>
  <widget class="QToolBar" name="mainToolBar">
   <attribute name="toolBarArea">
    <enum>TopToolBarArea</enum>
   </attribute>
   <attribute name="toolBarBreak">
    <bool>false</bool>
   </attribute>
  </widget>
  <widget class="QStatusBar" name="statusBar"/>
  <action name="importPicAction">
   <property name="text">
    <string>导入图片</string>
   </property>
  </action>
  <action name="action_2">
   <property name="text">
    <string>退出</string>
   </property>
  </action>
 </widget>
 <layoutdefault spacing="6" margin="11"/>
 <resources>
  <include location="Vcode.qrc"/>
 </resources>
 <connections/>
</ui>


### `View-Model`
View的抽象，负责View与 Model之间信息转换，同时将View的 Command传送到Model
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


