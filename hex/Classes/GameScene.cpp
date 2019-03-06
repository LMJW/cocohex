#include "GameScene.h"
#include <iostream>
#include "HexNode.h"
#include "cocos2d.h"

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
    drawHexes(4);

    return true;
}

/// @param n integer to determine the edge of hex grid. The total numbers of
/// hexes in the grid equls to n*n;
void GameScene::drawHexes(int n) {
    float init_x = this->getContentSize().width / 2;
    float init_y = this->getContentSize().height / 2;
    float r = 30;
    Color4F borderColor = Color4F::RED;
    Color4F fillColor = Color4F::WHITE;
    for (int i = -n / 2; i < n / 2; ++i) {
        for (int j = -n / 2; j < n / 2; ++j) {
            auto _drawNode = HexNode::createNode(init_x, init_y, r, i, j);
            this->addChild(_drawNode);
        }
    }
}
