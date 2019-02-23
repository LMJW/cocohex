#include "AboutScene.h"
#include "WelcomeScene.h"
#include "cocos2d.h"

USING_NS_CC;

Scene* AboutScene::createScene() {
    auto scene = Scene::create();
    auto layer = AboutScene::create();

    scene->addChild(layer);
    return scene;
}

bool AboutScene::init() {
    if (!Layer::init()) {
        return false;
    }
    auto auth_label = Label::createWithSystemFont("Author: LMJW", "", 25);
    auth_label->setAnchorPoint(Vec2(0.5, 0.5));
    auth_label->setPosition(this->getContentSize().width / 2,
                            this->getContentSize().height * 2 / 3);

    auto back_label = Label::createWithSystemFont("Back", "", 15);

    auto back_menuitem = MenuItemLabel::create(
        back_label, CC_CALLBACK_0(AboutScene::menuItemBackCallback, this));

    auto menu = Menu::createWithItem(back_menuitem);
    menu->setAnchorPoint(cocos2d::Vec2(0.5, 0.5));
    menu->setPosition(this->getContentSize().width / 2,
                      this->getContentSize().height / 3);

    this->addChild(auth_label);
    this->addChild(menu);
    return true;
}

void AboutScene::menuItemBackCallback() {
    auto welcome_scene = WelcomeScene::createScene();
    Director::getInstance()->replaceScene(welcome_scene);
}