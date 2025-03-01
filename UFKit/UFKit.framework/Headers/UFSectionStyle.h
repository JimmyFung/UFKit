//
//  UFSectionStyle.h
//  UFKit
//
//  Created by ChenZhangli QQ893419255 on 2019/6/26.
//  Copyright © 2019 UFKit. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class UFSectionStyleMaker;
@interface UFSectionStyle : NSObject

// 分组高度
@property (nonatomic, assign) CGFloat height;
// 文本内容
@property (nonatomic, copy) NSString *text;
// 行数
@property (nonatomic, assign) NSInteger numberOfLines;
// 字体
@property (nonatomic, strong) UIFont *font;
// 文本颜色
@property (nonatomic, strong) UIColor *color;

+ (UFSectionStyle *)makeSectionStyle:(NS_NOESCAPE void(^)(UFSectionStyleMaker *make))block;

@end


@interface UFSectionStyleMaker : NSObject

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithSectionStyle:(UFSectionStyle *)sectionStyle NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong, readonly) UFSectionStyle *sectionStyle;

@property (nonatomic, copy, readonly) UFSectionStyleMaker *(^height)(CGFloat height);
@property (nonatomic, copy, readonly) UFSectionStyleMaker *(^text)(NSString *text);
@property (nonatomic, copy, readonly) UFSectionStyleMaker *(^font)(UIFont *font);
@property (nonatomic, copy, readonly) UFSectionStyleMaker *(^color)(UIColor *color);
@property (nonatomic, copy, readonly) UFSectionStyleMaker *(^numberOfLines)(NSInteger numberOfLines);

@end

NS_ASSUME_NONNULL_END
