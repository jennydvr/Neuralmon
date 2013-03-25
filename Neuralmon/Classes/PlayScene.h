//
//  PlayScene.h
//  Pokemon
//
//  Created by Jenny Valdez on 22/02/13.
//
//

#ifndef __Pokemon__PlayScene__
#define __Pokemon__PlayScene__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

#include "MenuScene.h"
#include "BackgroundLayer.h"
#include "CharactersLayer.h"

class PlayScene : public cocos2d::CCLayer {
protected:
    
    CharactersLayer *characterLayer;
    
    // Cambia la escena cuando termina el juego
    void onEnd(cocos2d::CCTime dt);
    
public:
    
    // Inicializar la escena
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(PlayScene);
    
};

#endif /* defined(__Pokemon__PlayScene__) */
