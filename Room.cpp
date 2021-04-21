#include "Room.h"
#include "Monster.h"
#include "NPC.h"
Room::Room()
{
    upRoom=downRoom=leftRoom=rightRoom=NULL;
}
Room::Room(bool isExit_value,int index_value,vector<Object*> objects_value)
{
    upRoom=downRoom=leftRoom=rightRoom=NULL;
    isExit=isExit_value;
    index=index_value;
    this->objects=objects_value;
}

bool Room::clearObject(Object* obj)
{
    return true;

}
Item Room::buyItem(int idx)
{
    return Item();


}
void Room::printRoomItem()
{
    cout<<"\n";
    cout<<"=============================================================\n"<<endl;
    cout<<"Room"<<index<<" This room has:\n\n";



    cout<<"Item:\n\n";
    for(int i=0; i<objects.size(); i++)
    {


        if(objects[i]->get_tag()=="item")
        {

            Item* it = dynamic_cast<Item*>(objects[i]);
            cout<<i+1<<":"<<it->get_name()<<"\n"<<endl;
        }
    }

    cout<<"NPC:\n\n";
    for(int i=0; i<objects.size(); i++)
    {
        if(objects[i]->get_tag()=="npc")
        {
            NPC* np = dynamic_cast<NPC*>(objects[i]);
            cout<<i+1<<":"<<np->get_name()<<"\n"<<endl;
        }
    }

    cout<<"Monster:\n\n";
    for(int i=0; i<objects.size(); i++)
    {
        if(objects[i]->get_tag()=="monster"){
            Monster* mt = dynamic_cast<Monster*>(objects[i]);
            cout<<i+1<<":"<<mt->get_name()<<"\n"<<endl;
        }
    }






}
void Room::putItem(Object* it)
{
    objects.push_back(it);
}

//////////////////////////////////////////////////////////////////////////////getter
bool Room::getIsExit()
{
    return isExit;
}
int Room::getIndex()
{
    return index;
}
vector<Object*> Room::getObject()
{
    return objects;
}
Room* Room::getUpRoom()
{
    return upRoom;
}
Room* Room::getDownRoom()
{
    return downRoom;
}
Room* Room::getLeftRoom()
{
    return leftRoom;
}
Room* Room::getRightRoom()
{
    return rightRoom;
}
/////////////////////////////////////////////////////////////////////////////////////setter
void Room::setIsExit(bool ise)
{
    isExit=ise;
}
void Room::setIndex(int ind)
{
    index=ind;
}
void Room::setUpRoom(Room* upr)
{
    upRoom=upr;
}
void Room::setDownRoom(Room* dor)
{
    downRoom=dor;
}
void Room::setLeftRoom(Room* ler)
{
    leftRoom=ler;
}
void Room::setRightRoom(Room* rir)
{
    rightRoom=rir;
}
void Room::setObject(vector<Object*> obj)
{
    objects=obj;
}
