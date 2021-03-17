#pragma once

#include "cocos2d.h"

class AppMenu : public cocos2d::Scene
{
public:
    AppMenu();
    ~AppMenu() override;

    static cocos2d::Scene* createScene();
    static cocos2d::Scene* removeScene();

    bool init() override;

private:
    CREATE_FUNC(AppMenu);

private:
    void addMenuButton();
};