//
//  Pet.cpp
//  Pokemon
//
//  Created by Jenny Valdez on 22/02/13.
//
//

#include "Pet.h"

using namespace cocos2d;

Move::Move(float _maxPP, float _maxPower) : maxPP(_maxPP),  maxPower(_maxPower), pp(_maxPP), power(_maxPower) {}

std::string Move::toString()
{
    std::stringstream ss;
    ss << name << "\n";
    ss << "PP = " << pp << "/" << maxPP;
    return ss.str();
}

float Move::getPP()
{
    return pp;
}

void Move::setPP(int _pp)
{
    pp += _pp;
    
    // Reiniciar a los limites
    if (pp < 0)
        pp = 0;
    else if (pp > maxPP)
        pp = maxPP;
}

Pet::Pet(float _maxHP, float _maxAttack, float _maxDefense) :
    maxHP(_maxHP), maxAttack(_maxAttack), maxDefense(_maxDefense),
    hp(_maxHP), attack(_maxAttack), defense(_maxDefense), lastMove(0) {}

void Pet::init(const char* name)
{
    sprite = CCSprite::create(name);
}

std::string Pet::useMove(int n, Pet *foe)
{
    // Chequea si se puede usar el movimiento
    if (moves[n]->getPP() <= 0)
        return "NO";
    
    // Usa el movimiento
    moves[n]->effect(this, foe);
    lastMove = n;
    
    std::stringstream ss;
    ss << name << " ha usado " << moves[n]->name << "!";
    return ss.str();
}

std::string Pet::useMove(Pet *foe)
{
    // Busca un movimiento disponible
    int n = rand() % moves.size();
    while (moves[n]->getPP() <= 0)
        n = rand() % moves.size();
    
    // Usa el movimiento
    moves[n]->effect(this, foe);
    lastMove = n;
    
    std::stringstream ss;
    ss << name << " ha usado " << moves[n]->name << "!";
    return ss.str();
}

CCSprite* Pet::getSprite()
{
    return sprite;
}

int Pet::getNumMoves()
{
    return moves.size();
}

float Pet::getMaxHP()
{
    return maxHP;
}

float Pet::getHP()
{
    return hp;
}

float Pet::getAttack()
{
    return attack;
}

float Pet::getDefense()
{
    return defense;
}

void Pet::setHP(float _hp)
{
    hp += _hp;
    
    // Reiniciar a los limites
    if (hp < 0)
        hp = 0;
    else if (hp > maxHP)
        hp = maxHP;
}

void Pet::setDefense(float _defense)
{
    defense += _defense;
    
    // Reiniciar a los limites
    if (defense < 0)
        defense = 0;
    else if (defense > maxDefense)
        defense = maxDefense;
}

void Pet::setAttack(float _attack)
{
    attack += _attack;
    
    // Reiniciar a los limites
    if (attack < 0)
        attack = 0;
    else if (attack > maxAttack)
        attack = maxAttack;
}

void Pet::setLastMovePP(float _pp)
{
    moves[lastMove]->setPP(_pp);
}

std::string Pet::toString()
{
    std::stringstream ss;
    ss << "HP = " << hp << "/" << maxHP << "\n";
    ss << "Atk = " << attack << "/" << maxAttack << "\n";
    ss << "Def = " << defense << "/" << maxDefense;
    return ss.str();
}
