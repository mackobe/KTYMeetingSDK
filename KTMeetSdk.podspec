Pod::Spec.new do |s|
  s.name = "KTMeetSdk"
  s.version = "0.4.0"
  s.summary = "A short description of KTMeetSdk."
  s.license = {"type"=>"MIT", "file"=>"LICENSE"}
  s.authors = {"BIBiBI12"=>"qingxiang.zhu@ketianyun.com"}
  s.homepage = "https://github.com/BIBiBI12/KTMeetSdk"
  s.description = "TODO: Add long description of the pod here."
  s.libraries = "c++"
  s.xcconfig = {"VALID_ARCHS"=>"arm64 armv7 armv7s"}
  s.source = { :git => "git@github.com:mackobe/KTYMeetingSDK.git", :tag => "#{s.version}" }

  s.ios.deployment_target    = '10.0'
  s.ios.vendored_framework   = 'ios/KTMeetSdk.embeddedframework/KTMeetSdk.framework'
end
