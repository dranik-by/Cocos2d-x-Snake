#pragma once

namespace AppUtils
{
typedef std::function<void(cocos2d::Ref*)> ccMenuCallback;

namespace Text
{
const int size = 33;
const std::string font = "fonts/Marker Felt.ttf";
}

enum class POINT
{
    ZERO,
    CENTRE,
    CENTRE_LEFT,
    CENTRE_RIGHT,
    TOP_LEFT,
    TOP_RIGHT,
    TOP_CENTRE,
    BOTTOM_LEFT,
    BOTTOM_RIGHT,
    BOTTOM_CENTRE,
};

enum class Transition
{
    TRANSITION_SCENE,
    TRANSITION_SCENE_ORIENTED,
    TRANSITION_ROTO_ZOOM,
    TRANSITION_JUMP_ZOOM,
    TRANSITION_MOVE_INL,
    TRANSITION_MOVE_INR,
    TRANSITION_MOVE_INT,
    TRANSITION_MOVE_INB,
    TRANSITION_SLIDE_INL,
    TRANSITION_SLIDE_INR,
    TRANSITION_SLIDE_INB,
    TRANSITION_SLIDE_INT,
    TRANSITION_SHRINK_GROW,
    TRANSITION_FLIP_X,
    TRANSITION_FLIP_Y,
    TRANSITION_FLIP_ANGULAR,
    TRANSITION_ZOOM_FLIP_X,
    TRANSITION_ZOOM_FLIP_Y,
    TRANSITION_ZOOM_FLIP_ANGULAR,
    TRANSITION_FADE,
    TRANSITION_CROSS_FADE,
    TRANSITION_TURN_OFF_TILES,
    TRANSITION_SPLIT_COLS,
    TRANSITION_SPLIT_ROWS,
    TRANSITION_FADE_TR,
    TRANSITION_FADE_BL,
    TRANSITION_FADE_UP,
    TRANSITION_FADE_DOWN
};

static cocos2d::Size getSizeBorder()
{
    cocos2d::Size sizeBorder = cocos2d::Size(Text::size, Text::size);
    //    // cocos2d::log("sizeBorder\n\tx: %f\n\ty: %f", sizeBorder.width, sizeBorder.height);
    //    // cocos2d::log("Remove: ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    return sizeBorder;
}

static cocos2d::Size getSizeScreen()
{
    cocos2d::Size sizeScreen = cocos2d::Director::getInstance()->getOpenGLView()->getFrameSize();

    //    // cocos2d::log("sizeScreen\n\tx: %f\n\ty: %f", sizeScreen.width, sizeScreen.height);
    //    // cocos2d::log("Remove: ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    return sizeScreen;
}

static cocos2d::DrawNode* drawBottom()
{
    auto drawBottom = cocos2d::DrawNode::create();
    drawBottom->drawLine(cocos2d::Point(getSizeBorder().width, getSizeBorder().height),
                         cocos2d::Point(getSizeScreen().width - getSizeBorder().width, getSizeBorder().height),
                         cocos2d::Color4F::RED);
    return drawBottom;
}

static cocos2d::DrawNode* drawTop()
{
    auto drawTop = cocos2d::DrawNode::create();
    drawTop->drawLine(cocos2d::Point(getSizeBorder().width, getSizeScreen().height - getSizeBorder().height),
                      cocos2d::Point(getSizeScreen().width - getSizeBorder().width,
                                     getSizeScreen().height - getSizeBorder().height), cocos2d::Color4F::RED);
    return drawTop;
}

static cocos2d::DrawNode* drawLeft()
{
    auto drawLeft = cocos2d::DrawNode::create();
    drawLeft->drawLine(cocos2d::Point(getSizeBorder().width, getSizeBorder().height),
                       cocos2d::Point(getSizeBorder().width, getSizeScreen().height - getSizeBorder().height),
                       cocos2d::Color4F::RED);
    return drawLeft;
}

static cocos2d::DrawNode* drawRight()
{
    auto drawRight = cocos2d::DrawNode::create();
    drawRight->drawLine(cocos2d::Point(getSizeScreen().width - getSizeBorder().width, getSizeBorder().height),
                        cocos2d::Point(getSizeScreen().width - getSizeBorder().width,
                                       getSizeScreen().height - getSizeBorder().height), cocos2d::Color4F::RED);

    return drawRight;
}

static cocos2d::Size setPoint(POINT point)
{
    cocos2d::Size sizeScreen = cocos2d::Size(getSizeScreen().width - getSizeBorder().width * 2,
                                             getSizeScreen().height - getSizeBorder().height * 2);

    switch (point)
    {
        case POINT::ZERO:
            // cocos2d::log("ZERO - width: %f, height: %f", size.width, size.height);
            return cocos2d::Size(0 + getSizeBorder().width, 0 + getSizeBorder().height);

        case POINT::CENTRE:
            // cocos2d::log("CENTRE - width: %f, height: %f", size.width, size.height);
            return cocos2d::Size(sizeScreen.width / 2 + getSizeBorder().width / 2,
                                 sizeScreen.height / 2 + getSizeBorder().height / 2);

        case POINT::CENTRE_LEFT:
            // cocos2d::log("CENTRE_LEFT - width: %f, height: %f", size.width, size.height);
            return cocos2d::Size(0 + getSizeBorder().width, sizeScreen.height / 2 + getSizeBorder().height / 2);

        case POINT::CENTRE_RIGHT:
            // cocos2d::log("CENTRE_RIGHT - width: %f, height: %f", size.width, size.height);
            return cocos2d::Size(sizeScreen.width + getSizeBorder().width,
                                 sizeScreen.height / 2 + +getSizeBorder().height / 2);

        case POINT::TOP_LEFT:
            // cocos2d::log("TOP_LEFT - width: %f, height: %f", size.width, size.height);
            return cocos2d::Size(0 + getSizeBorder().width, sizeScreen.height + getSizeBorder().height);

        case POINT::TOP_RIGHT:
            // cocos2d::log("TOP_RIGHT - width: %f, height: %f", size.width, size.height);
            return cocos2d::Size(sizeScreen.width + getSizeBorder().width, sizeScreen.height + getSizeBorder().height);

        case POINT::TOP_CENTRE:
            // cocos2d::log("TOP_CENTRE - width: %f, height: %f", size.width, size.height);
            return cocos2d::Size(sizeScreen.width / 2, sizeScreen.height + getSizeBorder().height);

        case POINT::BOTTOM_LEFT:
            // cocos2d::log("BOTTOM_LEFT - width: %f, height: %f", size.width, size.height);
            return cocos2d::Size(0 + getSizeBorder().width, 0 + getSizeBorder().height);

        case POINT::BOTTOM_RIGHT:
            // cocos2d::log("BOTTOM_RIGHT - width: %f, height: %f", size.width, size.height);
            return cocos2d::Size(sizeScreen.width + getSizeBorder().width, 0 + getSizeBorder().height);

        case POINT::BOTTOM_CENTRE:
            // cocos2d::log("BOTTOM_CENTRE - width: %f, height: %f", size.width, size.height);
            return cocos2d::Size(sizeScreen.width / 2, 0 + getSizeBorder().height);

        default:
            return cocos2d::Size(sizeScreen.width / 2, 0 + getSizeBorder().height);
    }
}

static cocos2d::Vec2 setVec2MenuItem(cocos2d::MenuItem* menuItem, POINT point)
{
    cocos2d::Size size = setPoint(point);
    switch (point)
    {
        case POINT::ZERO:
            // cocos2d::log("POINT ZERO");
            return cocos2d::Vec2(size.width + menuItem->getContentSize().width / 2,
                                 size.height + menuItem->getContentSize().height / 2);

        case POINT::TOP_LEFT:
            // cocos2d::log("POINT TOP_LEFT");
            return cocos2d::Vec2(size.width + menuItem->getContentSize().width / 2,
                                 size.height - menuItem->getContentSize().height / 2);

        case POINT::TOP_RIGHT:
            // cocos2d::log("POINT TOP_RIGHT");
            return cocos2d::Vec2(size.width - menuItem->getContentSize().width / 2,
                                 size.height - menuItem->getContentSize().height / 2);

        case POINT::TOP_CENTRE:
            // cocos2d::log("POINT TOP_CENTRE");
            return cocos2d::Vec2(size.width + menuItem->getContentSize().width / 2,
                                 size.height - menuItem->getContentSize().height / 2);

        case POINT::BOTTOM_LEFT:
            // cocos2d::log("POINT BOTTOM_LEFT");
            return cocos2d::Vec2(size.width + menuItem->getContentSize().width / 2,
                                 size.height + menuItem->getContentSize().height / 2);

        case POINT::BOTTOM_RIGHT:
            // cocos2d::log("POINT BOTTOM_RIGHT");
            return cocos2d::Vec2(size.width - menuItem->getContentSize().width / 2,
                                 size.height + menuItem->getContentSize().height / 2);

        case POINT::BOTTOM_CENTRE:
            // cocos2d::log("POINT BOTTOM_CENTRE");
            return cocos2d::Vec2(size.width + menuItem->getContentSize().width / 2,
                                 size.height + menuItem->getContentSize().height / 2);

        case POINT::CENTRE_LEFT:
            // cocos2d::log("POINT CENTRE_LEFT");
            return cocos2d::Vec2(size.width + menuItem->getContentSize().width / 2,
                                 size.height + menuItem->getContentSize().height / 2);

        case POINT::CENTRE_RIGHT:
            // cocos2d::log("POINT CENTRE_RIGHT");
            return cocos2d::Vec2(size.width - menuItem->getContentSize().width / 2,
                                 size.height + menuItem->getContentSize().height / 2);

        case POINT::CENTRE:
            // cocos2d::log("POINT CENTRE");
            return cocos2d::Vec2(size.width + menuItem->getContentSize().height / 2,
                                 size.height + menuItem->getContentSize().height / 2);
    }
}

static cocos2d::Menu* createVectorMenu(cocos2d::Vector<cocos2d::MenuItem*> vector)
{
    std::reverse(vector.rbegin(), vector.rend());

    int count = 0;

    for (auto item : vector)
    {
        cocos2d::Point point = cocos2d::Point(setVec2MenuItem(item, POINT::CENTRE).x, setVec2MenuItem(item,
                                                                                                      POINT::BOTTOM_CENTRE).y + (item->getContentSize().height * count + 1) + (item->getContentSize().height * count / 2 / 2));
        item->setPosition(point);

        //        // cocos2d::log("Button: %s", item->getName().c_str());
        //        // cocos2d::log("Size: width:%f, height:%f", item->getContentSize().width, item->getContentSize().height);
        //        // cocos2d::log("Point: x:%f, y:%f", item->getPosition().x, item->getPosition().y);
        //        // cocos2d::log("Remove: ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

        ++count;
    }

    cocos2d::Menu* menu = cocos2d::Menu::createWithArray(vector);
    menu->setPosition(cocos2d::Vec2::ZERO);

    return menu;
}

static cocos2d::Menu* createMenu(cocos2d::MenuItem* menuItem)
{
    cocos2d::Vec2 vec2 = menuItem->getPosition();
    cocos2d::Size size = menuItem->getContentSize();

    //    // cocos2d::log("Button: %s", menuItem->getName().c_str());
    //    // cocos2d::log("getContentSize: width:%f, height:%f", menuItem->getContentSize().width,
    //                 menuItem->getContentSize().height);
    //    // cocos2d::log("getPosition: x:%f, y:%f", menuItem->getPosition().x, menuItem->getPosition().y);
    //    // cocos2d::log("Remove: ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    cocos2d::Menu* menu = cocos2d::Menu::createWithItem(menuItem);
    menu->setPosition(cocos2d::Vec2::ZERO);

    return menu;
}

//cocos2d::Vector<Slider> setVec2T(cocos2d::Vector<Slider> vector, POINT point)
//{
//    for (int i = 0; i < vector.size() / 2; ++i)
//    {
//
//    }
//
//    return vector;
//}

}