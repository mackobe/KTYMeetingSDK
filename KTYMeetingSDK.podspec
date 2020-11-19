Pod::Spec.new do |s|
  s.name = "KTYMeetingSDK"
  s.version = "1.0.0"
  s.summary = "A short description of KTYMeetingSDK."
  s.license = {"type"=>"MIT", "file"=>"LICENSE"}
  s.authors = {"BIBiBI12"=>"qingxiang.zhu@ketianyun.com"}
  s.homepage = "https://github.com/BIBiBI12/KTMeetSdk"
  s.description = "TODO: Add long description of the pod here."
  s.libraries = "c++"
  s.xcconfig = {"VALID_ARCHS"=>"arm64"}
  s.source = { :git => "https://github.com/mackobe/KTYMeetingSDK.git", :tag => "#{s.version}" }

  s.ios.deployment_target    = '10.0'
  s.ios.vendored_framework   = 'ios/KTYMeetingSDK.embeddedframework/KTYMeetingSDK.framework'
end
