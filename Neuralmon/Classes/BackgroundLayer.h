//
//  BackgroundLayer.h
//  Pokemon
//
//  Created by Jenny Valdez on 22/02/13.
//
//

#ifndef __Pokemon__BackgroundLayer__
#define __Pokemon__BackgroundLayer__

#include "cocos2d.h"

class BackgroundLayer : public cocos2d::CCLayer {
protected:
    
    // Crea el fondo del juego
    void generateBackground();
    
    // Cambia la escena cuando termina el juego
    void onEnd(cocos2d::CCTime dt);
    
public:
    
    // Inicializar la capa
    virtual bool init();
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(BackgroundLayer);
    
};

#endif /* defined(__Pokemon__BackgroundLayer__) */
