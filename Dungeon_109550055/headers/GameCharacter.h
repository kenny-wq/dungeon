#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H
#include <iostream>
#include "object.h"
using namespace std;
class Gamecharacter: public Object
{
public:
    Gamecharacter();
    Gamecharacter(string, string, int, int, int);
    Gamecharacter(string nam,string ta,int ma,int curr,int atta,int def);

    bool checkIsDead();
    int takeDamage(int);

    int get_currentHealth();
    int get_maxHealth();
    int get_attack();
    int get_defense();
    void set_currentHealth(int);
    void set_maxHealth(int);
    void set_attack(int);
    void set_defense(int);
private:
    int maxHealth;
    int currentHealth;
    int attack;
    int defense;
};
#endif // GAMECHARACTER_H
