Debug drawing for Spine cocos2dx runtime
========================

![Alt text](demo.png)

### Introduction

`CCSpineDebugDrawNode` is a `cocos2d::CCNode` subclass which does debug drawing for `spine::CCSkeleton`

### Usage

	  // Create and add skeletons to layer
	  CSkeleton* skeletonNode1 = new CCSkeleton(skeletonData);
	  CSkeleton* skeletonNode2 = new CCSkeleton(skeletonData);
	  addChild(skeletonNode1);
	  addChild(skeletonNode2);
	  
	  // Create and add debug draw node to layer
	  CCSpineDebugDrawNode* debugDrawNode = CCSpineDebugDrawNode::create();
	  debugDrawNode->setPosition(CCPointZero);
	  addChild(debugDrawNode, 1000);
	  
	  // Register skeletons with debug draw nodes
	  debugDrawNode->getSkeletons()->addObject(skeletonNode1);
	  debugDrawNode->getSkeletons()->addObject(skeletonNode2);
	  
	  // Enable/disable drawing slot bounding boxes or bones
	  debugDrawNode->setIsDrawingBones(false);             // true by default
  	  debugDrawNode->setIsDrawingSlotBoundingBoxes(false); // true by default

