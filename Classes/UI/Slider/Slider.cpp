#include "Slider.h"

#include "AppUtils.h"

namespace UI
{
Slider Slider::createTSlider(const std::string &text)
{
    cocos2d::ui::Slider* slider = cocos2d::ui::Slider::create();
    slider->setName(text);
    slider->loadBarTexture("UI/Slider/Slider_Back.png");
    slider->loadSlidBallTextures("UI/Slider/SliderNode_Normal.png", "UI/Slider/SliderNode_Press.png",
                                 "UI/Slider/SliderNode_Disable.png");
    slider->loadProgressBarTexture("UI/Slider/Slider_PressBar.png");

    slider->addEventListener([](cocos2d::Ref* ptr, cocos2d::ui::Slider::EventType eventType)
                             {
                                 cocos2d::ui::Slider* slider = dynamic_cast<cocos2d::ui::Slider*>(ptr);

                                 switch (eventType)
                                 {
                                     case cocos2d::ui::Slider::EventType::ON_SLIDEBALL_DOWN:
                                         cocos2d::log("Slider(%s): ON_SLIDEBALL_DOWN: %i", slider->getName().c_str(),
                                                      slider->getPercent());
                                         break;
                                     case cocos2d::ui::Slider::EventType::ON_PERCENTAGE_CHANGED:
                                         cocos2d::log("Slider(%s): ON_PERCENTAGE_CHANGED: %i",
                                                      slider->getName().c_str(), slider->getPercent());
                                         break;
                                     case cocos2d::ui::Slider::EventType::ON_SLIDEBALL_UP:
                                         cocos2d::log("Slider(%s): ON_SLIDEBALL_UP: %i", slider->getName().c_str(),
                                                      slider->getPercent());
                                         break;
                                     case cocos2d::ui::Slider::EventType::ON_SLIDEBALL_CANCEL: //?
                                         cocos2d::log("Slider(%s): ON_SLIDEBALL_UP: %i", slider->getName().c_str(),
                                                      slider->getPercent());
                                         break;
                                 }
                             });

    //    slider->setPosition(TSettingsApp::POINT::CENTRE);

    cocos2d::Label* label = cocos2d::Label::createWithTTF(text, AppUtils::Text::font, AppUtils::Text::size);
    label->setPosition(slider->getPosition().x - label->getContentSize().width,
                       slider->getPosition().y + label->getContentSize().height);

    return {slider, label};
}

//cocos2d::Vector<Slider>* Slider::create(std::vector vector)
//{
//    cocos2d::log("%i", vector.size());
//
//    cocos2d::Vector<Slider>* vec;
//
//    int       count = 0;
//    for (auto v : vector)
//    {
//        ++count;
//        vec->pushBack(createTSlider(v, count));
//    }
//    return vec;
//}
}