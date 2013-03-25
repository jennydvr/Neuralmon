//
//  BackgroundLayer.cpp
//  Pokemon
//
//  Created by Jenny Valdez on 22/02/13.
//
//

#include "BackgroundLayer.h"

using namespace cocos2d;

bool BackgroundLayer::init()
{
    // Super init
    if (!CCLayer::init())
        return false;
    
    generateBackground();
    
    return true;
}

void BackgroundLayer::generateBackground()
{
    CCLayerGradient* layer = CCLayerGradient::create(ccc4(255, 255, 255, 255), ccc4(240, 240, 240, 255));
    layer->setBlendFunc((ccBlendFunc){GL_ONE_MINUS_DST_COLOR, GL_ZERO});
    
    this->addChild(layer, -1);
}
