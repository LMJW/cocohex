//
//  GameScene.h
//  hex
//
//  Created by Liming Jiang on 23/2/19.
//

#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include "cocos2d.h"

class GameScene : public cocos2d::Layer {
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(GameScene);
};

#endif /* _GAMESCENE_H_ */
