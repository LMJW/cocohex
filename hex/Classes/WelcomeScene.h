#ifndef _WELCOME_SCENE_H_
#define _WELCOME_SCENE_H_

#include "cocos2d.h"

class WelcomeScene : public cocos2d::Layer {
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(WelcomeScene);

    /// Define callbacks for different menuitems
    void menuItemExitCallback();
    void menuItemSettingCallback();
    void menuItemPlayCallback();
    void menuItemAboutCallback();
};

#endif  //_WELCOME_SCENE_H_
