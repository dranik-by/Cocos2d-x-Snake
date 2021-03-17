#pragma once

#include <cocos2d.h>
#include <iostream>

namespace UI
{
class TiledMap
{
public:
    static cocos2d::TMXTiledMap* create(std::string tmxFile);
    static void createTMXTiled(cocos2d::TMXTiledMap* tmxTiledMap);
};
}