#include "Message.h"

namespace UI
{
bool Message::initWithNode(cocos2d::Node* node, const std::string &msg, const float &time, cocos2d::Vec2 point,
                           const cocos2d::ccMenuCallback &callback)
{
    if (!Layer::init())
    {
        return false;
    }
    //    _bg = Sprite::create("store/msgboxBg.png");
    //    this->addChild(_bg);
    //
    //    Size size = _bg->getContentSize();
    //    this->setContentSize(size);
    //
    //    //_labelExplain = Label::create(Explain, "Helvetica-Bold", 16, Size(200, 100), TextHAlignment::LEFT);
    //    Label* label = Label::create(msg.c_str(), "Helvetica-Bold", 15, Size(200,100), TextHAlignment::LEFT,TextVAlignment::CENTER);
    //    label->setColor(Color3B::YELLOW);
    //    label->ignoreAnchorPointForPosition(false); //开启锚点有效，不设false就是label被addChild后锚点不是原来的锚点而变为(0,0)左下角,设为false还是取原来的锚点
    //    label->setAnchorPoint(Vec2::ANCHOR_MIDDLE); //锚点在中间
    //    label->setTag(TAG_TOAST_LABEL);
    //    label->setPosition(Vec2(size.width/2, size.height/2));
    //
    //    _bg->addChild(label);
    //
    //    //CallFunc* call = CallFunc::create(callback);
    //    MenuItemImage* btnOK = MenuItemImage::create("Store/okBtn.png","Store/okBtnDown.png","Store/okBtn.png", callback);
    //    btnOK->setScale(0.8f);
    //    Menu* btnOkMenu = Menu::create(btnOK, NULL);
    //    btnOkMenu->setPosition(Vec2(size.width*0.3f, size.height*0.25f));
    //    _bg->addChild(btnOkMenu, 2);
    //
    //    MenuItemImage* btnCancel = MenuItemImage::create("Store/cancelBtn.png","Store/cancelBtnDown.png","Store/cancelBtn.png", CC_CALLBACK_0(BDMessageBox::CancelClick, this));
    //    btnCancel->setScale(0.8f);
    //    Menu* btnCancelMenu = Menu::create(btnCancel, NULL);
    //    btnCancelMenu->setPosition(Vec2(size.width*0.7f, size.height*0.25f));
    //    _bg->addChild(btnCancelMenu, 2);
    //
    //    _bg->setScale(0.01f);
    //    _bg->setVisible(false);
    //
    //    node->addChild(this, 5);
    //    this->setPosition(point);

    return true;
}

Message* Message::createToast(cocos2d::Node* node, const std::string &msg, const float &time, cocos2d::Vec2 point,
                              const cocos2d::ccMenuCallback &callback)
{
    //    BDMessageBox* pRet = new BDMessageBox();
    //    if (pRet && pRet->initWithNode(node, msg, time, point,callback))
    //    {
    //        return pRet;
    //    }
    //    else
    //    {
    //        delete pRet;
    //        pRet = nullptr;
    //        return pRet;
    //    }
}

void Message::onEnter()
{
    //    Layer::onEnter();
    //    _bg->setVisible(true);

    //    Sequence *seq = Sequence::create(EaseElasticIn::create(ScaleTo::create(0.5f, 1.1f, 1.1f)),
    //                                     EaseElasticOut::create(ScaleTo::create(0.2f, 1.f, 1.f)), NULL);
    //    _bg->runAction(seq);
}

void Message::OkClick()
{

}

void Message::CancelClick()
{
    //    CallFunc* removeC = CallFunc::create([this]()   //飘出后要删除掉自身
    //                                         {
    //                                             _bg->setVisible(false);
    //                                             this->removeFromParentAndCleanup(true);    //这里CallFunc参数是lambda表达式，捕获参数是类自身
    //                                         });
    //
    //    Sequence *seq = Sequence::create(EaseElasticOut::create(ScaleTo::create(0.5f, 0.01f, 0.01f)), removeC, nullptr);
    //    _bg->runAction(seq);
}
}