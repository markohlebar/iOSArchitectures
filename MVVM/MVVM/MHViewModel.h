//
//  MHViewModel.h
//  MVVM
//
//  Created by Marko Hlebar on 25/10/2014.
//  Copyright (c) 2014 Marko Hlebar. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol MHModel;
@protocol MHViewModel <NSObject>
+ (instancetype)viewModelWithModel:(id <MHModel> )model;
@required
- (NSString *)identifier;
@end

@protocol MHTableViewModel <MHViewModel>
@required
- (CGFloat)cellHeight;
@end

@protocol MHCollectionViewModel <MHViewModel>
@required
- (CGSize)cellSize;
@end