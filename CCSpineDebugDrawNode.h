
#ifndef SPINE_DEBUG_DRAW_H_
#define SPINE_DEBUG_DRAW_H_

#include "cocos2d.h"

class CCSpineDebugDrawNode: public cocos2d::CCNode {
  CC_SYNTHESIZE(cocos2d::CCArray*, mSkeletons, Skeletons)
  CC_SYNTHESIZE(bool, mIsDrawingBones, IsDrawingBones);
  CC_SYNTHESIZE(bool, mIsDrawingSlotBoundingBoxes, IsDrawingSlotBoundingBoxes);
public:
  CREATE_FUNC(CCSpineDebugDrawNode);
  virtual bool init();
  virtual ~CCSpineDebugDrawNode(void);

	virtual void draw ();
};

#endif
