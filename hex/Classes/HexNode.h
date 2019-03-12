#ifndef _HEX_SCENE_H_
#define _HEX_SCENE_H_

#include "cocos2d.h"

/// HexNode extend the DrawNode class.
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

    /// This Macro function implemented smart pointer to avoid memory leak
    CREATE_FUNC(HexNode);
};

#endif