#pragma once

#include "cocos2d.h"

namespace UI
{
class Label
{
public:
    static cocos2d::Label* create(std::string text);
};
}