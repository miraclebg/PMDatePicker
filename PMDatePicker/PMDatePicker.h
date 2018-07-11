//
//  PMDatePicker.h
//  PMDatePicker
//
//  Created by Pavel S. Mazurin on 1/13/13.
//  Copyright (c) 2013 Pavel Mazurin. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PMDatePickerTableView.h"

@interface PMDatePicker : UIControl <PMTableViewDataSource, PMTableViewDelegate>

// UIDatePicker properties & methods /copy-pasted ;)/
@property (nonatomic, assign) UIDatePickerMode datePickerMode;      // default is UIDatePickerModeDateAndTime

@property (nonatomic, strong) NSLocale      *locale;                // default is [NSLocale currentLocale]. setting nil returns to default
@property (nonatomic, strong) NSLocale      *dayLocale;
@property (nonatomic, strong) NSLocale      *monthLocale;
@property (nonatomic, strong) NSLocale      *yearLocale;
@property (nonatomic, copy)   NSCalendar    *calendar;              // default is [NSCalendar currentCalendar]. setting nil returns to default
@property (nonatomic, strong) NSTimeZone    *timeZone;              // default is nil. use current time zone or time zone from calendar

@property (nonatomic, strong) NSDate        *date;                  // default is current date when picker created. Ignored in countdown timer mode. for that mode, picker starts at 0:00

@property (nonatomic, strong) NSDate        *minimumDate;           // specify min/max date range. default is nil. When min > max, the values are ignored. Ignored in countdown timer mode
@property (nonatomic, strong) NSDate        *maximumDate;           // default is nil
@property (nonatomic, assign) NSTimeInterval countDownDuration;     // for UIDatePickerModeCountDownTimer, ignored otherwise. default is 0.0. limit is 23:59 (86,399 seconds)
@property (nonatomic, assign) NSInteger      minuteInterval;        // display minutes wheel with interval. interval must be evenly divided into 60. default is 1. min is 1, max is 30

- (void) setDate:(NSDate *)date animated:(BOOL)animated;            // if animated is YES, animate the wheels of time to display the new date

// ==============================
// PMDatePicker custom properties
@property (nonatomic, strong) UIFont *font;                         // default is [UIFont boldSystemFontOfSize:24]
@property (nonatomic, assign) CGFloat rowHeight;                    // default is 45.0f

@property (nonatomic, strong, readonly) UIImageView *frameImageView;
@property (nonatomic, strong, readonly) UIImageView *shadowImageView;
@property (nonatomic, strong, readonly) UIImageView *selectionImageView;

@property (nonatomic, assign) BOOL selectionImageFullWidth;

@property (nonatomic, strong) NSString *customDateFormat;

@property (nonatomic, strong) UIColor *shadowColor;

@property (nonatomic, strong) UIFont *textFont;

@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) UIColor *disabledTextColor;
@property (nonatomic, strong) UIColor *todayTextColor;

- (void)setColBackgroundImage:(UIImage *)colBackgroundImage;

- (void)refresh;

@end

