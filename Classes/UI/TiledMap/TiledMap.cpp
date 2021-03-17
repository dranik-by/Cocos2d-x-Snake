#include "TiledMap.h"

namespace UI
{
cocos2d::TMXTiledMap* TiledMap::create(std::string tmxFile)
{
    cocos2d::log("Remove: ~~~Loading TiledMap~~~\n");

    cocos2d::TMXTiledMap* tiledMap = cocos2d::TMXTiledMap::create(tmxFile.c_str());

    //Size Maps
    cocos2d::Size sizeMaps = tiledMap->getMapSize();
    cocos2d::log("Size Maps:\n\tw: %0.f\t h: %0.f", sizeMaps.width, sizeMaps.height);
    //Size Tiled
    cocos2d::Size sizeTiled = tiledMap->getTileSize();
    cocos2d::log("Size Tiled:\n\tw: %0.f\t h: %0.f", sizeTiled.width, sizeTiled.height);
    //Size Layer
    cocos2d::Size sizeLayer = tiledMap->getLayer("background")->getLayerSize();
    cocos2d::log("tmxLayerBackground:\n\tx= %0.f\t y= %0.f", sizeLayer.width, sizeLayer.height);

    for (int y = 0; y < int(sizeLayer.height); ++y)
    {
        for (int x = 0; x < int(sizeLayer.width); ++x)
        {
            cocos2d::log("%i\t", tiledMap->getLayer("background")->getTileGIDAt(cocos2d::Point(x, y)));
        }
    }

    return tiledMap;
}

void TiledMap::createTMXTiled(cocos2d::TMXTiledMap* tmxTiledMap)
{
    cocos2d::Vec2 sizeMaps = tmxTiledMap->getMapSize();
    cocos2d::Vec2 sizeTiled = tmxTiledMap->getTileSize();

    for (int y = 0; y < sizeMaps.y; ++y)
    {
        for (int x = 0; x < sizeMaps.x; ++x)
        {
            int iTiled = tmxTiledMap->getLayer("background")->getTileGIDAt(cocos2d::Vec2(x, y));
            std::string sTiled = "TiledMaps/" + std::to_string(iTiled) + ".png";

            cocos2d::Sprite* item = cocos2d::Sprite::create(sTiled.c_str());
            cocos2d::Vec2 vec2 = cocos2d::Vec2(x * sizeTiled.x,
                                               (sizeMaps.y * sizeTiled.y - sizeTiled.y) - y * sizeTiled.y);
            item->setAnchorPoint(cocos2d::Vec2(0, 0));
            item->setPosition(vec2);
            // scene->addChild(item);
        }
    }
}
}