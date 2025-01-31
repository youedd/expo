/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <UIKit/UIKit.h>

#import <ABI45_0_0React/ABI45_0_0RCTDefines.h>
#import <ABI45_0_0yoga/ABI45_0_0Yoga.h>

NS_ASSUME_NONNULL_BEGIN

@class ABI45_0_0RCTShadowView;

typedef NS_ENUM(NSInteger, ABI45_0_0RCTDisplayType) {
  ABI45_0_0RCTDisplayTypeNone,
  ABI45_0_0RCTDisplayTypeFlex,
  ABI45_0_0RCTDisplayTypeInline,
};

struct ABI45_0_0RCTLayoutMetrics {
  CGRect frame;
  CGRect contentFrame;
  UIEdgeInsets borderWidth;
  ABI45_0_0RCTDisplayType displayType;
  UIUserInterfaceLayoutDirection layoutDirection;
};
typedef struct CG_BOXABLE ABI45_0_0RCTLayoutMetrics ABI45_0_0RCTLayoutMetrics;

struct ABI45_0_0RCTLayoutContext {
  CGPoint absolutePosition;
  __unsafe_unretained NSHashTable<ABI45_0_0RCTShadowView *> *_Nonnull affectedShadowViews;
  __unsafe_unretained NSHashTable<NSString *> *_Nonnull other;
};
typedef struct CG_BOXABLE ABI45_0_0RCTLayoutContext ABI45_0_0RCTLayoutContext;

static inline BOOL ABI45_0_0RCTLayoutMetricsEqualToLayoutMetrics(ABI45_0_0RCTLayoutMetrics a, ABI45_0_0RCTLayoutMetrics b)
{
  return CGRectEqualToRect(a.frame, b.frame) && CGRectEqualToRect(a.contentFrame, b.contentFrame) &&
      UIEdgeInsetsEqualToEdgeInsets(a.borderWidth, b.borderWidth) && a.displayType == b.displayType &&
      a.layoutDirection == b.layoutDirection;
}

ABI45_0_0RCT_EXTERN ABI45_0_0RCTLayoutMetrics ABI45_0_0RCTLayoutMetricsFromYogaNode(ABI45_0_0YGNodeRef yogaNode);

/**
 * Converts float values between Yoga and CoreGraphics representations,
 * especially in terms of edge cases.
 */
ABI45_0_0RCT_EXTERN float ABI45_0_0RCTYogaFloatFromCoreGraphicsFloat(CGFloat value);
ABI45_0_0RCT_EXTERN CGFloat ABI45_0_0RCTCoreGraphicsFloatFromYogaFloat(float value);

/**
 * Converts compound `ABI45_0_0YGValue` to simple `CGFloat` value.
 */
ABI45_0_0RCT_EXTERN CGFloat ABI45_0_0RCTCoreGraphicsFloatFromYogaValue(ABI45_0_0YGValue value, CGFloat baseFloatValue);

/**
 * Converts `ABI45_0_0YGDirection` to `UIUserInterfaceLayoutDirection` and vise versa.
 */
ABI45_0_0RCT_EXTERN ABI45_0_0YGDirection ABI45_0_0RCTYogaLayoutDirectionFromUIKitLayoutDirection(UIUserInterfaceLayoutDirection direction);
ABI45_0_0RCT_EXTERN UIUserInterfaceLayoutDirection ABI45_0_0RCTUIKitLayoutDirectionFromYogaLayoutDirection(ABI45_0_0YGDirection direction);

/**
 * Converts `ABI45_0_0YGDisplay` to `ABI45_0_0RCTDisplayType` and vise versa.
 */
ABI45_0_0RCT_EXTERN ABI45_0_0YGDisplay ABI45_0_0RCTYogaDisplayTypeFromABI45_0_0ReactDisplayType(ABI45_0_0RCTDisplayType displayType);
ABI45_0_0RCT_EXTERN ABI45_0_0RCTDisplayType ABI45_0_0RCTABI45_0_0ReactDisplayTypeFromYogaDisplayType(ABI45_0_0YGDisplay displayType);

NS_ASSUME_NONNULL_END
