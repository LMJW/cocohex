#include "HexNode.h"
#include "cocos2d.h"

USING_NS_CC;

DrawNode* HexNode::createNode(float x, float y, float r, int i, int j) {
    /// create a DrawNode instance
    auto node = HexNode::create();
    /// Convert the cartesion coordinate to hex coordinate
    node->x = x + 1.5 * r * (i + j);
    node->y = y + 0.866 * r * (i - j);

    /// r represents the hex edge length
    node->r = r;

    /// The index of hex coordinate
    node->idx = i;
    node->idy = j;

    /// Hard coded color value
    Color4F borderColor = Color4F::RED;
    Color4F fillColor = Color4F::WHITE;

    x = node->x;
    y = node->y;

    /// 6 point to represent a hex shape
    Point vertices[6] = {
        Point(x - r, y),
        Point(x + 0.5 * r - r, y + 1.732 * r / 2.),
        Point(x + 1.5 * r - r, y + 1.732 * r / 2.),
        Point(x + 2 * r - r, y),
        Point(x + 1.5 * r - r, y - 1.732 * r / 2),
        Point(x + 0.5 * r - r, y - 1.732 * r / 2),
    };

    node->drawPolygon(vertices, 6, fillColor, 1.f, borderColor);
    node->setAnchorPoint(Point(0, 0));
    return node;
};

bool HexNode::init() {
    if (!DrawNode::init()) {
        return false;
    }
    return true;
}
