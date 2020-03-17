Pod::Spec.new do |s|
  s.name       = 'ADvantage'
  s.version    = '2.5.5.3'
  s.license = {
      :type => 'BSD',
      :file => 'LICENSE'
  }
  s.platform   = :ios
  s.requires_arc = true
  s.summary    = 'ADvantage - the innovative, rich media mobile advertising platform.'
  s.homepage   = "http://docs.advantage-adsolution.com/"
  s.license    = "All rights reserved."
  s.author     = {
      'Digitalsunray Media GmbH' => 'advantage@digitalsunray.com'
  }
  s.source     = {
      :http => 'https://github.com/DsrMedia/Advantage-SDK-ios/raw/master/Advantage.zip'
  }
  s.source_files = 'AdvantageFramework.framework/Headers/*.h'
  s.exclude_files = 'AdvantageFramework.framework/*.plist'
  s.ios.deployment_target = '10.0'
  s.ios.vendored_framework = 'AdvantageFramework.framework'
end
