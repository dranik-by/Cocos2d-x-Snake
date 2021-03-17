#include "AppMenu.h"

#include "UI/Button/Button.h"
#include "Scene/Loading/AppLoading.h"
#include "AppUtils.h"

AppMenu::AppMenu()
{
    cocos2d::log("AppMenu");
}

AppMenu::~AppMenu()
{
    cocos2d::log("Remove: ~AppMenu");
}

cocos2d::Scene* AppMenu::createScene()
{
    return AppMenu::create();
}

cocos2d::Scene* AppMenu::removeScene()
{
    return AppMenu::remove();
}

bool AppMenu::init()
{
    this->addMenuButton();

    return true;
}

void AppMenu::addMenuButton()
{
    cocos2d::MenuItem* itemNewGame = UI::Button::create("New Game", [](cocos2d::Ref* obj)
    {
        cocos2d::log("Click >> onButtonNewGame()");
        cocos2d::Director::getInstance()->replaceScene(
        cocos2d::TransitionFade::create(0.5f, AppLoading::createScene()));
    });

    cocos2d::MenuItem* itemExit = UI::Button::create("Exit", [](cocos2d::Ref* obj)
    {
        cocos2d::log("Click >> onButtonExit()");
        cocos2d::Director::getInstance()->end();

        #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        exit(0);
        #endif
    });

    cocos2d::Vector<cocos2d::MenuItem*> vector;
    vector.pushBack(itemNewGame);
    vector.pushBack(itemExit);

    this->addChild(AppUtils::createVectorMenu(vector));
}
