//
//  KTAddHead.h
//  KTMeetSDK
//
//  Created by vito.zhu on 2020/4/27.
//

#ifndef KTAddHead_h
#define KTAddHead_h

#import "NSBundle+KTSKMeetSDK.h"
#import "NSString+KTSGetFirstLetter.h"
#import "NSObject+KTSModelToDict.h"
#import "NSArray+KTSGetResultInOrder.h"
#import "UIViewController+KTSAdd.h"
#import "KTS_UIHelper.h"
#import "Masonry.h"
#import "YYCategories.h"
#import "SVProgressHUD.h"
#import "NSString+KTS_Add.h"


#define KSWIDTH        UIScreen.mainScreen.bounds.size.width
#define KSHEIGHT       UIScreen.mainScreen.bounds.size.height
#define kWidth(x) ((x)*(KSWIDTH)/375.0)
#define kHeight(y) ((y)*(KSHEIGHT)/667.0)
#define IsIphoneX   (KSHEIGHT == 896 || KSHEIGHT == 812)
#define kNavBarHeight (IsIphoneX ? 88.f : 64.f)
#define KSafeBottomHeight  (IsIphoneX ? 34.f : 10.f)
#define BLUECOLOR [UIColor colorWithHexString:@"#039FD9"]

#endif /* KTAddHead_h */
