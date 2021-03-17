#include "AppPause.h"

#include "Scene/Games/AppGame.h"
#include "UI/Button/Button.h"
#include "Scene/Menu/AppMenu.h"

AppPause::AppPause()
{
    cocos2d::log("AppPause");
}

AppPause::~AppPause()
{
    cocos2d::log("Remove: ~AppPause");
}

cocos2d::Scene* AppPause::createScene()
{
    return AppPause::create();
}

cocos2d::Scene* AppPause::removeScene()
{
    return AppPause::remove();
}

bool AppPause::init()
{
    this->addMenuButton();

    return true;
}

void AppPause::addMenuButton()
{
    cocos2d::MenuItem* itemResume = UI::Button::create("Resume", [](cocos2d::Ref* obj)
    {
        cocos2d::log("Click >> onButtonResume()");
        // cocos2d::Director::getInstance()->popSceneWithTransition();
        cocos2d::Director::getInstance()->popScene(cocos2d::TransitionFade::create(0.5f, AppPause::removeScene()));
    });

    cocos2d::MenuItem* itemMainMenu = UI::Button::create("Main Menu", [this](cocos2d::Ref* obj)
    {
        cocos2d::log("Click >> onButtonQuitGame()");
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(0.5f, AppMenu::createScene()));
    });

    cocos2d::Vector<cocos2d::MenuItem*> vector;
    vector.pushBack(itemResume);
    vector.pushBack(itemMainMenu);

    this->addChild(AppUtils::createVectorMenu(vector));
}