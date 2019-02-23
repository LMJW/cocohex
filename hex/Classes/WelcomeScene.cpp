#include "WelcomeScene.h"
#include "AboutScene.h"
#include "GameScene.h"
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

    /// Create the MenuItems
    Vector<MenuItem*> menuitems;
    auto play = Label::createWithSystemFont("play", "", 15);
    auto play_menuitem = MenuItemLabel::create(
        play, CC_CALLBACK_0(WelcomeScene::menuItemPlayCallback, this));

    auto setting = Label::createWithSystemFont("setting", "", 15);
    auto setting_menuitem = MenuItemLabel::create(setting);

    auto about = Label::createWithSystemFont("about", "", 15);
    auto about_menuitem = MenuItemLabel::create(
        about, CC_CALLBACK_0(WelcomeScene::menuItemAboutCallback, this));

    auto exit_ = Label::createWithSystemFont("exit", "", 15);
    auto exit_menuitem = MenuItemLabel::create(
        exit_, CC_CALLBACK_0(WelcomeScene::menuItemExitCallback, this));

    menuitems.pushBack(play_menuitem);
    menuitems.pushBack(setting_menuitem);
    menuitems.pushBack(about_menuitem);
    menuitems.pushBack(exit_menuitem);

    auto menu = Menu::createWithArray(menuitems);

    menu->setAnchorPoint(cocos2d::Vec2(0.5, 0.5));
    menu->setPosition(this->getContentSize().width / 2,
                      this->getContentSize().height * 1 / 3);
    menu->alignItemsVerticallyWithPadding(0.1);

    this->addChild(title, 1);
    this->addChild(menu);

    return true;
}

void WelcomeScene::menuItemExitCallback() {
    Director::getInstance()->end();
}

void WelcomeScene::menuItemPlayCallback() {
    auto gameScene = GameScene::createScene();
    Director::getInstance()->replaceScene(gameScene);
}

void WelcomeScene::menuItemAboutCallback() {
    auto aboutScene = AboutScene::createScene();
    Director::getInstance()->replaceScene(aboutScene);
}