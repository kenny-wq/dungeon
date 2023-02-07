#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include "object.h"

using namespace std;

class Item: public Object
{
public:
    Item();
    Item(string);
    Item(string,int,int,int);
    friend bool operator ==(Item ,Item);

    int vgetHealth();
    int vgetAttack();
    int vgetDefense();

    bool triggerEvent(Object*);
    void set_health(int);
    void set_attack(int);
    void set_defense(int);
    int get_health();
    int get_attack();
    int get_defense();
private:
    int health;
    int attack;
    int defense;
};
#endif // ITEM_H
