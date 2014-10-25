//
//  MHTableViewController.m
//  MVVM
//
//  Created by Marko Hlebar on 25/10/2014.
//  Copyright (c) 2014 Marko Hlebar. All rights reserved.
//

#import "MHTableViewController.h"
#import "MHDataController.h"
#import "MHColorTableCell.h"
#import "MHViewModel.h"
#import "MHNameTableCell.h"

@interface MHTableViewController ()
@property (nonatomic, copy) NSArray *viewModels;
@end

@implementation MHTableViewController {
    NSObject <MHTableViewDataController> *_dataController;
}
@synthesize dataController = _dataController;

- (void)viewDidLoad {
    [super viewDidLoad];
    
    __weak typeof(self) weakSelf = self;
    [_dataController reloadData:^(NSArray *viewModels, NSError *error) {
        weakSelf.viewModels = viewModels;
        [weakSelf.tableView reloadData];
    }];
    
    [self.tableView registerClass:[MHColorTableCell class]
           forCellReuseIdentifier:@"MHColorTableCell"];
    
    [self.tableView registerClass:[MHNameTableCell class]
           forCellReuseIdentifier:@"MHNameTableCell"];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.viewModels.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    id <MHViewModel> viewModel = self.viewModels[indexPath.row];
    UITableViewCell <MHView> *cell = [tableView dequeueReusableCellWithIdentifier:viewModel.identifier
                                                                     forIndexPath:indexPath];
    [cell updateWithViewModel:viewModel];
    return cell;
}

#pragma mark - Table view delegate

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    id <MHTableViewModel> viewModel = self.viewModels[indexPath.row];
    return viewModel.cellHeight;
}

@end
