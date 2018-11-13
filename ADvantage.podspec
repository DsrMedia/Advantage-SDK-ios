Pod::Spec.new do |s|
  s.name       = 'ADvantage'
  s.version    = '2.5.5.5-test'
  s.license = {
      :type => 'BSD',
      :file => 'LICENSE'
  }
  s.platform   = :ios
  s.summary    = 'ADvantage - the innovative, rich media mobile advertising platform.'
  s.homepage   = "http://advantage.docs.digitalsunray.com/"
  s.license    = "All rights reserved."
  s.author     = {
      'Digitalsunray Media GmbH' => 'advantage@digitalsunray.com'
  }
  s.source     = {
      :http => 'https://github.com/DsrMedia/Advantage-SDK-ios/raw/master/Advantage.zip'
  }
  s.source_files = 'AdvantageFramework.framework/Headers/*.h'
  s.ios.deployment_target = '9.0'
  s.ios.vendored_framework = 'AdvantageFramework.framework'
end
