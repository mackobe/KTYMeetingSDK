//
//  DogLanguageTranslation
//  DogLanguageTranslation
//
//  DogLanguageTranslation
//  DogLanguageTranslation
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//是否为中文
#define MN_LanguageIsChinese       [KTSK_Localization mn_iaCurrentLanguageChinese]

//国际化 简易版
#define KTText(en,zh)  ( MN_LanguageIsChinese ? zh : en )

@interface KTSK_Localization : NSObject

+ (NSString *)mn_localizationWithEnglish:(NSString *)mn_english mn_chinese:(NSString *)mn_chinese;

+(BOOL)mn_iaCurrentLanguageChinese;

@end

NS_ASSUME_NONNULL_END
