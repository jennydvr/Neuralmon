//
//  CharactersLayer.h
//  Pokemon
//
//  Created by Jenny Valdez on 22/02/13.
//
//

#ifndef __Pokemon__CharactersLayer__
#define __Pokemon__CharactersLayer__

#include "cocos2d.h"
#include "Pet.h"

#include "Saquito.h"

class CharactersLayer : public cocos2d::CCLayer {
protected:
    
    // Jugadores del juego
    Pet *player1;       // Persona
    Pet *player2;       // Computadora
    
    // Labels de los stats de los jugadores
    cocos2d::CCLabelTTF *label1;
    cocos2d::CCLabelTTF *label2;
    
    // Mensajes de juego
    cocos2d::CCLabelTTF *gamelog;
    
    // Indica fin de juego
    bool gameover;
    bool exit;
    
    // Jugador actual - true: player1, false: player2
    bool currentPlayer;
    
    // Crea el menu de acciones - player1
    void showMoves();
    
    // Escoger una accion - player2
    void chooseMove();

    // Ejecutar accion
    void play(CCObject* sender);
    
    // Turno nuevo
    void changeTurn();
    
    // Cambia los stats
    void changeStats();
    
    // Funcion para deteccion de toques
    void ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    
public:
        
    // Inicializar la capa
    virtual bool init();
    
    // Chequea si el juego ha terminado
    bool isGameOver();
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(CharactersLayer);
    
};

#endif /* defined(__Pokemon__CharactersLayer__) */
