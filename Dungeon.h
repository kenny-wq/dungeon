#ifndef DUNGEON_H
#define DUNGEON_H

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include "Room.h"
#include "object.h"
#include "Player.h"
#include "GameCharacter.h"
#include "Monster.h"
#include "NPC.h"
using namespace std;

class Dungeon
{
public:
    Dungeon();
    void startGame();
    void createPlayer();
    void createMap();
    void handleMovement(char);
    bool handleRetreat();
    bool handleEvent(Object*);
    bool checkMonsterRoom(vector<Object*>);
    void chooseAction(vector<Object*>);
    bool checkGameLogic();
    void runDungeon();
    void listOption();
    void setFruits();
    void setGiants();
    void setNPC();


    //getter setter
    Player getPlayer();
    vector<Room> getRoom();
    void setPlayer(Player);
    void setRoom(Room*);

private:
    Player player;
    bool win;
    vector<Room> rooms;
    vector <Item> fruits;
    vector <Monster> giants;
    vector <NPC> people;

};
#endif






































