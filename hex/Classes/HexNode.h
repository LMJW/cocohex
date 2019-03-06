#ifndef _HEX_SCENE_H_
#define _HEX_SCENE_H_

#include "cocos2d.h"

class HexNode : public cocos2d::DrawNode {
public:
    virtual bool init();
    static cocos2d::DrawNode* createNode(float x,
                                         float y,
                                         float r,
                                         int i,
                                         int j);
    float x;
    float y;
    float r;
    int idx;
    int idy;

    virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchCancelled(cocos2d::Touch*, cocos2d::Event*);
    CREATE_FUNC(HexNode);
};

#endif