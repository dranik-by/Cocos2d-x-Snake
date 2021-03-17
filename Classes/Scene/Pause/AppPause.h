#pragma once

#include "cocos2d.h"

class AppPause : public cocos2d::Scene
{
public:
    AppPause();
    ~AppPause();

    static cocos2d::Scene* createScene();
    static cocos2d::Scene* removeScene();

    bool init() override;

private:
    CREATE_FUNC(AppPause);

    void addMenuButton();
};
