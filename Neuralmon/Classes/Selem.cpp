//
//  Selem.cpp
//  Neuralmon
//
//  Created by Jenny Valdez on 25/03/13.
//
//

#include "Selem.h"

Selem::Selem() : Pet(106, 90, 130)
{
    name = "Saquito";
    Pet::init("Selem.png");
    
    sprite->setScale(0.125f);
    addMoves();
}

void Selem::addMoves()
{
    moves.push_back(new Tackle());
    moves.push_back(new Recover());
    moves.push_back(new Spite());
    moves.push_back(new Charm());
}
