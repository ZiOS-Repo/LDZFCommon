#
# Be sure to run `pod lib lint LDZFCommon.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'LDZFCommon'
  s.version          = '0.1.1'
  s.summary          = 'A short description of LDZFCommon.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/ZiOS-Repo/LDZFCommon'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'zhuyuhui434@gmail.com' => 'zhuyuhui434@gmail.com' }
  s.source           = { :git => 'https://github.com/ZiOS-Repo/LDZFCommon.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '9.0'

  s.source_files = 'LDZFCommon/Classes/**/*'
  
  # s.resource_bundles = {
  #   'LDZFCommon' => ['LDZFCommon/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
  s.dependency 'QMUIKit/QMUICore'
  #控制图片在UIButton里的位置
  s.dependency 'QMUIKit/QMUIComponents/QMUIButton'
#  /**
#   *  相比系统的 UISlider，支持：
#   *  1. 修改背后导轨的高度
#   *  2. 修改圆点的大小
#   *  3. 修改圆点的阴影样式
#   */
  s.dependency 'QMUIKit/QMUIComponents/QMUISlider'
#  /**
#   * `QMUILabel`支持通过`contentEdgeInsets`属性来实现类似padding的效果。
#   *
#   * 同时通过将`canPerformCopyAction`置为`YES`来开启长按复制文本的功能，复制 item 的文案可通过 menuItemTitleForCopyAction 修改，长按时label的背景色默认为`highlightedBackgroundColor`
#   */
  s.dependency 'QMUIKit/QMUIComponents/QMUILabel'
#  /**
#   *  用于做九宫格布局，会将内部所有的 subview 根据指定的列数和行高，把每个 item（也即 subview） 拉伸到相同的大小。
#   *
#   *  支持在 item 和 item 之间显示分隔线，分隔线支持虚线。
#   *
#   *  @warning 注意分隔线是占位的，把 item 隔开，而不是盖在某个 item 上。
#   */
  s.dependency 'QMUIKit/QMUIComponents/QMUIGridView'
#  /**
#   *  简易的跑马灯 label 控件，在文字超过 label 可视区域时会自动开启跑马灯效果展示文字，文字滚动时是首尾连接的效果（参考播放音乐时系统锁屏界面顶部的音乐标题）。
#   *  @warning lineBreakMode 默认为 NSLineBreakByClipping（UILabel 默认值为 NSLineBreakByTruncatingTail）。
#   *  @warning textAlignment 暂不支持 NSTextAlignmentJustified 和 NSTextAlignmentNatural。
#   *  @warning 会忽略 numberOfLines 属性，强制以 1 来展示。
#   */
  s.dependency 'QMUIKit/QMUIComponents/QMUIMarqueeLabel'
#  /**
#   *  支持的特性包括：
#   *
#   *  1. 自定义 placeholderColor。
#   *  2. 自定义 UITextField 的文字 padding。
#   *  3. 支持限制输入的文字的长度。
#   *  4. 修复 iOS 10 之后 UITextField 输入中文超过文本框宽度后再删除，文字往下掉的 bug。
#   */
  s.dependency 'QMUIKit/QMUIComponents/QMUITextField'
#  /**
#   *  自定义 UITextView，提供的特性如下：
#   *
#   *  1. 支持 placeholder 并支持更改 placeholderColor；若使用了富文本文字，则 placeholder 的样式也会跟随文字的样式（除了 placeholder 颜色）
#   *  2. 支持在文字发生变化时计算内容高度并通知 delegate。
#   *  3. 支持限制输入框最大高度，一般配合第 2 点使用。
#   *  4. 支持限制输入的文本的最大长度，默认不限制。
#   *  5. 修正系统 UITextView 在输入时自然换行的时候，contentOffset 的滚动位置没有考虑 textContainerInset.bottom
#   */
  s.dependency 'QMUIKit/QMUIComponents/QMUITextView'
#  /*
#   * QMUISegmentedControl，继承自 UISegmentedControl
#   * 如果需要更大程度地修改样式，比如说字体大小，选中的 segment 的文字颜色等等，可以使用下面的第一个方法来做
#   * QMUISegmentedControl 也同样支持使用图片来做样式，需要五张图片。
#   */
  s.dependency 'QMUIKit/QMUIComponents/QMUISegmentedControl'
#  /**
#   *  做类似 CSS 里的 float:left 的布局，自行使用 addSubview: 将子 View 添加进来即可。
#   *
#   *  支持通过 `contentMode` 属性修改子 View 的对齐方式，目前仅支持 `UIViewContentModeLeft` 和 `UIViewContentModeRight`，默认为 `UIViewContentModeLeft`。
#   */
  s.dependency 'QMUIKit/QMUIComponents/QMUIFloatLayoutView'
#  /**
#   *  `QMUIAlertController`是模仿系统`UIAlertController`的控件，所以系统有的功能在QMUIAlertController里面基本都有。同时`QMUIAlertController`还提供了一些扩展功能，例如：它的每个 button 都是开放出来的，可以对默认的按钮进行二次处理（比如加一个图片）；可以通过 appearance 在 app 启动的时候修改整个`QMUIAlertController`的主题样式。
#   */
  s.dependency 'QMUIKit/QMUIComponents/QMUIAlertController'

  
end
