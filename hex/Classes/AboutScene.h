#ifndef _ABOUT_SCENE_H_
#define _ABOUT_SCENE_H_

#include "cocos2d.h"

class AboutScene : public cocos2d::Layer {
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(AboutScene);

    void menuItemBackCallback();
};

#endif /* __ABOUTSCENE_H */
