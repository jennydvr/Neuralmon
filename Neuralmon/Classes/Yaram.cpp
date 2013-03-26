//
//  Yaram.cpp
//  Neuralmon
//
//  Created by Jenny Valdez on 25/03/13.
//
//

#include "Yaram.h"

Yaram::Yaram() : Pet(106, 90, 130)
{
    name = "Saquito";
    Pet::init("Yaram.png");
    
    sprite->setScale(0.125f);
    addMoves();
}

void Yaram::addMoves()
{
    moves.push_back(new Tackle());
    moves.push_back(new Recover());
    moves.push_back(new Spite());
    moves.push_back(new Charm());
}
