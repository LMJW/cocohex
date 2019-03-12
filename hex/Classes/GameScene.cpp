#include "GameScene.h"
#include <iostream>
#include "HexNode.h"
#include "cocos2d.h"
#include "math.h"

USING_NS_CC;

Scene* GameScene::createScene() {
    Scene* scene = Scene::create();

    auto layer = GameScene::create();

    scene->addChild(layer);
    return scene;
};

bool GameScene::init() {
    if (!Layer::init()) {
        return false;
    }
    drawHexes(5);
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);

    touchListener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
    touchListener->onTouchCancelled =
        CC_CALLBACK_2(GameScene::onTouchCancelled, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener,
                                                             this);
    return true;
}

/// @param n integer to determine the edge of hex grid. The total numbers of
/// hexes in the grid equls to n*n;
void GameScene::drawHexes(int n) {
    /// hard code the 'center' of hex grid
    float init_x = this->getContentSize().width / 2;
    float init_y = this->getContentSize().height / 2;
    /// TODO: change the hard coded value
    float r = this->r;

    /// Current implementation will cause even number grid shift towards left
    /// TODO: deal with even n;
    for (int i = -n / 2; i < n * 1.0 / 2; ++i) {
        for (int j = -n / 2; j < n * 1.0 / 2; ++j) {
            auto _drawNode = HexNode::createNode(init_x, init_y, r, i, j);
            hexgrid.pushBack(_drawNode);
            this->addChild(_drawNode);
        }
    }
}

/// To find the hex index, we can do a vector transformation. Basically, we can
/// convert the vector a * e_x + b * e_y to different coordinates as
/// c * e_1 + d * e_2. Once we get the c & d, we can round the value to the hex
/// coordinate.
int GameScene::_hex_index(float x, float y) {
    /// transformed vector coordinate
    /// p, q represents the coordinate of hex coordinate
    auto p = 2 * x / 3;
    auto q = 1.732 / 3 * y - x / 3;

    /// pidx/qidx represents the hex index of p/q coordinate
    int pidx = 0;
    int qidx = 0;

    // aggregate the float number coordinate to hex index
    auto f = [&](float i) {
        i += r / 2;
        if (i < 0) {
            return i / r - 1;
        }
        return i / r;
    };

    pidx = f(p);
    qidx = f(q);

    /// Debug info
    std::cout << p << " | " << q << std::endl;
    std::cout << pidx << " | " << qidx << std::endl;
}

bool GameScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event*) {
    cocos2d::log("ontouchbegan");
    auto touchpoint = touch->getLocationInView();
    float init_x = this->getContentSize().width / 2;
    float init_y = this->getContentSize().height / 2;

    /// transform the touch coordinate
    _hex_index(touchpoint.x - init_x, touchpoint.y - init_y);
    return true;
};
void GameScene::onTouchEnded(cocos2d::Touch*, cocos2d::Event*) {
    cocos2d::log("ontouchend");
};
void GameScene::onTouchMoved(cocos2d::Touch*, cocos2d::Event*) {
    cocos2d::log("ontouchmoved");
};
void GameScene::onTouchCancelled(cocos2d::Touch*, cocos2d::Event*) {
    cocos2d::log("ontouchcancelled");
};