//
//  Yaram.h
//  Neuralmon
//
//  Created by Jenny Valdez on 25/03/13.
//
//

#ifndef __Neuralmon__Yaram__
#define __Neuralmon__Yaram__

#include "Tackle.h"
#include "Recover.h"
#include "Spite.h"
#include "Charm.h"

class Yaram : public Pet {
protected:
    
    // Agrega los movimientos
    virtual void addMoves();
    
public:
    
    // Constructor
    Yaram();
    
};

#endif /* defined(__Neuralmon__Yaram__) */
