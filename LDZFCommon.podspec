#
# Be sure to run `pod lib lint LDZFCommon.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'LDZFCommon'
  s.version          = '0.3.2'
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
#  s.dependency 'QMUIKit/QMUICore'
  s.dependency 'QMUIKit/QMUICore'
  s.dependency 'QMUIKit/QMUIComponents/QMUIBadge'
  s.dependency 'QMUIKit/QMUIComponents/QMUIButton'
  s.dependency 'QMUIKit/QMUIComponents/QMUINavigationButton'
  s.dependency 'QMUIKit/QMUIComponents/QMUIToolbarButton'
  s.dependency 'QMUIKit/QMUIComponents/QMUITableView'
  s.dependency 'QMUIKit/QMUIComponents/QMUITableViewProtocols'
  s.dependency 'QMUIKit/QMUIComponents/QMUITableViewHeaderFooterView'
  s.dependency 'QMUIKit/QMUIComponents/QMUICellSizeKeyCache'
  s.dependency 'QMUIKit/QMUIComponents/QMUICellHeightKeyCache'
  s.dependency 'QMUIKit/QMUIComponents/QMUICellHeightCache'
  s.dependency 'QMUIKit/QMUIComponents/QMUICollectionViewPagingLayout'
  s.dependency 'QMUIKit/QMUIComponents/QMUIGridView'
  s.dependency 'QMUIKit/QMUIComponents/QMUIStaticTableView'
  s.dependency 'QMUIKit/QMUIComponents/QMUIFloatLayoutView'
  s.dependency 'QMUIKit/QMUIComponents/QMUISegmentedControl'

  s.dependency 'QMUIKit/QMUIComponents/QMUIAnimation'
  s.dependency 'QMUIKit/QMUIComponents/QMUICALayerExtension'
  s.dependency 'QMUIKit/QMUIComponents/QMUICAAnimationExtension'
  
  s.dependency 'QMUIKit/QMUIComponents/QMUIMultipleDelegates'
  s.dependency 'QMUIKit/QMUIComponents/QMUIOrderedDictionary'
  s.dependency 'QMUIKit/QMUIComponents/QMUIScrollAnimator'
  s.dependency 'QMUIKit/QMUIComponents/QMUIWindowSizeMonitor'
  
end
