//
//  PlayScene.cpp
//  Pokemon
//
//  Created by Jenny Valdez on 22/02/13.
//
//

#include "PlayScene.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* PlayScene::scene()
{
    CCScene *scene = CCScene::create();
    
    PlayScene *playScene = PlayScene::create();
    BackgroundLayer *backgroundLayer = BackgroundLayer::create();
    CharactersLayer *charactersLayer = CharactersLayer::create();
    
    playScene->characterLayer = charactersLayer;
    
    scene->addChild(playScene);
    scene->addChild(backgroundLayer);
    scene->addChild(charactersLayer);
    
    return scene;
}

bool PlayScene::init()
{
    // Super init
    if (!CCLayer::init())
        return false;
    
    this->schedule(schedule_selector(PlayScene::onEnd));
    
    return true;
}

void PlayScene::onEnd(CCTime dt)
{
    if (characterLayer->isGameOver())
        CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(2, MenuScene::scene()));
}
