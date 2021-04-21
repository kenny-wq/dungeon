#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
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
    void addItem(Item);
    void increaseStates(int,int,int);
    void lootRoom(Room*);
    void changeRoom(Room*);
    bool triggerEvent(Object*);
    //getter
    Room* getPreviousRoom();
    Room* getCurrentRoom();
    vector<Item> getInventory();
    //getter

    //setter
    void setCurrentRoom(Room*);
    void setPreviousRoom(Room*);
    void setInventory(vector<Item>);
    //setter
private:
    Room* currentRoom;
    Room* previousRoom;
    vector <Item> inventory;
};
#endif // PLAYER_H

























