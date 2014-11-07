//
//  AAKToolbar.h
//  AAKeyboardApp
//
//  Created by sonson on 2014/10/09.
//  Copyright (c) 2014年 sonson. All rights reserved.
//

#import <UIKit/UIKit.h>

@class AAKToolbar;
@class AAKASCIIArtGroup;

@protocol AAKToolbarDelegate <NSObject>

/**
 * AAKToolbarがタップされ，グループが切り替えられたときに呼ばれるデリゲートメソッド．
 * @param toolbar AAKToolbarオブジェクト．
 **/
- (void)didSelectGroupToolbar:(AAKToolbar*)toolbar;

/**
 * AAKToolbarの地球アイコンボタンが押された時によばれるデリゲートメソッド．
 * @param toolbar AAKToolbarオブジェクト．
 * @param button 本当の送信元のUIButtonオブジェクト．
 **/
- (void)toolbar:(AAKToolbar*)toolbar didPushEarthButton:(UIButton*)button;

/**
 * AAKToolbarの削除ボタンが押された時によばれるデリゲートメソッド．
 * @param toolbar AAKToolbarオブジェクト．
 * @param button 本当の送信元のUIButtonオブジェクト．
 **/
- (void)toolbar:(AAKToolbar*)toolbar didPushDeleteButton:(UIButton*)button;

@end

@interface AAKToolbar : UIView
@property (nonatomic, assign) id <AAKToolbarDelegate> delegate;
@property (nonatomic, assign) CGFloat height;
@property (nonatomic, assign) CGFloat fontSize;
@property (nonatomic, readonly) AAKASCIIArtGroup *currentGroup;

/**
 * 現在，選択中のグループのアスキーアートオブジェクトの配列を返す．
 * @return AAKASCIIArtオブジェクトを含むNSArray，
 **/
- (NSArray*)asciiArtsForCurrentGroup;

/**
 * ツールバー全体をレイアウトする．
 * グループ名の枠の大きさを計算し，すべてのセルの幅を計算する．そのあとに，セルのレイアウトを更新したりする．
 **/
- (void)layout;

@end
