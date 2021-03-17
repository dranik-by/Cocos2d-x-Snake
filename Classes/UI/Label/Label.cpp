#include "Label.h"
#include "AppUtils.h"

namespace UI
{
cocos2d::Label* Label::create(std::string text)
{
    cocos2d::log(">> add Label: text=(%s)", text.c_str());
    cocos2d::Label* label = cocos2d::Label::createWithTTF(text, AppUtils::Text::font, AppUtils::Text::size);
    label->setName(text);

    return label;
}
}