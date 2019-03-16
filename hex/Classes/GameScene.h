//
//  GameScene.h
//  hex
//
//  Created by Liming Jiang on 23/2/19.
//

#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include "cocos2d.h"

/// GameScene is the scene that hex game is running in. This scene will
/// initialize the hex grid, and touch event handler. To determine which hex is
/// touched, we can use the x, y coordinate to compute out the hex index.

class GameScene : public cocos2d::Layer {
    cocos2d::Vector<cocos2d::DrawNode*> hexgrid;

public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    /// Hex grid constant. r -> The edge length of hex.
    /// The value can be reset by setting scene
    float r = 30;
    int grid_n;
    float _x_shift;
    float _y_shift;

    bool player;

    /// drawHexes method draw the @param by @param grid
    void drawHexes(int);

    /// @param x, y indicate the x, y coordinate of the touch event. This
    /// function will return the index of the hex.
    int _hex_index(float x, float y);

    /// event handler
    virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchCancelled(cocos2d::Touch*, cocos2d::Event*);

    /// Cocos2d provided macro function to avoid memory leak
    CREATE_FUNC(GameScene);
};

#endif /* _GAMESCENE_H_ */
