#pragma once

#include "cocos2d.h"
#include "cocos/ui/UISlider.h"

namespace UI
{
    class Slider
    {
    public:
        cocos2d::ui::Slider* slider;
        cocos2d::Label* label;

        static Slider createTSlider(const std::string &text);
    };
}