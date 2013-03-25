//
//  Pet.h
//  Pokemon
//
//  Created by Jenny Valdez on 22/02/13.
//
//

#ifndef __Neuralmon__Pet__
#define __Neuralmon__Pet__

#include "cocos2d.h"

class Pet;

class Move {
protected:
    
    // Maximos stats
    float maxPP;
    float maxPower;
    
    // Stats
    float pp;
    float power;
    
public:
    
    // Nombre del movimiento
    std::string name;
    
    // Constructor
    Move(float _maxPP, float _maxPower = 0);
    
    // Efecto de la accion
    virtual void effect(Pet *me, Pet *foe) = 0;
    
    // Convierte a string
    std::string toString();
    
    // Setters
    void setPP(int _pp);
    
    // Getters
    float getPP();
};


class Pet {
protected:
    
    // Nombre del pet
    std::string name;
    
    // Imagen de la mascota
    cocos2d::CCSprite *sprite;
    
    // Maximos stats
    float maxHP;
    float maxAttack;
    float maxDefense;
    
    // Stats actuales
    float hp;
    float attack;
    float defense;
    
    // Ultimo movimiento usdo
    int lastMove;
    
    // Agrega los movimientos
    virtual void addMoves() = 0;
    
public:
    
    // Lista de movimientos
    std::vector<Move *> moves;
    
    // Constructor
    Pet(float _maxHP, float _maxAttack, float _maxDefense);
    
    // Inicializa la mascota
    void init(const char* name);
    
    // Usa un movimiento
    std::string useMove(int num, Pet *foe);
    
    // Usa un movimiento escogido
    std::string useMove(Pet *foe);
    
    // Getters
    cocos2d::CCSprite* getSprite();
    float getMaxHP();
    float getHP();
    float getAttack();
    float getDefense();
    int getNumMoves();
    
    // "Setters" - dependen de los efectos activos
    void setHP(float _hp);
    void setDefense(float _defense);
    void setAttack(float _attack);
    void setLastMovePP(float _pp);
    
    // Retorna el pet en string
    std::string toString();
    
};

#endif /* defined(__Neuralmon__Pet__) */
