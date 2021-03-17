#include "AppGame.h"

#include "Scene/GameOver/GameOver.h"
#include "Scene/Pause/AppPause.h"

#include "AppUtils.h"

#include "UI/Button/Button.h"

AppGame::AppGame()
{
    cocos2d::log("AppGame");
}

AppGame::~AppGame()
{
    cocos2d::log("Remove: ~AppGame");

    for (int i = 0; i < _height; i++)
    {
        delete[] maze[i];
    }

    delete[] maze;
}

cocos2d::Scene* AppGame::createScene()
{
    return AppGame::create();
}

cocos2d::Scene* AppGame::removeScene()
{
    return AppGame::remove();
}

bool AppGame::init()
{
    this->addChild(AppUtils::drawTop());
    this->addChild(AppUtils::drawBottom());
    this->addChild(AppUtils::drawLeft());
    this->addChild(AppUtils::drawRight());

    cocos2d::MenuItem* item = UI::Button::create("STOP", AppUtils::POINT::TOP_RIGHT, [=](cocos2d::Ref* obj)
    {
        cocos2d::log("Click >> onButtonPause()");
        cocos2d::Director::getInstance()->pushScene(cocos2d::TransitionFade::create(0.5f, AppPause::createScene()));
    });

    this->addChild(AppUtils::createMenu(item));

    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

    intKeyCode = 1 + rand() % 4;
    cocos2d::log("RAND intKeyCode: %d", intKeyCode);

    addMaps();
    updateBoolSnake(intKeyCode);

    listenerKeyboardEnable();

    schedule(CC_SCHEDULE_SELECTOR(AppGame::updateSnake), 0.5f);

    return true;
}

void AppGame::menuCloseCallback(Ref* pSender)
{
    cocos2d::Director::getInstance()->end();

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}

void AppGame::updateBoolSnake(int boolSnake)
{
    switch (boolSnake)
    {
        case 1:
        {
            _x = 0;
            _y = 1;

            b_up = true;
            b_down = false;
            b_left = true;
            b_right = true;
        }
            break;
        case 2:
        {
            _x = 0;
            _y = -1;

            b_up = false;
            b_down = true;
            b_left = true;
            b_right = true;
        }
            break;
        case 3:
        {
            _x = -1;
            _y = 0;

            b_up = true;
            b_down = true;
            b_left = true;
            b_right = false;
        }
            break;
        case 4:
        {
            _x = 1;
            _y = 0;

            b_up = true;
            b_down = true;
            b_left = false;
            b_right = true;
        }
            break;
    }

    _x = list_snake.at(0)->getPositionX() / _block + _x;
    _y = list_snake.at(0)->getPositionY() / _block + _y;
}

void AppGame::updateApple()
{
    int x = 1 + rand() % (_height - 2);
    int y = 1 + rand() % (_width - 2);

    cocos2d::Point pointUpdateApple = coordinateToPosition(cocos2d::Point(x, y));

    if (apple_->getPosition() == pointUpdateApple)
    {
        updateApple();
        return;
    }

    for (auto sprite : list_snake)
    {
        if (sprite != nullptr)
        {
            if (sprite->getPosition() == pointUpdateApple)
            {
                updateApple();
                return;
            }
        }
    }

    apple_->setPosition(pointUpdateApple);
}

void AppGame::updateSnake(float)
{
    updateBoolSnake(intKeyCode);

    //Передвигает змейки хвост
    for (int i = list_snake.size() - 1; i >= 1; --i)
    {
        cocos2d::Sprite* spriteEND = list_snake.at(i);
        //Последний спрайт, который будет привязан к предыдущему спрайту
        cocos2d::Sprite* spriteUP = list_snake.at(i - 1);
        if (spriteEND != nullptr && spriteUP != nullptr)
        {
            spriteEND->setPosition(spriteUP->getPosition());
        }
    }

    //Мы тут ходим
    switch (intKeyCode)
    {
        case 1:
        {
            if (maze[_x][_y] != wall)
            {
                list_snake.at(0)->setPosition(coordinateToPosition(cocos2d::Point(_x, _y)));
            }
            else
            {
                gameOver();
            }

            break;
        }

        case 2:
        {
            if (maze[_x][_y] != wall)
            {
                list_snake.at(0)->setPosition(coordinateToPosition(cocos2d::Point(_x, _y)));
            }
            else
            {
                gameOver();
            }

            break;
        }

        case 3:
        {
            if (maze[_x][_y] != wall)
            {
                list_snake.at(0)->setPosition(coordinateToPosition(cocos2d::Point(_x, _y)));
            }
            else
            {
                gameOver();
            }

            break;
        }

        case 4:
        {
            if (maze[_x][_y] != wall)
            {
                list_snake.at(0)->setPosition(coordinateToPosition(cocos2d::Point(_x, _y)));
            }
            else
            {
                gameOver();
            }

            break;
        }
    }

    //Яблоко нашел
    if (list_snake.at(0)->getPosition() == apple_->getPosition())
    {
        cocos2d::Sprite* sprite = list_snake.at(list_snake.size() - 1);
        updateApple();
        addSnakeTail(sprite->getPosition());
    }

    //КОД столкновения
    //Если голова врезалась в тело, то Змейка умрет
    for (int i = list_snake.size() - 1; i >= 2; --i)
    {
        if (list_snake.at(0)->getPosition() == list_snake.at(i)->getPosition())
        {
            gameOver();
        }
    }

}

void AppGame::gameOver()
{
    cocos2d::log("~~~GAME OVER~~~");
    cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(0.5f, GameOver::createScene()));
}

void AppGame::blockAddMaps(const cocos2d::Point &point, int iSwitch)
{
    cocos2d::Sprite* sprite = cocos2d::Sprite::create();

    switch (iSwitch)
    {
        case wall:
        {
            sprite->initWithFile("gnd.png");
            break;
        }
        case pass:
        {
            sprite->initWithFile("pan.png");
            break;
        }
    }

    sprite->setPosition(coordinateToPosition(point));
    addChild(sprite);
}

void AppGame::addStackSnake(const cocos2d::Point &point)
{
    cocos2d::Sprite* snake = cocos2d::Sprite::create("snake.png");
    snake->setPosition(coordinateToPosition(point));

    addChild(snake);
    list_snake.pushBack(snake);
}

void AppGame::addSnakeTail(const cocos2d::Point &point)
{
    cocos2d::Sprite* snake_tail = cocos2d::Sprite::create("bush.png");
    snake_tail->setPosition(point);
    addChild(snake_tail);
    list_snake.pushBack(snake_tail);
}

void AppGame::addApple(const cocos2d::Point &point)
{
    apple_ = cocos2d::Sprite::create("apple.png");
    apple_->setPosition(coordinateToPosition(point));
    addChild(apple_);
}

void AppGame::addMaps()
{
    maze = new int* [_height];

    for (int i = 0; i < _height; i++)
    {
        maze[i] = new int[_width];
    }

    for (int i = 0; i < _height; i++)
    {
        for (int j = 0; j < _width; j++)
        {
            maze[i][j] = wall;
        }
    }

    for (int i = 1; i < _height - 1; i++)
    {
        for (int j = 1; j < _width - 1; j++)
        {
            maze[i][j] = pass;
        }
    }

    for (int i = 0; i < _height; i++)
    {
        for (int j = 0; j < _width; j++)
        {
            if (maze[i][j] == wall)
            {
                blockAddMaps(cocos2d::Point(i, j), wall);
            }
            else
            {
                blockAddMaps(cocos2d::Point(i, j), pass);
            }
        }
    }

    int xStartSnake = _height / 2;
    int yStartSnake = _width / 2;
    maze[xStartSnake][yStartSnake] = 3;
    addStackSnake(cocos2d::Point(xStartSnake, yStartSnake));

    int xStartApple = 1 + rand() % (_height - 2);
    int yStartApple = 1 + rand() % (_width - 2);
    maze[xStartApple][yStartApple] = 5;
    addApple(cocos2d::Point(xStartApple, yStartApple));
}

cocos2d::Point AppGame::coordinateToPosition(const cocos2d::Point &point)
{
    float x = floor(point.x * _block + _block * 0.5f);
    float y = floor(point.y * _block + _block * 0.5f);

    return cocos2d::Point(x, y);
}

void AppGame::listenerKeyboardEnable()
{
    cocos2d::EventListenerKeyboard* eventListenerKeyboard = cocos2d::EventListenerKeyboard::create();
    cocos2d::Director::getInstance()->getOpenGLView()->setIMEKeyboardState(true);
    eventListenerKeyboard->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
    {

        if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_ENTER)
        {
            activeScene = !activeScene;
            cocos2d::log("activeScene %d", activeScene);
            if (!activeScene)
            {
                cocos2d::Director::getInstance()->pause();
            }
            else
            {
                cocos2d::Director::getInstance()->resume();
            }
        }

        if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW)
        {
            if (b_up)
            {
                intKeyCode = 1;
            }
        }

        if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW)
        {
            if (b_down)
            {
                intKeyCode = 2;
            }
        }

        if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW)
        {
            if (b_left)
            {
                intKeyCode = 3;
            }
        }

        if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
        {
            if (b_right)
            {
                intKeyCode = 4;
            }
        }
    };

    _eventDispatcher->addEventListenerWithSceneGraphPriority(eventListenerKeyboard, this);
}