#include "Button.h"

#include "../Label/Label.h"

namespace UI
{
    Button::Button()
    {
        cocos2d::log("Button");
    }

    Button::~Button()
    {
        cocos2d::log("Remove: ~Button");
    }

    cocos2d::MenuItem* Button::create(const std::string &text, const AppUtils::ccMenuCallback &callback)
    {
        cocos2d::log(">>> add Button: name=(%s)", text.c_str());

        cocos2d::Label* label = Label::create(text);
        cocos2d::MenuItemLabel* item = cocos2d::MenuItemLabel::create(label, callback);
        item->setName(text);

        return item;
    }

    cocos2d::MenuItem* Button::create(const std::string &text, AppUtils::POINT point,
                                      const AppUtils::ccMenuCallback &callback)
    {
        cocos2d::log(">>> add Button: name=(%s)", text.c_str());

        cocos2d::Label* label = Label::create(text);
        cocos2d::MenuItemLabel* item = cocos2d::MenuItemLabel::create(label, callback);
        item->setName(text);

        item->setPosition(AppUtils::setVec2MenuItem(item, point));

        return item;
    }
}