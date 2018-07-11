//
//  PMDatePickerTableViewCell.h
//  PMDatePicker
//
//  Created by Pavel S. Mazurin on 1/13/13.
//  Copyright (c) 2013 Pavel Mazurin. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    PMStringTableViewCellTypeDefault,
    PMStringTableViewCellTypeDisabled,
    PMStringTableViewCellTypeToday
} PMStringTableViewCellType;

@interface PMDatePickerTableViewCell : UITableViewCell

- (PMDatePickerTableViewCell *)initWithReuseIdentifier:(NSString *)reuseIdentifier
                                        labelAlignment:(NSTextAlignment)alignment;

@property (nonatomic, strong) UIColor *shadowColor;

@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) UIFont *textFont;

@property (nonatomic, strong) UIColor *disabledTextColor;
@property (nonatomic, strong) UIColor *todayTextColor;

@property (nonatomic, strong) UILabel *label;
@property (nonatomic, assign) PMStringTableViewCellType type;

@end

