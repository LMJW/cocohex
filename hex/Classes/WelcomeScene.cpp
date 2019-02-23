#include "WelcomeScene.h"
#include "cocos2d.h"

USING_NS_CC;

Scene* WelcomeScene::createScene() {
    auto scene = Scene::create();

    auto layer = WelcomeScene::create();

    scene->addChild(layer);
    return scene;
}

bool WelcomeScene::init() {
    if (!Layer::init()) {
        return false;
    }

    /// Create the welcome title
    auto title = Label::createWithSystemFont("Welcome to Hex", "", 25);
    title->setAnchorPoint(cocos2d::Vec2(0.5, 0.5));
    title->setPosition(this->getContentSize().width / 2,
                       this->getContentSize().height * 2 / 3);

    this->addChild(title, 1);

    /// Create the Menu
    Vector<MenuItem*> menuitems;
    auto play = Label::createWithSystemFont("play", "", 15);
    auto play_menu = MenuItemLabel::create(play);

    auto setting = Label::createWithSystemFont("setting", "", 15);
    auto setting_menu = MenuItemLabel::create(setting);

    auto about = Label::createWithSystemFont("about", "", 15);
    auto about_menu = MenuItemLabel::create(about);

    menuitems.pushBack(play_menu);
    menuitems.pushBack(setting_menu);
    menuitems.pushBack(about_menu);

    auto menu = Menu::createWithArray(menuitems);
    menu->setAnchorPoint(cocos2d::Vec2(0.5, 0.5));
    menu->setPosition(this->getContentSize().width / 2,
                      this->getContentSize().height * 1 / 3);
    menu->alignItemsVerticallyWithPadding(0.1);

    this->addChild(menu);

    return true;
}
