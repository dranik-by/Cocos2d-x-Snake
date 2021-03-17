#pragma once

#include "cocos2d.h"

class GameOver : public cocos2d::Scene
{
public:
    GameOver();
    ~GameOver() override;

    static cocos2d::Scene* createScene();
    static cocos2d::Scene* removeScene();

    CREATE_FUNC(GameOver);

    bool init() override;

    void onShowSceneGame(float delta);

    cocos2d::Sprite* spriteLoading {};

    int start = 0;
    bool act = false;
};