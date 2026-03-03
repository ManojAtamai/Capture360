//
//  INSEditOptions.h
//  INSCameraServiceSDK
//
//  Created by insta360_ltp on 2024/7/30.
//

#ifndef INSEditOptions_h
#define INSEditOptions_h

typedef NS_ENUM(NSUInteger, INSEditDataSource) {
    INSEditDataSourceNone = 0,
    INSEditDataSourceAndroid = 1,
    INSEditDataSourceIos = 2,
    INSEditDataSourcePc = 3,
};

/** 防抖类型 */
typedef NS_ENUM(NSUInteger, INSEditStabType) {
    INSEditStabTypeStill = 0,
    INSEditStabTypeDirectionLock = 1,
};

/** 工程片段类型 */
typedef NS_ENUM(NSUInteger, INSEditProjectSegmentType) {
    INSEditProjectSegmentTypeEdit = 0,
    INSEditProjectSegmentTypeSnap = 1,
};

typedef NS_ENUM(NSUInteger, INSEditProjectionType) {
    INSEditProjectionTypeOMNI = 0,
    INSEditProjectionTypePANINI = 1,
};

/** 数据的类型包含关键帧数据、深度追踪和ViewFinder */
typedef NS_ENUM(NSUInteger, INSEditViewDataType) {
    INSEditViewDataTypeKeyFramePoint = 0,
    INSEditViewDataTypeDeepTrack = 1,
    INSEditViewDataTypeViewFinder = 2,
};

typedef NS_ENUM(NSUInteger, INSEditLutFilterInfoType) {
    INSEditLutFilterInfoTypeUnknown = 0,
    INSEditLutFilterInfoTypeK283Pano = 1,
    INSEditLutFilterInfoTypeK283WideAngle = 2,
    INSEditLutFilterInfoTypeK577FishEye = 3,
    INSEditLutFilterInfoTypeK577WideAngle = 4,
    INSEditLutFilterInfoTypeKGo2 = 5,
    INSEditLutFilterInfoTypeKDefault = 6,
};

typedef NS_ENUM(NSUInteger, INSEditLutStyleFilterInfoType) {
    
    /** 未知 */
    INSEditLutStyleFilterInfoTypeUnknown = 0,
    
    /** 冲浪 */
    INSEditLutStyleFilterInfoTypeSportSurfing = 1,
    
    /** 冬季-1 */
    INSEditLutStyleFilterInfoTypeSportS1 = 2,
    
    /** 冬季-2 */
    INSEditLutStyleFilterInfoTypeSportS2 = 3,
    
    /** 冬季-3 */
    INSEditLutStyleFilterInfoTypeSportS3 = 4,
    
    /** 户外 */
    INSEditLutStyleFilterInfoTypeSportOutdoor = 5,
    
    /** 骑行-1 */
    INSEditLutStyleFilterInfoTypeSportC1 = 100,
    
    /** 骑行-2 */
    INSEditLutStyleFilterInfoTypeSportC2 = 101,
    
    /** 骑行-3 */
    INSEditLutStyleFilterInfoTypeSportC3 = 102,
    
    /** 水下-1 */
    INSEditLutStyleFilterInfoTypeSportD1 = 200,
    
    /** 水下-2 */
    INSEditLutStyleFilterInfoTypeSportD2 = 201,
    
    /** 城市-晴1 */
    INSEditLutStyleFilterInfoTypeCityS1 = 300,
    
    /** 城市-晴2 */
    INSEditLutStyleFilterInfoTypeCityS2 = 301,
    
    /** 城市-晴3 */
    INSEditLutStyleFilterInfoTypeCityS3 = 302,
    
    /** 城市-晴4 */
    INSEditLutStyleFilterInfoTypeCityS4 = 303,
    
    /** 城市-阴1 */
    INSEditLutStyleFilterInfoTypeCityC1 = 400,
    
    /** 城市-阴2 */
    INSEditLutStyleFilterInfoTypeCityC2 = 401,
    
    /** 城市-阴3 */
    INSEditLutStyleFilterInfoTypeCityC3 = 402,
    
    /** 阴天 */
    INSEditLutStyleFilterInfoTypeNatureCloudy = 500,
    
    /** 黄昏 */
    INSEditLutStyleFilterInfoTypeNatureDusk = 501,
    
    /** 森林-1 */
    INSEditLutStyleFilterInfoTypeNatureF1 = 600,
    
    /** 森林-2 */
    INSEditLutStyleFilterInfoTypeNatureF2 = 601,
    
    /** 森林-3 */
    INSEditLutStyleFilterInfoTypeNatureF3 = 602,
    
    /** 森林-4 */
    INSEditLutStyleFilterInfoTypeNatureF4 = 603,
    
    /** 海边-1 */
    INSEditLutStyleFilterInfoTypeNatureC1 = 700,
    
    /** 海边-2 */
    INSEditLutStyleFilterInfoTypeNatureC2 = 701,
    
    /** 山野-1 */
    INSEditLutStyleFilterInfoTypeNatureM1 = 800,
    
    /** 山野-2 */
    INSEditLutStyleFilterInfoTypeNatureM2 = 801,
    
    /** 夜景-1 */
    INSEditLutStyleFilterInfoTypeNightN1 = 900,
    
    /** 夜景-2 */
    INSEditLutStyleFilterInfoTypeNightN2 = 901,
    
    /** 夜景-3 */
    INSEditLutStyleFilterInfoTypeNightN3 = 902,
    
    /** 夜景-4 */
    INSEditLutStyleFilterInfoTypeNightN4 = 903,
    
    /** 夜景-5 */
    INSEditLutStyleFilterInfoTypeNightN5 = 904,
    
    /** 夜景-6 */
    INSEditLutStyleFilterInfoTypeNightN6 = 905,
    
    /** 夜景-7 */
    INSEditLutStyleFilterInfoTypeNightN7 = 906,
    
    /** 胶片-1 */
    INSEditLutStyleFilterInfoTypeFilmF1 = 1000,
    
    /** 胶片-2 */
    INSEditLutStyleFilterInfoTypeFilmF2 = 1001,
    
    /** 胶片-3 */
    INSEditLutStyleFilterInfoTypeFilmF3 = 1002,
    
    /** 胶片-4 */
    INSEditLutStyleFilterInfoTypeFilmF4 = 1003,
    
    /** 胶片-5 */
    INSEditLutStyleFilterInfoTypeFilmF5 = 1004,
    
    /** 胶片-6 */
    INSEditLutStyleFilterInfoTypeFilmF6 = 1005,
    
    /** 胶片-7 */
    INSEditLutStyleFilterInfoTypeFilmF7 = 1006,
    
    /** 胶片-8 */
    INSEditLutStyleFilterInfoTypeFilmF8 = 1007,
    
    /** 人像-自然 */
    INSEditLutStyleFilterInfoTypePortraitPs1 = 1100,
    
    /** 人像-白皙 */
    INSEditLutStyleFilterInfoTypePortraitPs2 = 1101,
    
    /** 人像-明媚 */
    INSEditLutStyleFilterInfoTypePortraitPs3 = 1102,
    
    /** 人像-粉嫩 */
    INSEditLutStyleFilterInfoTypePortraitPs4 = 1103,
    
    /** 人像-1 */
    INSEditLutStyleFilterInfoTypePortraitP1 = 1200,
    
    /** 人像-2 */
    INSEditLutStyleFilterInfoTypePortraitP2 = 1201,
    
    /** 人像-3 */
    INSEditLutStyleFilterInfoTypePortraitP3 = 1202,
    
    /** 人像-4 */
    INSEditLutStyleFilterInfoTypePortraitP4 = 1203,
    
    /** 人像-5 */
    INSEditLutStyleFilterInfoTypePortraitP5 = 1204,
    
    /** 黑白-1 */
    INSEditLutStyleFilterInfoTypeMonoM1 = 1300,
    
    /** 黑白-2 */
    INSEditLutStyleFilterInfoTypeMonoM2 = 1301,
    
    /** 黑白-3 */
    INSEditLutStyleFilterInfoTypeMonoM3 = 1302,
    
    /** 黑白-4 */
    INSEditLutStyleFilterInfoTypeMonoM4 = 1303,
    
    /** 黑白-5 */
    INSEditLutStyleFilterInfoTypeMonoM5 = 1304,
    
    /** 黑白-6 */
    INSEditLutStyleFilterInfoTypeMonoM6 = 1305,
    
    /** 室内-明亮 */
    INSEditLutStyleFilterInfoTypeIndoorIndoorI1 = 1400,
    
    /** 室内-暖 */
    INSEditLutStyleFilterInfoTypeIndoorIndoorI2 = 1401,
    
    /** 室内-冷 */
    INSEditLutStyleFilterInfoTypeIndoorIndoorI3 = 1402,
    
    /** 室内 */
    INSEditLutStyleFilterInfoTypeIndoorIndoor = 1403,
    
    /** 冷色调-1 */
    INSEditLutStyleFilterInfoTypeColdCt1 = 1500,
    
    /** 冷色调-2 */
    INSEditLutStyleFilterInfoTypeColdCt2 = 1501,
    
    /** 暖色调-1 */
    INSEditLutStyleFilterInfoTypeWarmWt1 = 1600,
    
    /** 暖色调-2 */
    INSEditLutStyleFilterInfoTypeWarmWt2 = 1601,
    
    /** 暖色调-3 */
    INSEditLutStyleFilterInfoTypeWarmWt3 = 1602,
    
    /** 风格-日系 */
    INSEditLutStyleFilterInfoTypeStyleStl01 = 1700,
    
    /** 风格-复古 */
    INSEditLutStyleFilterInfoTypeStyleStl02 = 1701,
    
    /** 风格-青旅 */
    INSEditLutStyleFilterInfoTypeStyleStl03 = 1702,
    
    /** 风格-暗调 */
    INSEditLutStyleFilterInfoTypeStyleStl04 = 1703,
    
    /** 风格-日漫 */
    INSEditLutStyleFilterInfoTypeStyleStl05 = 1704,
    
    /** 美食-新鲜 */
    INSEditLutStyleFilterInfoTypeFoodFd01 = 1800,
    
    /** 美食-轻食 */
    INSEditLutStyleFilterInfoTypeFoodFd02 = 1801,
    
    /** 美食-暖食 */
    INSEditLutStyleFilterInfoTypeFoodFd03 = 1802,
    
    /** 美食-暗食 */
    INSEditLutStyleFilterInfoTypeFoodFd04 = 1803,
    
    /** 黑暗神话 */
    INSEditLutStyleFilterInfoTypeDarkMyth = 1900,
    
    /** 沙丘 */
    INSEditLutStyleFilterInfoTypeDune = 1901,
    
    /** 落日飞车 */
    INSEditLutStyleFilterInfoTypeSunsetDrive = 1902,
    
    /** 低保真 */
    INSEditLutStyleFilterInfoTypeLoFi = 1903,
    
    /** Y3K */
    INSEditLutStyleFilterInfoTypeY3K = 1904,
    
    /** 千禧梦核 */
    INSEditLutStyleFilterInfoTypeMillenniumDream = 1905,
    
    /** 旅行 I */
    INSEditLutStyleFilterInfoTypeTravelI = 2000,
    
    /** 旅行 II */
    INSEditLutStyleFilterInfoTypeTravelIi = 2001,
    
    /** GR正片 */
    INSEditLutStyleFilterInfoTypeGrpositiveFilm = 2100,
    
    /** G12 */
    INSEditLutStyleFilterInfoTypeG12 = 2101,
    
    /** NN */
    INSEditLutStyleFilterInfoTypeNn = 2102,
    
    /** Q2 */
    INSEditLutStyleFilterInfoTypeQ2 = 2103,
    
    /** 绿妍 */
    INSEditLutStyleFilterInfoTypeGreenLustre = 2200,
    
    /** 漫樱 */
    INSEditLutStyleFilterInfoTypeSakuraDream = 2201,
    
    /** 多巴胺 */
    INSEditLutStyleFilterInfoTypeDopamine = 2202,
    
    /** 宫崎漫夏 */
    INSEditLutStyleFilterInfoTypeMiyazakiSummer = 2203,
    
    /** 海盐 */
    INSEditLutStyleFilterInfoTypeSeaSalt = 2204,
    
    /** 阿勒泰 */
    INSEditLutStyleFilterInfoTypeAltay = 2205,
    
    /** 秋意浓 */
    INSEditLutStyleFilterInfoTypeDeepAutumn = 2206,
    
    /** 金秋 */
    INSEditLutStyleFilterInfoTypeGoldenAutumn = 2207,
    
    /** 海山 */
    INSEditLutStyleFilterInfoTypeSeaMountain = 2208,
    
    /** 冰原 */
    INSEditLutStyleFilterInfoTypeIceField = 2209,
    
    /** 冬寂 */
    INSEditLutStyleFilterInfoTypeWinterSilence = 2210,
    
    /** 冷晴 */
    INSEditLutStyleFilterInfoTypeColdClear = 2211,
    
    /** 港湾 */
    INSEditLutStyleFilterInfoTypeHarbor = 2212,
    
    /** 海浪 */
    INSEditLutStyleFilterInfoTypeOceanWave = 2213,
    
    /** 夜景增色 */
    INSEditLutStyleFilterInfoTypeEnhanceColor = 2300,
    
    /** 仲夏夜 */
    INSEditLutStyleFilterInfoTypeMidsummerNight = 2301,
    
    /** 黑金 */
    INSEditLutStyleFilterInfoTypeBlackGold = 2302,
    
    /** 冰蓝 */
    INSEditLutStyleFilterInfoTypeIceBlue = 2303,

    /** 圣诞暖光 */
    INSEditLutStyleFilterInfoTypeChristmas = 2304,

    /** 都市冷光 */
    INSEditLutStyleFilterInfoTypeCity = 2305,

    /** 火烧云 */
    INSEditLutStyleFilterInfoTypeFlameClouds = 2306,

    /** 橘子海 */
    INSEditLutStyleFilterInfoTypeOrangeSea = 2307,

    /** 蓝调时刻 */
    INSEditLutStyleFilterInfoTypeBluesHour = 2308,

    /** 粉霞 */
    INSEditLutStyleFilterInfoTypePinkCloud = 2309,

    /** 富士电影 */
    INSEditLutStyleFilterInfoTypeFuji = 2400,

    /** 好莱坞电影 */
    INSEditLutStyleFilterInfoTypeHollywood = 2401,

    /** 黑豹 */
    INSEditLutStyleFilterInfoTypeBlackPanther = 2402,

    /** 奥本海默 */
    INSEditLutStyleFilterInfoTypeOppenheimer = 2403,

    /** 繁花似锦 */
    INSEditLutStyleFilterInfoTypeTheOutsider = 2404,

    /** 哥谭 */
    INSEditLutStyleFilterInfoTypeGotham = 2405,

    /** 美白 */
    INSEditLutStyleFilterInfoTypeWhitening = 2500,

    /** 自然 */
    INSEditLutStyleFilterInfoTypeNatural = 2501,

    /** 清新 */
    INSEditLutStyleFilterInfoTypeFresh = 2502,

    /** 甜美 */
    INSEditLutStyleFilterInfoTypeSweet = 2503,

    /** 港风 */
    INSEditLutStyleFilterInfoTypeHongKongStyle = 2504,

    /** INS 暗调 */
    INSEditLutStyleFilterInfoTypeInsdarkTone = 2505,

    /** 美拉德 */
    INSEditLutStyleFilterInfoTypeMaylard = 2506,

    /** 韩系冷白 */
    INSEditLutStyleFilterInfoTypeKoreanColdWhite = 2507,

    /** 运动 */
    INSEditLutStyleFilterInfoTypeSport = 2508,

    /** 健身 */
    INSEditLutStyleFilterInfoTypeFitness = 2509,

    /** 夜拍曝光 */
    INSEditLutStyleFilterInfoTypeNightExposure = 2510,

    /** 夜景人像增强 */
    INSEditLutStyleFilterInfoTypePortraitEnhancement = 2511,

    /** 黑白记忆 */
    INSEditLutStyleFilterInfoTypeBlackWhiteMemory = 2600,

    /** 高清黑白 */
    INSEditLutStyleFilterInfoTypeHdblackWhite = 2601,

    /** 森山 */
    INSEditLutStyleFilterInfoTypeMoriyama = 2602,

    /** 墨红 */
    INSEditLutStyleFilterInfoTypeInkRed = 2603,

    /** 牛皮纸 */
    INSEditLutStyleFilterInfoTypeKraftPaper = 2604,

    /** 黑胶 */
    INSEditLutStyleFilterInfoTypeVinylRecord = 2605,

    /** 高清4k */
    INSEditLutStyleFilterInfoTypeHd4K = 2700,

    /** 超清8k */
    INSEditLutStyleFilterInfoTypeUltraHd8K = 2701,

    /** 自然清晰 */
    INSEditLutStyleFilterInfoTypeNaturalClarity = 2702,

    /** 鲜艳明亮 */
    INSEditLutStyleFilterInfoTypeVividBright = 2703,

    /** 去雾 */
    INSEditLutStyleFilterInfoTypeDehaze = 2704,

    /** 去黄增质 */
    INSEditLutStyleFilterInfoTypeAntiYellow = 2705,

    /** 去灰提亮 */
    INSEditLutStyleFilterInfoTypeBrighten = 2706,

    /** 胶片电影 */
    INSEditLutStyleFilterInfoTypeFilmMovie = 2800,

    /** 旧时来信 */
    INSEditLutStyleFilterInfoTypeOldLetter = 2801,

    /** 褪色照片 */
    INSEditLutStyleFilterInfoTypeFadedPhoto = 2802,

    /** 儿时回忆 */
    INSEditLutStyleFilterInfoTypeChildhoodMemory = 2803,

    /** 90s */
    INSEditLutStyleFilterInfoTypeNineties = 2804,

    /** 00s */
    INSEditLutStyleFilterInfoTypeZeroZero = 2805,

    /** 10s */
    INSEditLutStyleFilterInfoTypeTenZero = 2806,

    /** 美食增色 */
    INSEditLutStyleFilterInfoTypeFoodEnhance = 2900,

    /** 高清美食 */
    INSEditLutStyleFilterInfoTypeHdfood = 2901,

    /** 鲜美 */
    INSEditLutStyleFilterInfoTypeFreshness = 2902,

    /** 野餐 */
    INSEditLutStyleFilterInfoTypePicnic = 2903,

    /** 简餐 */
    INSEditLutStyleFilterInfoTypeLightMeal = 2904,

    /** 轻食 */
    INSEditLutStyleFilterInfoTypeHealthyFood = 2905,

    /** 西冷 */
    INSEditLutStyleFilterInfoTypeSirloin = 2906,

    /** 烘培 */
    INSEditLutStyleFilterInfoTypeBaking = 2907,
};

typedef NS_ENUM(NSUInteger, INSEditFilterInfoType) {
    /** 未知 */
    INSEditFilterInfoTypeUnknown = 0,
    INSEditFilterInfoTypeColorPlus3 = 1,
    INSEditFilterInfoTypeCartoon = 2,
    
    /** 风格滤镜 */
    INSEditFilterInfoTypeLutStyle = 3,
    
    /** 水下色彩还原 */
    INSEditFilterInfoTypeUnderwaterColourRestoration = 4,
    
    /** 对比 (-100,100), default: 0 android[-50F,15F] */
    INSEditFilterInfoTypeImageContrast = 5,
    
    /** 饱和 (-100,100), default: 0 android[-50F,50F] */
    INSEditFilterInfoTypeImageSaturation = 6,
    
    /** 高光 (0,100),    default: 0 android[0F,100F] */
    INSEditFilterInfoTypeImageHighlight = 7,
    
    /** 阴影 (-100,100), default: 0 android[0F,100F] */
    INSEditFilterInfoTypeImageShadow = 8,
    
    /** 色温 (-100,100), default: 0 android[-30F, 100F] */
    INSEditFilterInfoTypeImageColortemperature = 9,
    
    /** 色调 (-100,100), default: 0 android[-50F,50F] */
    INSEditFilterInfoTypeImageTone = 10,
    
    /** 锐化 (0,100),    default: 0 android[0F,10F] */
    INSEditFilterInfoTypeImageSharpness = 11,
    
    /** 曝光 (-100,100), default: 0 android[-30F, 20F] */
    INSEditFilterInfoTypeImageExposure = 12,
    
    /** 通透增强 */
    INSEditFilterInfoTypeLtm = 13,
    
    /** lut滤镜 */
    INSEditFilterInfoTypeLut = 14,
    
    /** ND镜特效 */
    INSEditFilterInfoTypeMotionBlur = 15,
    
    /** 镜像 */
    INSEditFilterInfoTypeTransform3D = 16,
    
    /** 移轴滤镜 */
    INSEditFilterInfoTypeTiltShiftBlur = 17,
    
    /** 美摄 */
    INSEditFilterInfoTypeMeisheBeauty = 18,
    
    /** 新滤镜调色 */
    INSEditFilterInfoTypeColorAdjust = 19,
    
    /** SDR to HDR10 杜比视界滤镜 */
    INSEditFilterInfoTypeSdrToHdr10 = 20,
    
    /** 高斯滤镜 */
    INSEditFilterInfoTypeBlurBackground = 21,
    
    /** 车牌模糊 */
    INSEditFilterInfoTypeNumberPlate = 22,
    
    /** 水下色彩还原3.0 */
    INSEditFilterInfoTypeUnderWaterColor3 = 26,
    
    /** 机外平面素材自由角度旋转 */
    INSEditFilterInfoTypeTransform2D = 24
};

typedef NS_ENUM(NSUInteger, INSEditItemIndex) {
    
  /** 体能训练 比如滑雪、骑行等 */
  INSEditItemIndexWorkout = 0,

  /** 距离 */
  INSEditItemIndexDistance = 10,

  /** 步数 */
  INSEditItemIndexSteps = 11,

  /** 能量消耗 */
  INSEditItemIndexEnergyConsumption = 20,

  /** 功率 */
  INSEditItemIndexPowerInWatts = 21,

  /** 路线 */
  INSEditItemIndexRoute = 30,

  /** 心率 */
  INSEditItemIndexHeartRate = 40,

  /** 配速 */
  INSEditItemIndexPace = 50,

  /** 速度 */
  INSEditItemIndexSpeed = 51,

  /** 加速度 */
  INSEditItemIndexAcceleration = 52,

  /** 档位开关 */
  INSEditItemIndexGear = 53,

  /** 油门开度 (和加速度不一样) */
  INSEditItemIndexAccelerator = 54,

  /** 刹车 */
  INSEditItemIndexBrake = 55,

  /** 海拔 */
  INSEditItemIndexElevation = 60,

  /** 坡度 */
  INSEditItemIndexSlope = 61,

  /** 方向 */
  INSEditItemIndexDirection = 62,

  /** 踏频 */
  INSEditItemIndexCadence = 70,

  /** 日期时间 */
  INSEditItemIndexDateTime = 80,

  /** 倾角 */
  INSEditItemIndexBendingAngle = 90,

  /** G值 */
  INSEditItemIndexGravity = 91,

  /** 车架型号 */
  INSEditItemIndexModelCode = 100,
};

typedef NS_ENUM(NSUInteger, INSEditDashBoardDataSource) {
    INSEditDashBoardDataSourceNaitve = 0,
    INSEditDashBoardDataSourceGarmin = 1,
    INSEditDashBoardDataSourceTbox = 2,
    INSEditDashBoardDataSourceAppleHealth = 3,
    INSEditDashBoardDataSourceIGPSport = 4,
    INSEditDashBoardDataSourceGaoChi = 5,
    INSEditDashBoardDataSourceInsGPS = 6,
    INSEditDashBoardDataSourceGpsTrack = 7,
    INSEditDashBoardDataSourceWahoo = 8,
    INSEditDashBoardDataSourceHuawei = 9,
    INSEditDashBoardDataSourceStrava = 10,
    INSEditDashBoardDataSourceMagene = 11,
    INSEditDashBoardDataSourceCfMoto = 12
};

typedef NS_ENUM(NSUInteger, INSEditVideoType) {
    INSEditVideoTypeNormalmp4 = 0,
    INSEditVideoTypeFragmentmp4 = 1,
};


typedef NS_ENUM(NSUInteger, INSEditChannelLayout) {
    /** 只为编译凑数，不要传 */
    INSEditChannelLayoutNone = 0,
    INSEditChannelLayoutMono = 1,
    INSEditChannelLayoutStereo = 2,
};

typedef NS_ENUM(NSUInteger, INSEditExMatColorType) {
    INSEditExMatColorTypeRgba = 0,
    INSEditExMatColorTypeYuvI420 = 1,
};

/** 一般与工具端AVCodecID相同 */
typedef NS_ENUM(NSUInteger, INSEditCodecId) {
    INSEditCodecIdNonecodec = 0,
    INSEditCodecIdH264 = 27,
    INSEditCodecIdH265 = 173,
    INSEditCodecIdProres = 147,
};

typedef NS_ENUM(NSUInteger, INSEditExporterTimeScaleType) {
    INSEditExporterTimeScaleTypeKDefaultValue = 0,
    INSEditExporterTimeScaleTypeKInterpolateFinalFrame = 1,
    INSEditExporterTimeScaleTypeKInterpolateFinalFrameAi = 2,
    INSEditExporterTimeScaleTypeKInterpolateSourceFrame = 3,
    INSEditExporterTimeScaleTypeKRepeatSingleSourceFrame = 4,
};

typedef NS_ENUM(NSUInteger, INSEditClipAudioMode) {
    INSEditClipAudioModeKNone = 0,
    INSEditClipAudioModeKDirectionFocus = 1,
    INSEditClipAudioModeKSpatialAudio360 = 3,
};

typedef NS_ENUM(NSUInteger, INSEditRenderModelType) {
    INSEditRenderModelTypeAuto = 0,
    INSEditRenderModelTypeSphereAuto = 1,
    INSEditRenderModelTypeSphereStitch = 2,
    INSEditRenderModelTypeSphereEquirectangular = 3,
    INSEditRenderModelTypeSphereFisheyeDewarp = 4,
    INSEditRenderModelTypeCubeTileProjection = 5,
    INSEditRenderModelTypeSphereCubemap = 6,
    INSEditRenderModelTypePlaneAuto = 10,
    INSEditRenderModelTypePlaneStitch = 11,
    INSEditRenderModelTypePlaneEquirectangular = 12,
    INSEditRenderModelTypePlaneFisheyeDewarp = 13,
    INSEditRenderModelTypePlaneStitchMercator = 14,
    INSEditRenderModelTypePlaneMercator = 15,
    INSEditRenderModelTypePlane = 20,
    INSEditRenderModelTypePlaneRemapUv = 21,
};

typedef NS_ENUM(NSUInteger, INSEditCutsceneType) {
    INSEditCutsceneTypeNone = 0,
    INSEditCutsceneTypeLottie = 1,
    INSEditCutsceneTypePano = 2,
    INSEditCutsceneTypeMeishe = 3,
    INSEditCutsceneTypeOthers = 4
};

typedef NS_ENUM(NSUInteger, INSEditCutsceneName) {
    // CutsceneType::LOTTIE
    INSEditCutsceneNameBlurSlideTop = 0,          // 模糊上滑
    INSEditCutsceneNameBlurSlideLeft = 1,         // 模糊左滑
    INSEditCutsceneNameBlurZoomIn = 2,            // 模糊缩小
    INSEditCutsceneNameBlurZoomOut = 3,           // 模糊放大
    INSEditCutsceneNameBlurRotation = 4,           // 模糊旋转
    INSEditCutsceneNameBlurMove = 5,               // 模糊移动
    INSEditCutsceneNameBlurLeftSlideWiggle = 6,  //
    INSEditCutsceneNameBlurTopSlideWiggle = 7,   //
    INSEditCutsceneNameBasicFadeInFadeOut = 8,  // 基础淡入淡出
    INSEditCutsceneNameMaskSliceFourBlocks = 9,  // 四格滑动

    // CutsceneType::PANO
    INSEditCutsceneNameNewVR360PanoSmallPlanet = 10,    // 小行星
    INSEditCutsceneNameNewVR360PanoResmallPlanet = 11,  // 反转小行星
    INSEditCutsceneNameNewVR360PanoTiltZoom = 12,       // 垂直旋转
    INSEditCutsceneNameNewVR360PanoZoomZoom = 13,       // 缩进
    INSEditCutsceneNameNewVR360PanoLowerLeft = 14,      // 向左下
    INSEditCutsceneNameNewVR360PanoAdvanceRoll = 15,    // 旋转

    // CutsceneType::OTHERS
    INSEditCutsceneNameSlotMachine = 16, // 老虎机
};

typedef NS_ENUM(NSUInteger, INSEditMeisheTimeWaterMarkCaptionInfoFormatType) {
    INSEditMeisheTimeWaterMarkCaptionInfoFormatTypeUnknown = 0,    // 未知
    INSEditMeisheTimeWaterMarkCaptionInfoFormatTypeYearMonthDay,   // 年月日
    INSEditMeisheTimeWaterMarkCaptionInfoFormatTypeMonthDayYear,   // 月日年
    INSEditMeisheTimeWaterMarkCaptionInfoFormatTypeDayMonthYear,   // 日月年
};

#endif /* INSEditOptions_h */
