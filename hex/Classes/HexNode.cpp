#include "HexNode.h"
#include "cocos2d.h"

USING_NS_CC;

DrawNode* HexNode::createNode(float x, float y, float r, int i, int j) {
    auto node = HexNode::create();
    node->x = x + 1.5 * r * (i + j);
    node->y = y + 0.866 * r * (i - j);
    node->r = r;
    node->idx = i;
    node->idy = j;
    Color4F borderColor = Color4F::RED;
    Color4F fillColor = Color4F::WHITE;
    x = node->x;
    y = node->y;
    Point vertices[6] = {Point(x, y),
                         Point(x + 0.5 * r, y + 1.732 * r / 2.),
                         Point(x + 1.5 * r, y + 1.732 * r / 2.),
                         Point(x + 2 * r, y),
                         Point(x + 1.5 * r, y - 1.732 * r / 2),
                         Point(x + 0.5 * r, y - 1.732 * r / 2)};
    node->drawPolygon(vertices, 6, fillColor, 1.f, borderColor);
    node->setAnchorPoint(Point(0, 0));
    return node;
};

bool HexNode::init() {
    if (!DrawNode::init()) {
        return false;
    }
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);

    touchListener->onTouchBegan = CC_CALLBACK_2(HexNode::onTouchBegan, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(HexNode::onTouchEnded, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(HexNode::onTouchMoved, this);
    touchListener->onTouchCancelled =
        CC_CALLBACK_2(HexNode::onTouchCancelled, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener,
                                                             this);
    return true;
}

bool HexNode::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event*) {
    cocos2d::log("ontouchbegan");
    auto touchpoint = touch->getLocationInView();
    auto area = this->getBoundingBox();
    auto inarea = area.containsPoint(touchpoint);
    if (inarea) {
        cocos2d::log("%d - %d", this->idx, this->idy);
    }
    return true;
};
void HexNode::onTouchEnded(cocos2d::Touch*, cocos2d::Event*) {
    cocos2d::log("ontouchend");
};
void HexNode::onTouchMoved(cocos2d::Touch*, cocos2d::Event*) {
    cocos2d::log("ontouchmoved");
};
void HexNode::onTouchCancelled(cocos2d::Touch*, cocos2d::Event*) {
    cocos2d::log("ontouchcancelled");
};
