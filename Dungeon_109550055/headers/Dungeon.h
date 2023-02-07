#ifndef DUNGEON_H
#define DUNGEON_H

#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
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
    void handleMovement();
    void handleRetreat();
    bool handleEvent(Object*);
    bool checkMonsterRoom(vector<Object*>);
    void chooseAction(vector<Object*>);
    bool checkGameLogic();
    void runDungeon();
    void listOption();
    void listMoveMent();

    void isaveRecord();
    void nsaveRecord();
    void msaveRecord();

    void setkey();
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
    vector <Item> key;
    vector <Monster> giants;
    vector <NPC> people;

};
#endif

