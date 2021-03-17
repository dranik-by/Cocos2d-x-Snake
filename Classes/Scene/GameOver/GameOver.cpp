#include "GameOver.h"

#include "Scene/Menu/AppMenu.h"
#include "AppUtils.h"

GameOver::GameOver()
{
    cocos2d::log("GameOver");
}

GameOver::~GameOver()
{
    cocos2d::log("Remove: GameOver");
}

cocos2d::Scene* GameOver::createScene()
{
    return GameOver::create();
}

cocos2d::Scene* GameOver::removeScene()
{
    return GameOver::remove();
}

bool GameOver::init()
{
    spriteLoading = cocos2d::Sprite::create("Scene/GameOver/GameOver.png");
    spriteLoading->setPosition(AppUtils::setPoint(AppUtils::POINT::CENTRE));
    this->addChild(spriteLoading);

    this->schedule(CC_SCHEDULE_SELECTOR(GameOver::onShowSceneGame), 1.0f);

    return true;
}

void GameOver::onShowSceneGame(float delta)
{
    ++start;

    if (act)
    {
        act = false;
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(0.5f, AppMenu::createScene()));
    }

    if (start == 3)
    {
        act = true;
    }
}