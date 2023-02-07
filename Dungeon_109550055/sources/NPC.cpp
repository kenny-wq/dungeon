#include "../headers/NPC.h"


NPC::NPC() {}
NPC::NPC(string nam):Gamecharacter(nam,"npc",100,100,100)
{

}
NPC::NPC(string nam,string scri,vector<Item> c):Gamecharacter(nam,"npc",10,5,3)
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
bool NPC::hasThisItem(string name)
{
    bool hasThisItem;
    for(int i=0; i<commodity.size(); i++)
    {
        if(commodity[i].get_name()==name)
        {
            return true;
        }
    }
    return false;
}

bool NPC::triggerEvent(Object* obj)
{
    Player* player=dynamic_cast<Player*> (obj);
    if(commodity.size()==0)
    {
        cout<<endl<<"Sorry, I don't have any item left."<<endl;
        return false;
    }
    else
    {
        cout<<endl<<script<<endl;
        cout<<commodity[0].get_name()<<"\n"<<endl;
        string itemName;
        cin>>itemName;

        if(hasThisItem(itemName))
        {
            player->setInventory(commodity[0]);
            player->increaseStates(10,10,10);
            cout<<endl<<"You get a (10,10,10) buff."<<endl;
            commodity.clear();
            return true;
        }
        else{
            cout<<"Sorry, I don't have this item."<<endl;
            return false;
        }
    }


}



int NPC::vgetHealth()
{
    return get_currentHealth();
}
int NPC::vgetAttack()
{
    return get_attack();
}
int NPC::vgetDefense()
{
    return get_defense();
}

