//
//  CCListView.h
//  CodecademyMobile
//
//  Created by Ian Grossberg on 3/31/14.
//  Copyright (c) 2014 Codecademy. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface CCListView : UIView<UIScrollViewDelegate>

- (instancetype)initWithFrameVertically:(CGRect)frame scrolling:(BOOL)scrolling;
- (instancetype)initWithFrameHorizontally:(CGRect)frame scrolling:(BOOL)scrolling;

- (void)sharedInit:(BOOL)horizontal scrolling:(BOOL)scrolling; // for subclassing, do not call directly unless you impliment your own init path

@property (readwrite) CGFloat contentViewSpacing;
@property (readwrite) BOOL shouldConstrainTrailingEdge;

#if DEBUG
@property (readwrite) BOOL debugShowFieldBounds;
#endif

- (void)addContentView:(UIView *)contentView;
- (void)insertContentView:(UIView *)contentView atIndex:(NSUInteger)index;
@property (strong, readwrite) void (^addedOrInsertedContentViewHandler)(UIView *contentView, NSUInteger atIndex);

- (void)enumerateContentViews:(void (^)(UIView *view, NSUInteger index, BOOL *stop) )block;

@property (readonly) UIView *firstContentView;
@property (readonly) UIView *lastContentView;

- (UIView *)contentViewAtIndex:(NSUInteger)index;
- (UIView *)contentViewAtLocation:(CGPoint)location inView:(UIView *)relativeView;
- (NSUInteger)indexOfContentView:(UIView *)contentView;
- (NSUInteger)countofContentViews;

- (CGPoint)insertPointOfContentViewAtIndex:(NSUInteger)index;

@property (readonly) CGSize contentSize;

- (BOOL)isContentView:(UIView *)view;
- (BOOL)contentViewIsFirst:(UIView *)contentView;
- (BOOL)contentViewIsLast:(UIView *)contentView;

- (NSUInteger)contentViewIndexForLocation:(CGPoint)location inView:(UIView *)inView;

- (void)removeContentView:(UIView *)contentView;
- (void)removeContentViewAtIndex:(NSUInteger)index;
@property (strong, readwrite) void (^removedContentViewHandler)(UIView *contentView, NSUInteger atIndex);

- (void)removeAllContentViews;

@property (weak, readwrite) UIView *containerView;

+ (CCListView *)parentListView:(UIView *)forView;

@property (readwrite,getter=isPerpendicularScrollingEnabled) BOOL perpendicularScrollingEnabled;

@end
