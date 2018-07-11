//
//  PMDatePickerTableViewCell.m
//  PMDatePicker
//
//  Created by Pavel S. Mazurin on 1/13/13.
//  Copyright (c) 2013 Pavel Mazurin. All rights reserved.
//

#import "PMDatePickerTableViewCell.h"
#import "Common.h"

@implementation PMDatePickerTableViewCell

#pragma mark - Initialization / Finalization

- (PMDatePickerTableViewCell *)initWithReuseIdentifier:(NSString *)reuseIdentifier
                                        labelAlignment:(NSTextAlignment)alignment {
    self = [super initWithStyle:UITableViewCellStyleDefault reuseIdentifier:reuseIdentifier];
    if (self) {
        [self setSelectionStyle:UITableViewCellSelectionStyleNone];
        self.backgroundColor = [UIColor clearColor];
        
        self.shadowColor = [UIColor colorWithHex:0xfafafa];
        self.disabledTextColor = [UIColor redColor];
        self.todayTextColor = [UIColor blueColor];
        self.textColor = [UIColor darkGrayColor];
        
        _label = [[UILabel alloc] initWithFrame:CGRectInset(self.contentView.bounds, (alignment==NSTextAlignmentCenter)?0.0f:10.0f, 0)];
        _label.textAlignment = alignment;
        _label.clipsToBounds = NO;
        _label.textColor = [UIColor blackColor];
        _label.backgroundColor = [UIColor clearColor];
        _label.shadowColor = self.shadowColor;
        _label.shadowOffset = CGSizeMake(0, 1);
        _label.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
        
        [self.contentView addSubview:_label];
    }
    
    return self;
}

#pragma mark - Getters / Setters

- (void)setTextFont:(UIFont *)textFont {
    if (textFont != _textFont) {
        _textFont = textFont;
        
        _label.font = _textFont;
    }
}

- (void)setShadowColor:(UIColor *)shadowColor {
    if (shadowColor != _shadowColor) {
        _shadowColor = shadowColor;
        
        _label.shadowColor = self.shadowColor;
    }
}

- (void)setTextColor:(UIColor *)textColor {
    if (textColor != _textColor) {
        _textColor = textColor;
        
        [self updateTextColor];
    }
}

- (void)setTodayTextColor:(UIColor *)todayTextColor {
    if (todayTextColor != _todayTextColor) {
        _todayTextColor = todayTextColor;
        
        [self updateTextColor];
    }
}

- (void)setDisabledTextColor:(UIColor *)disabledTextColor {
    if (disabledTextColor != _disabledTextColor) {
        _disabledTextColor = disabledTextColor;
        
        [self updateTextColor];
    }
}

- (void)setType:(PMStringTableViewCellType)type {
    if (_type != type) {
        _type = type;
        
        [self updateTextColor];
    }
}

#pragma mark - Actions

- (void)updateTextColor {
    switch (_type) {
        case PMStringTableViewCellTypeDisabled:
            _label.textColor = self.disabledTextColor;
            break;
        case PMStringTableViewCellTypeToday:
            _label.textColor = self.todayTextColor;
            break;
        default:
            _label.textColor = self.textColor;
            break;
    }
}

@end

