#pragma once

#include "cocos2d.h"

class AppGame : public cocos2d::Scene
{
    enum games
    {
        wall = 0,
        pass = 1,
        start = 3,
        item = 5
    };

public:
    AppGame();
    ~AppGame() override;

    static cocos2d::Scene* createScene();
    static cocos2d::Scene* removeScene();

    bool init() override;

    void gameOver();
    void blockAddMaps(const cocos2d::Point &point, int iSwitch);
    void addStackSnake(const cocos2d::Point &point);
    static cocos2d::Point coordinateToPosition(const cocos2d::Point &point);
    void listenerKeyboardEnable();
    void updateSnake(float);
    void addMaps();
    void addApple(const cocos2d::Point &point);
    void addSnakeTail(const cocos2d::Point &point);
    void updateApple();
    void updateBoolSnake(int boolSnake);

private:
    CREATE_FUNC(AppGame);
    static void menuCloseCallback(cocos2d::Ref* pSender);

private:
    //    virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    //    virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

    //    void onKeyHold(float interval);
    //    std::vector<cocos2d::EventKeyboard::KeyCode> heldKeys;

    cocos2d::Sprite* mario;

    cocos2d::Vector<cocos2d::Sprite*> list_snake;

    cocos2d::Sprite* apple_ {};

    bool b_up = false;
    bool b_down = false;
    bool b_left = false;
    bool b_right = false;

    const int _width = 10;
    const int _height = 10;

    int intKeyCode {};

    bool activeScene = true;

    static const int _block = 32;

    int _x;
    int _y;

    int** maze;
};
