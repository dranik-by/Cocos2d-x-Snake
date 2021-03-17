#include "LoadingBar.h"

namespace UI
{
    cocos2d::ui::LoadingBar* LoadingBar::create()
    {
        cocos2d::ui::LoadingBar* loadingBar = cocos2d::ui::LoadingBar::create("LoadingBarFile.png");
        //    loadingBar->setDirection(LoadingBar::Direction::RIGHT);

        // something happened, change the percentage of the loading bar
        loadingBar->setPercent(25);

        return loadingBar;
    }
}