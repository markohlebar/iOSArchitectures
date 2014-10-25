//
//  MHCell.h
//  MVVM
//
//  Created by Marko Hlebar on 25/10/2014.
//  Copyright (c) 2014 Marko Hlebar. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol MHViewModel;
@protocol MHView <NSObject>
@required
- (void)updateWithViewModel:(id <MHViewModel> )viewModel;
@end
