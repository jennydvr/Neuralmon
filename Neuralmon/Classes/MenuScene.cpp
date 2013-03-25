//
//  MenuScene.cpp
//  Pokemon
//
//  Created by Jenny Valdez on 22/02/13.
//
//

#include "MenuScene.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* MenuScene::scene()
{
    CCScene *scene = CCScene::create();
    MenuScene *layer = MenuScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool MenuScene::init()
{
    // Super init
    if (!CCLayer::init())
        return false;
    
    CCMenuItem *playItem = CCMenuItemFont::create("Jugar", this, menu_selector(MenuScene::onPlay));
    CCMenuItem *exitItem = CCMenuItemFont::create("Salir", this, menu_selector(MenuScene::onExit));
    
    CCMenu *menu = CCMenu::create(playItem, exitItem, NULL);
    menu->alignItemsVertically();
    
    this->addChild(menu, 0);
    
    return true;
}

void MenuScene::onPlay(CCObject* sender)
{
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(2, PlayScene::scene()));
}

void MenuScene::onExit(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
