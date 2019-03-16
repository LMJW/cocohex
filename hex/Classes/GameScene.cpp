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
    // r is the edge length of the hex
    float r = this->r;
    this->grid_n = n;
    // change the coordinate to start from (0,0)
    float x_shift = (n % 2 == 0 ? (n + 0.5) * r : (n + 1) * r);

    float init_x = this->getContentSize().width / 2 - x_shift;
    float init_y = this->getContentSize().height / 2;

    this->_x_shift = init_x;
    this->_y_shift = init_y;
    /// TODO: change the hard coded value

    /// Current implementation will cause even number grid shift towards left
    /// TODO: deal with even n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
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
    /// TODO: this vector mapping is incorrect
    /// we need three coordinate to represent a hex position
    /// transformed vector coordinate
    /// p, q represents the coordinate of hex coordinate
    auto p = 2 * x / 3;              // point to 3 o'clock
    auto q = 1.732 / 3 * y - x / 3;  // point to 7 o'clock

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
    std::cout << "x:" << x << " | "
              << "y:" << y << std::endl;
    std::cout << "p:" << p << " | "
              << "q:" << q << std::endl;
    std::cout << "pid:" << pidx << " | "
              << "qid:" << qidx << std::endl;
    return pidx * this->r + qidx;
}

bool GameScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event*) {
    cocos2d::log("ontouchbegan");
    auto touchpoint = touch->getLocationInView();

    /// transform the touch coordinate
    auto idx = _hex_index(touchpoint.x - this->_x_shift,
                          touchpoint.y - this->_y_shift);
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