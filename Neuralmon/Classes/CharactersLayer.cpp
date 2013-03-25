//
//  CharactersLayer.cpp
//  Pokemon
//
//  Created by Jenny Valdez on 22/02/13.
//
//

#include "CharactersLayer.h"

using namespace cocos2d;

bool CharactersLayer::init()
{
    // Super init
    if (!CCLayer::init())
        return false;
    
    // Inicializar los jugadores
    player1 = new Saquito();
    player2 = new Saquito();
    
    // Inicializar los stats y las imagenes
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    // Player 1
    player1->getSprite()->setPosition(ccp(70, 225));
    this->addChild(player1->getSprite());
    CCSprite *box1 = CCSprite::create("statsbox.png");
    box1->setScale(0.5f);
    box1->setPosition(ccp(winSize.width / 2 + 60, winSize.height / 2 - 30));
    box1->setRotationY(180);
    this->addChild(box1, -1);
    
    label1 = CCLabelTTF::create(player1->toString().c_str(), "Marker Felt", 20);
    label1->setColor(ccBLACK);
    label1->setPosition(ccp(winSize.width / 2 + 60, winSize.height / 2 - 20));
    this->addChild(label1);
    
    // Player 2
    player2->getSprite()->setPosition(ccp(winSize.width - 70, winSize.height - 100));
    this->addChild(player2->getSprite());
    CCSprite *box2 = CCSprite::create("statsbox.png");
    box2->setPosition(ccp(winSize.width / 2 - 60, winSize.height / 2 + 160));
    box2->setScale(0.5f);
    this->addChild(box2, -1);
    
    label2 = CCLabelTTF::create(player2->toString().c_str(), "Marker Felt", 20);
    label2->setColor(ccBLACK);
    label2->setPosition(ccp(winSize.width / 2 - 60, winSize.height / 2 + 170));
    this->addChild(label2);
    
    // Mensaje
    gamelog = CCLabelTTF::create("", "Marker Felt", 20);
    gamelog->setColor(ccBLACK);
    gamelog->setPosition(ccp(winSize.width / 2, winSize.height / 6));
    this->addChild(gamelog);
    
    // Poner el turno
    currentPlayer = gameover = exit = false;
    changeTurn();
    
    return true;
}

void CharactersLayer::changeTurn()
{
    // Cambiar el jugador y actualizar stats
    currentPlayer = !currentPlayer;
    label1->setString(player1->toString().c_str());
    label2->setString(player2->toString().c_str());
    
    if (currentPlayer)
        showMoves();
    else
        chooseMove();
}

void CharactersLayer::showMoves()
{
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCArray* pArray = NULL;
    
    // Poner la imagen
    CCSprite *sprite = CCSprite::create("movebox.png");
    sprite->setPosition(ccp(winSize.width / 2, winSize.height / 6));
    sprite->setScaleX(0.8f);
    sprite->setScaleY(0.75f);
    this->addChild(sprite, -1);
    
    CCMenuItemFont::setFontSize(20);
    CCMenuItemFont::setFontName("Marker Felt");
    
    for (int i = 0; i != player1->getNumMoves(); ++i) {
        CCMenuItemLabel *l = CCMenuItemFont::create(player1->moves[i]->toString().c_str(), this, menu_selector(CharactersLayer::play));
        
        if (player1->moves[i]->getPP() <= 0)
            l->setColor(ccGRAY);
        else
            l->setColor(ccBLACK);
        
        CCMenuItem *item = l;
        item->setTag(i);
        
        // Situarlo en la pantalla
        CCPoint pos = ccp(-winSize.width / 2 + 90, -winSize.height / 3);
        pos.x *= (i % 2 == 0) ? 1 : -1;
        pos.y += (i / 2 == 0) ? 25 : -25;
        item->setPosition(pos);
        
        if (pArray == NULL)
            pArray = CCArray::create(item, NULL);
        else
            pArray->addObject(item);
    }
    
    CCMenu *menu = CCMenu::createWithArray(pArray);
    menu->setTag(0);
    this->addChild(menu, 1);
}

void CharactersLayer::chooseMove()
{
    gamelog->setString(player2->useMove(rand() % player2->getNumMoves(), player1).c_str());
    this->setTouchEnabled(true);
}

void CharactersLayer::play(CCObject* sender)
{
    std::string result = player1->useMove((int)((CCMenuItem *)sender)->getTag(), player2);
    
    if (result.compare("NO") == 0) {
        gamelog->setString("PPs insuficientes");
        return;
    }
    
    this->removeChildByTag(0, true);
    gamelog->setString(result.c_str());
    this->setTouchEnabled(true);
}

void CharactersLayer::ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event)
{
    // Chequea el toque para salir del juego
    if (gameover) {
        exit = true;
        this->setTouchEnabled(false);
        return;
    }
    
    // Chequea game over
    if (player1->getHP() <= 0 || player2->getHP() <= 0) {
        gameover = true;
        gamelog->setString((player1->getHP() <= 0 ? "Has perdido!" : "Has ganado!"));
        return;
    }
    
    // Cambia el turno
    this->setTouchEnabled(false);
    gamelog->setString("");
    changeTurn();
}

bool CharactersLayer::isGameOver()
{
    return exit;
}
