//
//  MenuScene.h
//  Pokemon
//
//  Created by Jenny Valdez on 22/02/13.
//
//

#ifndef __Pokemon__MenuScene__
#define __Pokemon__MenuScene__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

#include "PlayScene.h"

class MenuScene : public cocos2d::CCLayer {
protected:
    
    // Cambia a modo juego
    void onPlay(cocos2d::CCObject* sender);
    
    // Cerrar todo
    void onExit(cocos2d::CCObject* sender);
    
    // Play al sonido
    void playSelectionSound(cocos2d::CCObject* sender);
    
public:
    
    // Inicializar la escena
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(MenuScene);
    
};

#endif /* defined(__Pokemon__MenuScene__) */
