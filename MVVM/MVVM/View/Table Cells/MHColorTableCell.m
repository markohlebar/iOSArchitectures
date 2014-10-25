//
//  MHColorTableCell.m
//  MVVM
//
//  Created by Marko Hlebar on 25/10/2014.
//  Copyright (c) 2014 Marko Hlebar. All rights reserved.
//

#import "MHColorTableCell.h"
#import "MHColorViewModel.h"

@implementation MHColorTableCell

- (void)updateWithViewModel:(id <MHColorViewModel> )viewModel {
    self.contentView.backgroundColor = viewModel.color;
}

@end
