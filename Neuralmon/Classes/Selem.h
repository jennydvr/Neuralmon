//
//  Selem.h
//  Neuralmon
//
//  Created by Jenny Valdez on 25/03/13.
//
//

#ifndef __Neuralmon__Selem__
#define __Neuralmon__Selem__

#include "Tackle.h"
#include "Recover.h"
#include "Spite.h"
#include "Charm.h"

class Selem : public Pet {
protected:
    
    // Agrega los movimientos
    virtual void addMoves();
    
public:
    
    // Constructor
    Selem();
    
};

#endif /* defined(__Neuralmon__Selem__) */
