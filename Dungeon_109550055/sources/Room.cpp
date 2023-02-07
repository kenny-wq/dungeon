#include "../headers/Room.h"
#include "../headers/Monster.h"
#include "../headers/NPC.h"
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
    int i;
    for(i=0; i<objects.size(); i++)
    {
        if(objects[i]==obj)
        {
            break;
        }
    }
    objects.erase(objects.begin()+i);
    return true;

}

void Room::printRoomItem()
{

    for(int i=0; i<50; i++)
    {
        cout<<"=";
    }
    cout<<endl;
    cout<<"Room"<<index<<" This room has:\n";



    cout<<"Item:\n";
    for(int i=0; i<objects.size(); i++)
    {


        if(objects[i]->get_tag()=="item")
        {

            Item* it = dynamic_cast<Item*>(objects[i]);
            cout<<it->get_name()<<" ";
        }
    }
    cout<<endl<<endl;

    cout<<"NPC:\n";
    for(int i=0; i<objects.size(); i++)
    {
        if(objects[i]->get_tag()=="npc")
        {
            NPC* np = dynamic_cast<NPC*>(objects[i]);
            cout<<np->get_name()<<" ";
        }
    }
    cout<<endl<<endl;

    cout<<"Monster:\n";
    for(int i=0; i<objects.size(); i++)
    {
        if(objects[i]->get_tag()=="monster")
        {
            Monster* mt = dynamic_cast<Monster*>(objects[i]);
            cout<<mt->get_name()<<" ";
        }
    }
    cout<<endl;

    for(int i=0; i<50; i++)
    {
        cout<<"=";
    }
    cout<<endl<<endl;






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
