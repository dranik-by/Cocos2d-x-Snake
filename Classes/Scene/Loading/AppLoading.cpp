#include "AppLoading.h"

#include "Scene/Games/AppGame.h"
#include "AppUtils.h"

AppLoading::AppLoading()
{
    cocos2d::log("AppLoading");
}

AppLoading::~AppLoading()
{
    cocos2d::log("Remove: ~AppLoading");
}

cocos2d::Scene* AppLoading::createScene()
{
    return AppLoading::create();
}

cocos2d::Scene* AppLoading::removeScene()
{
    return AppLoading::remove();
}

bool AppLoading::init()
{
    spriteLoading = cocos2d::Sprite::create("Scene/Loading/Loading.png");
    spriteLoading->setPosition(AppUtils::setPoint(AppUtils::POINT::CENTRE));
    this->addChild(spriteLoading);

    this->schedule(CC_SCHEDULE_SELECTOR(AppLoading::onShowSceneGame), 1.0f);

    return true;
}

void AppLoading::onShowSceneGame(float delta)
{
    ++start;

    if (act)
    {
        act = false;

        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(0.5f, AppGame::createScene()));
    }

    if (start == 3)
    {
        act = true;
    }
}