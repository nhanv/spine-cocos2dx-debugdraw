#include "CCSpineDebugDrawNode.h"
#include <spine-cocos2dx/CCSkeleton.h>
#include <spine-cocos2dx/Skeleton.h>
#include <spine/Bone.h>
#include <spine/BoneData.h>
#include <spine/Slot.h>
#include <spine/Attachment.h>
#include <spine-cocos2dx/RegionAttachment.h>

using namespace cocos2d;
using namespace spine;

bool CCSpineDebugDrawNode::init()
{
  mSkeletons = CCArray::create();
  mSkeletons->retain();
  
  setIsDrawingBones(true);
  setIsDrawingSlotBoundingBoxes(true);
  
  return true;
}

void CCSpineDebugDrawNode::draw()
{
  CCObject* obj;
  
  CCARRAY_FOREACH(mSkeletons, obj)
  {
    CCSkeleton* skeletonNode = (CCSkeleton*) obj;
    const CCPoint skeletonPosition = skeletonNode->getPosition();
    
    // Slots
    if (getIsDrawingSlotBoundingBoxes())
    {
      const std::vector<Slot*>& slots = skeletonNode->skeleton->slots;
      ccV3F_C4B_T2F_Quad quad;
      
      // Green color for slot attachment bounding box
      ccDrawColor4B(0, 0, 255, 10);
      glLineWidth(1);
      
      for (int i = 0; i < slots.size(); i++)
      {
        if (slots[i]->attachment == NULL) continue;
        
        quad = ((RegionAttachment*) slots[i]->attachment)->quad;
        
        CCPoint points[4];
        points[0] = ccpAdd(ccp(quad.bl.vertices.x, quad.bl.vertices.y), skeletonPosition);
        points[1] = ccpAdd(ccp(quad.br.vertices.x, quad.bl.vertices.y), skeletonPosition);
        points[2] = ccpAdd(ccp(quad.tr.vertices.x, quad.tr.vertices.y), skeletonPosition);
        points[3] = ccpAdd(ccp(quad.tl.vertices.x, quad.tl.vertices.y), skeletonPosition);
        
        ccDrawPoly(points, 4, true);
      }
    }
    
    // Bones
    if (getIsDrawingBones())
    {
      const std::vector<Bone*>& bones = skeletonNode->skeleton->bones;
      Bone* bone = NULL;
      
      // Green color for bones
      glLineWidth(3);
      ccDrawColor4B(0, 255, 0, 255);
      
      // Bone line
      for (int i = 0; i < bones.size(); i++)
      {
        bone = bones[i];
        float x = bone->data->length * bone->m00 + bone->worldX;
        float y = bone->data->length * bone->m10 + bone->worldY;
        ccDrawLine(ccpAdd(ccp(bone->worldX, bone->worldY), skeletonPosition),
                   ccpAdd(ccp(x, y), skeletonPosition));
      }
      
      // Bone head
      ccPointSize(5);
      // Root bone head is assigned blue color
      ccDrawColor4B(0, 0, 255, 255);
      for (int i = 0; i < bones.size(); i++)
      {
        bone = bones[i];
        ccDrawPoint(ccpAdd(ccp(bone->worldX, bone->worldY), skeletonPosition));
        
        // Restore green color for other bone heads
        if (i == 0)
          ccDrawColor4B(0, 255, 0, 255);
      }
    }
  }
}

CCSpineDebugDrawNode::~CCSpineDebugDrawNode()
{
  mSkeletons->release();
}