#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>
#include "GameCharacter.h"
#include "object.h"
#include "Player.h"
using namespace std;

class Monster:public Gamecharacter
{
public:
    Monster();

    Monster(string,int,int,int);
    bool triggerEvent(Object*);
};
#endif // MONSTER_H
