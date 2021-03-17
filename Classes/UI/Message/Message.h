#pragma once

#include "cocos2d.h"

namespace UI
{
class Message : public cocos2d::Layer
{
public:
    bool initWithNode(cocos2d::Node* node, const std::string &msg, const float &time, cocos2d::Vec2 point,
                      const cocos2d::ccMenuCallback &callback);
    Message* createToast(cocos2d::Node* node, const std::string &msg, const float &time, cocos2d::Vec2 point,
                         const cocos2d::ccMenuCallback &callback);
    void onEnter();
    void OkClick();
    void CancelClick();

private:
    CREATE_FUNC(Message);
};
}