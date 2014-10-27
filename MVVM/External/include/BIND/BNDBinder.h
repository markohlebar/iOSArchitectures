//
//  BNDBinder.h
//  BIND
//
//  Created by Marko Hlebar on 27/10/2014.
//  Copyright (c) 2014 Marko Hlebar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BNDBinding.h"

@interface BNDBinder : NSObject

/**
 *  BIND is a special syntax to bind values at keyPath for an object
 *  to another object's value at keyPath.
 *  The syntax is MHFloatToStringTransformer|objectKeyPath->otherObjectKeyPath,object2KeyPath->otherObject2KeyPath
 *  where MHFloatToStringTransformer is the optional NSValueTransformer subclass you want to use,
 *  objectKeyPath is the keyPath of bound object, otherObjectKeyPath is the key path of other bound object.
 */
@property (nonatomic, strong) NSString *BIND;

/**
 *  Array of current bindings.
 */
@property (nonatomic, readonly) NSArray *bindings;

/**
 *  Binds an object's value at keyPath to anotherObjects value at keyPath.
 *  The system will assign otherObject's value as object's value on initialization.
 *
 *  @param object       object
 *  @param keyPath      a keyPath to object's property
 *  @param otherObject  other object
 *  @param otherKeyPath a keyPath to other object's property
 *
 *  @return a data binding object.
 */
- (BNDBinding *)bindObject:(id)object
                   keyPath:(NSString *)keyPath
                withObject:(id)otherObject
                   keyPath:(NSString *)otherKeyPath;

/**
 *  Binds an object's value at keyPath to anotherObjects value at keyPath.
 *  The system will assign otherObject's value as object's value on initialization.
 *
 *  @param object       object
 *  @param keyPath      a keyPath to object's property
 *  @param otherObject  other object
 *  @param otherKeyPath a keyPath to other object's property
 *  @param transformer  a custom transformer object
 *
 *  @return a data binding object.
 */
- (BNDBinding *)bindObject:(id)object
                   keyPath:(NSString *)keyPath
                withObject:(id)otherObject
                   keyPath:(NSString *)otherKeyPath
               transformer:(NSValueTransformer *)transformer;

/**
 *  Removes a binding.
 *
 *  @param binding a data binding object.
 */
- (void)removeBinding:(BNDBinding *)binding;

/**
 *  Removes all bindings.
 */
- (void)removeAllBindings;

/**
 *  Builds the bindings using BIND syntax.
 *  This removes all previous bindings on this data binder object,
 *  and builds bindings as defined with softBindings.
 *
 *  @param object      object
 *  @param otherObject other object
 */
- (void)buildBindingsForObject:(id)object
                   otherObject:(id)otherObject;

@end
