#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <vector>
#include "object.h"
#include "item.h"


#include <cstdlib>
using namespace std;

class Room
{
public:
    Room();
    Room(bool,int,vector<Object*>);

    bool clearObject(Object*);

    void printRoomItem();
    void putItem(Object*);



    //getter
    bool getIsExit();
    int getIndex();
    vector<Object*> getObject();
    Room* getUpRoom();
    Room* getDownRoom();
    Room* getLeftRoom();
    Room* getRightRoom();

    //setter
    void setIsExit(bool);
    void setIndex(int);
    void setUpRoom(Room*);
    void setDownRoom(Room*);
    void setLeftRoom(Room*);
    void setRightRoom(Room*);
    void setObject(vector<Object*>);
private:
    Room* upRoom;
    Room* downRoom;
    Room* leftRoom;
    Room* rightRoom;

    bool isExit;
    int index;
    vector<Object*> objects;
};
#endif // ROOM_H

