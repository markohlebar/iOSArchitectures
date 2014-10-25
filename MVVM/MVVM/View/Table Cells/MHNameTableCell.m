//
//  MHNameTableCell.m
//  MVVM
//
//  Created by Marko Hlebar on 25/10/2014.
//  Copyright (c) 2014 Marko Hlebar. All rights reserved.
//

#import "MHNameTableCell.h"
#import "MHNameViewModel.h"

@implementation MHNameTableCell

- (void)updateWithViewModel:(id <MHNameViewModel> )viewModel {
    self.textLabel.text = viewModel.name;
}

@end
