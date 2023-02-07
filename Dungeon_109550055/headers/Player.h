#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <fstream>
#include <vector>
#include "item.h"
#include "GameCharacter.h"
#include "Room.h"
using namespace std;

class Player:public Gamecharacter
{
public:
    Player();
    Player(string,int,int,int);
    Player(string nam,int ma,int curr,int atta,int def,vector<Item> inv);
    void addItem(Item);
    void increaseStates(int,int,int);
    void lootRoom(Room*);
    void changeRoom(Room*);
    bool triggerEvent(Object*);
    void printInventory();
    void psaveRecord();

    int vgetHealth();
    int vgetAttack();
    int vgetDefense();
    //getter
    Room* getPreviousRoom();
    Room* getCurrentRoom();
    vector<Item> getInventory();
    //getter

    //setter
    void setCurrentRoom(Room*);
    void setPreviousRoom(Room*);
    void setInventory(Item);
    //setter
private:
    Room* currentRoom;
    Room* previousRoom;
    vector <Item> inventory;
};
#endif // PLAYER_H

























