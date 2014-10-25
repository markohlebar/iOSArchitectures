//
//  MHDataController.h
//  MVVM
//
//  Created by Marko Hlebar on 25/10/2014.
//  Copyright (c) 2014 Marko Hlebar. All rights reserved.
//

#ifndef MVVM_MHDataController_h
#define MVVM_MHDataController_h

#import <UIKit/UIKit.h>

@class NSError;
typedef void(^MHViewModelBlock)(NSArray *viewModels, NSError *error);

@protocol MHDataController <NSObject>
@required
- (void)reloadData:(MHViewModelBlock)viewModelBlock;
@end

@protocol MHTableViewDataController <MHDataController>

@end

@protocol MHCollectionViewDataController <MHDataController>

@end

#endif
