#ifndef NPC_H
#define NPC_H
#include <iostream>
#include <vector>
#include "item.h"
#include "GameCharacter.h"
#include "object.h"
#include "Player.h"
using namespace std;

class NPC : public Gamecharacter
{
public:
    NPC();
    NPC(string);
    NPC(string,string,vector<Item>);
    void listCommodity();
    Item buyItem(Item);
    Item buyItem(int);
    bool triggerEvent(Object*);
    bool hasThisItem(string);


    int vgetHealth();
    int vgetAttack();
    int vgetDefense();
    vector<Item> getCommodity();
    string getScript();
    void setCommodity(vector<Item>);
    void setScript(string);

private:
    string script;
    vector<Item> commodity;

};
#endif // NPC_H

