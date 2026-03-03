Pod::Spec.new do |s|
s.name             = "Capture360"
s.version          = "1.0.0"
s.summary          = "Capture360 framework is used to capture pano images"
s.description      = 'Capture360 framework is used to capture pano images'
s.homepage         = "https://github.com/ManojAtamai/Capture360"
s.license          = { :type => 'LGPL-3.0' }
s.author           = { "Atamai" => "manoj.v@atamai.in" }
s.source           = {:git => "https://github.com/ManojAtamai/Capture360.git", :tag=>s.version}

s.vendored_frameworks = [
    'INSCameraSDK.xcframework',
    'INSCameraServiceSDK.xcframework',
    'INSCoreMedia.xcframework',
    'SnapKit.xcframework',
    'SSZipArchive.xcframework'
  ]
s.platform     = :ios, '12.1'
s.requires_arc = true
end



