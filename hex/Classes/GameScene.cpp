#include "GameScene.h"
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
    auto _drawNode = DrawNode::create();
    Color4F borderColor = Color4F::RED;
    Color4F fillColor = Color4F::WHITE;

    float x = 100;
    float y = 100;
    float r = 30;

    Point vertices[6] = {Point(x, y),
                         Point(x + 0.5 * r, y + 1.732 * r / 2.),
                         Point(x + 1.5 * r, y + 1.732 * r / 2.),
                         Point(x + 2 * r, y),
                         Point(x + 1.5 * r, y - 1.732 * r / 2),
                         Point(x + 0.5 * r, y - 1.732 * r / 2)};

    _drawNode->drawPolygon(vertices, 6, fillColor, 1.f, borderColor);
    _drawNode->setAnchorPoint(Point(0, 0));
    this->addChild(_drawNode);
    return true;
}
