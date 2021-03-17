#pragma once

#include "cocos2d.h"
#include "AppUtils.h"

namespace UI
{
class Button
{
public:
    Button();
    ~Button();

    static cocos2d::MenuItem* create(const std::string &text, const AppUtils::ccMenuCallback &callback);
    static cocos2d::MenuItem* create(const std::string &text, AppUtils::POINT point, const AppUtils::ccMenuCallback &callback);
};
}