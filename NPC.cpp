#include "NPC.h"


NPC::NPC() {}
NPC::NPC(string nam):Gamecharacter(nam,"npc",100,100,100)
{

}
NPC::NPC(string scri,string nam,vector<Item> c):Gamecharacter(nam,"npc",10,5,3)
{
    script=scri;
    commodity=c;
}
vector<Item> NPC::getCommodity()
{
    return commodity;
}
string NPC::getScript()
{

    return script;
}
void NPC::setCommodity(vector<Item> c)
{
    commodity=c;
}
void NPC::setScript(string s)
{

    script=s;
}

void NPC::listCommodity()
{
    cout<<get_name()<<":I have these things.\n";
    for(int i=0; i<commodity.size(); i++)
    {
        cout<<i+1<<". "<<commodity[i].get_name()<<endl;
    }
}

Item NPC::buyItem(Item wantToBuy)
{
    Item webuy;
    int i;
    for(i=0; i<commodity.size(); i++)
    {
        if(commodity[i]==wantToBuy)
        {
            break;
        }
    }
    webuy=commodity[i];
    commodity.erase(commodity.begin()+i);
    return webuy;
}

Item NPC::buyItem(int idx)
{
    Item weBuy;
    int index=idx-1;
    weBuy=commodity[index];
    commodity.erase(commodity.begin()+index);
    return weBuy;

}

bool NPC::triggerEvent(Object* obj)
{
    Player* player=dynamic_cast<Player*> (obj);
    if(commodity.size()==0)
    {
        cout<<"Sorry, I don't have any item left.";
        return false;
    }
    else
    {
        cout<<"Hello, I am "<<get_name()<<"Which item you want to buy(take)XD?"<<endl;
        listCommodity();

        while(1)
        {
            cout<<"Please enter the number of the item which you want to buy:";
            int opt;
            cin>>opt;
            if(opt>=1&&opt<=commodity.size())
            {
                player->addItem(buyItem(opt));
                return true;
            }
            else
            {
                cout<<"You enter a wrong number.Please input again.\n";
            }
        }
    }


}






























