Pod::Spec.new do |s|
  s.name             = "Capture360"
  s.version          = "1.0.1"
  s.summary          = "Capture360 framework for 360 pano images"
  s.homepage         = "https://github.com/ManojAtamai/Capture360"
  s.license          = { :type => 'LGPL-3.0' }
  s.author           = { "Atamai" => "manoj.v@atamai.in" }
  
  # Corrected source to use HTTP for a ZIP file
  s.source           = { :http => "https://github.com/ManojAtamai/Capture360/releases/download/1.0.0/Insta360-1.0.1.zip" }

  s.platform         = :ios, '12.1'
  s.requires_arc     = true

  # Ensure these paths match the folder structure INSIDE your zip file
  s.vendored_frameworks = [
    'INSCameraSDK.xcframework',
    'INSCameraServiceSDK.xcframework',
    'INSCoreMedia.xcframework',
    'SnapKit.xcframework',
    'SSZipArchive.xcframework'
  ]

  # Essential for Swift apps using these vendored frameworks
  s.pod_target_xcconfig = {
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64',
    'DEFINES_MODULE' => 'YES',
    'GCC_PREPROCESSOR_DEFINITIONS' => '$(inherited) TO_B_SDK=1'
  }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }

end



