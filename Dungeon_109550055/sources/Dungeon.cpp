#include "../headers/Dungeon.h"

Dungeon::Dungeon() {}
void Dungeon::startGame()
{
    char c;
    cout<<"Please choose an option."<<endl;
    cout<<"(A)start a new game"<<endl;
    cout<<"(B)Reload your previous game"<<endl;

    while(1)
    {
        cin>>c;
        c=toupper(c);
        if(c=='A'||c=='B')
        {
            break;
        }
        else
        {
            cout<<"Wrong input,please input again."<<endl;
        }
    }

    if(c=='A')
    {
        ofstream outPlayer,outItem,outNPC,outMonster;
        outPlayer.open("playerRecord.txt", std::ofstream::out | std::ofstream::trunc);
        outItem.open("itemRecord.txt", std::ofstream::out | std::ofstream::trunc);
        outNPC.open("npcRecord.txt", std::ofstream::out | std::ofstream::trunc);
        outMonster.open("monsterRecord.txt", std::ofstream::out | std::ofstream::trunc);
    }
    else if(c=='B')
    {

    }
    cout<<"Initialize map file...\n"<<endl;
    usleep(100);
    createMap();

    cout<<"Initialize player file...\n"<<endl;
    usleep(100);
    createPlayer();

    cout<<"Hello Alan,welcome to my Dungeon!\n"<<endl;
    usleep(100);

    cout<<"Please enjoy your trip.\n"<<endl;
    usleep(100);

    runDungeon();

}

void Dungeon::runDungeon()
{
    while(checkGameLogic())
    {
        player.getCurrentRoom()->printRoomItem();
        listOption();

    }

    if(win)
    {
        cout<<"\n\nYou win!Thanks for playing.\n\n\n";

    }
    else
    {
        cout<<"\n\nYou lose.Don't be depressive and play one more time.XD\n\n\n";
    }
    ofstream outPlayer,outItem,outNPC,outMonster;
    outPlayer.open("playerRecord.txt", std::ofstream::out | std::ofstream::trunc);
    outItem.open("itemRecord.txt", std::ofstream::out | std::ofstream::trunc);
    outNPC.open("npcRecord.txt", std::ofstream::out | std::ofstream::trunc);
    outMonster.open("monsterRecord.txt", std::ofstream::out | std::ofstream::trunc);
}
void Dungeon::createPlayer()
{
    player=Player("Alan",100,50,50);
    player.setCurrentRoom(&rooms[0]);
    player.setPreviousRoom(&rooms[0]);

    ifstream inplayer;
    inplayer.open("playerRecord.txt");

    char c;
    inplayer>>c;

    if(c=='\0')
    {
        player=Player("Alan",100,50,50);
        player.setCurrentRoom(&rooms[0]);
        player.setPreviousRoom(&rooms[0]);
    }
    else
    {
        string playerName;
        int maxHealth;
        int currentHealth;
        int attack;
        int defense;
        int currentRoomIndex;
        int previousRoomIndex;
        int inventoryNumber;

        string itemName;
        int itemHealth;
        int itemAttack;
        int itemDefense;

        vector<Item> inventory;

        inplayer>>playerName>>maxHealth>>currentHealth>>attack>>defense
                >>currentRoomIndex>>previousRoomIndex>>inventoryNumber;

        for(int i=0; i<inventoryNumber; i++)
        {
            inplayer>>itemName>>itemHealth>>itemAttack>>itemDefense;
            inventory.push_back(Item(itemName,itemHealth,itemAttack,itemDefense));
        }

        player=Player(playerName,maxHealth,currentHealth,attack,defense,inventory);

        player.setCurrentRoom(&rooms[currentRoomIndex]);
        player.setPreviousRoom(&rooms[previousRoomIndex]);
    }


}




void Dungeon::createMap()
{
    //set map
    ifstream inmap;

    inmap.open("map.txt");
    if (!inmap.good())
    {
        cout << "Map file loads failed\n";
        exit(0);
    }

    int roomNum;
    inmap>>roomNum;

    for(int i=0; i<roomNum; i++)
    {
        rooms.push_back(Room());
        rooms[i].setIndex(i);
    }
    //6-7-8-9
    //| | |
    //5-4-3
    //| | |
    //0-1-2
    int x;
    for(int i=0; i<roomNum; i++)
    {
        inmap>>x;
        if(x!=-1)
        {
            rooms[i].setUpRoom(&rooms[x]);
        }
        inmap>>x;
        if(x!=-1)
        {
            rooms[i].setDownRoom(&rooms[x]);
        }
        inmap>>x;
        if(x!=-1)
        {
            rooms[i].setLeftRoom(&rooms[x]);
        }
        inmap>>x;
        if(x!=-1)
        {
            rooms[i].setRightRoom(&rooms[x]);
        }

    }//set map

    setkey();
    setGiants();
    setNPC();

    ifstream inItem;
    inItem.open("itemRecord.txt");
    char c;
    inItem>>c;
    if(c=='\0')  //�Ĥ@���i��C��
    {
        //place key
        srand(time(NULL));
        for(int i=(rand()%3); i<roomNum-1; i+=2)
        {
            rooms[i].putItem(&key[0]);
        }

        //place npc
        srand(time(NULL));
        int ran=rand()%9;

        rooms[ran].putItem(&people[0]);

        if((ran+3)<=8)
        {
            rooms[ran+3].putItem(&people[1]);
        }
        else
        {
            rooms[ran-6].putItem(&people[1]);
        }

        if((ran+6)<=8)
        {
            rooms[ran+6].putItem(&people[2]);
        }
        else
        {
            rooms[ran-3].putItem(&people[2]);
        }


        //place monster
        rooms[9].putItem(&giants[rand()%9]);


        inmap.close();

    }
    else //�Y���O�Ĥ@���i��C���hŪ�ɮ�
    {
        //Ūitem
        int total;



        inItem>>total;

        int iroomIndex;
        for(int i=0; i<total; i++)
        {
            inItem>>iroomIndex;
            rooms[iroomIndex].putItem(&key[0]);
        }

        //Ūnpc
        ifstream inNPC;
        inNPC.open("npcRecord.txt");

        string npcNam,comName;
        int nroomIdex;

        for(int i=0; i<3; i++)
        {
            inNPC>>nroomIdex>>npcNam>>comName;

            vector<Item> com;
            if(comName=="noitem")
            {

            }
            else
            {
                com.push_back(Item(comName,10,10,10));
            }

            NPC* np= new NPC(npcNam,"Which item do you want?",com);
            rooms[nroomIdex].putItem(np);
        }

        //Ūmonster
        ifstream inMonster;
        inMonster.open("monsterRecord.txt");

        string monName;
        int mmaxhealth,mcurrhealth,mattack,mdefense;

        inMonster>>monName>>mmaxhealth>>mcurrhealth>>mattack>>mdefense;

        Monster* mon=new Monster(monName,mmaxhealth,mcurrhealth,mattack,mdefense);
        rooms[9].putItem(mon);

    }
}
void Dungeon::listOption()
{
    Room* nr = player.getCurrentRoom();
    vector<Object*> obj=nr->getObject();


    Monster* mt;
    int monster_index;
    bool hasMonster=false;
    bool hasNPC=false;
    bool hasItem=false;
    for(int i=0; i<obj.size(); i++)
    {
        if(obj[i]->get_tag()=="monster")
        {
            monster_index=i;
            hasMonster=true;
            mt=dynamic_cast<Monster*>(obj[i]);
        }
        else if(obj[i]->get_tag()=="npc")
        {
            hasNPC=true;
        }
        else if(obj[i]->get_tag()=="item")
        {
            hasItem=true;
        }

    }

    char opt;
    for(int i=0; i<50; i++)
    {
        cout<<"=";
    }

    cout<<endl<<"You have these options.\n"<<endl;
    cout<<"(A)Attack the monster.\n";
    cout<<"(P)Pick up the item.\n";
    cout<<"(T)Talk to the NPC.\n";
    cout<<"(I)Indicate our status.\n";
    cout<<"(M)Move to next room.\n";
    cout<<"(E)Exit and save the file\n";
    for(int i=0; i<50; i++)
    {
        cout<<"=";
    }
    cout<<endl<<endl;
    cout<<"Please enter your option."<<endl;
    cin>>opt;

    opt=toupper(opt);

    if((opt!='A')&&(opt!='P')&&(opt!='T')&&(opt!='I')&&(opt!='M')&&(opt!='E'))
    {
        cout<<endl<<"Wrong input.Please input again."<<endl;
        listOption();
    }

    else if(opt=='A')
    {
        if(hasMonster)
        {
            cout<<endl<<"You encounter a giant. Please choose an action."<<endl;
            cout<<endl<<"(A)attack"<<endl;
            cout<<endl<<"(B)retreat"<<endl;

            char opt;
            while(1)
            {
                cin>>opt;
                opt=toupper(opt);
                if(opt=='A'||opt=='B')
                {
                    break;
                }
            }

            if(opt=='B')
            {
                handleRetreat();
            }
            else if(opt=='A')
            {
                if(mt->triggerEvent(&player))
                {
                    nr->clearObject(mt);
                    win=true;
                }
                else
                {

                }
            }


        }
        else
        {
            cout<<endl<<"This room has no monster.Please choose again."<<endl;
            listOption();
        }
    }
    else if(opt=='P')
    {
        if(hasItem)
        {
            Item* it;
            string itemName;
            cout<<endl<<"Which item do you want?"<<endl;
            cin>>itemName;
            for(int i=0; i<obj.size(); i++)
            {
                if(obj[i]->get_name()==itemName)
                {
                    it=dynamic_cast<Item*>(obj[i]);
                    break;
                }
            }
            if(it->triggerEvent(&player))
            {
                nr->clearObject(it);
            }
        }
        else
        {
            cout<<endl<<"This room has no item.Please choose again."<<endl;
            listOption();
        }
    }
    else if(opt=='T')
    {
        if(hasNPC)
        {
            NPC* np;
            string npcName;
            cout<<endl<<"Which npc do you want to talk?"<<endl;
            cin>>npcName;
            npcName[0]=toupper(npcName[0]);
            for(int i=0; i<obj.size(); i++)
            {
                if(obj[i]->get_name()==npcName)
                {
                    np=dynamic_cast<NPC*>(obj[i]);
                    break;
                }
            }
            if(np->triggerEvent(&player)) {}
        }
        else
        {
            cout<<endl<<"This room has no npc.Please choose again."<<endl;
            listOption();
        }
    }
    else if(opt=='I')
    {
        player.triggerEvent(&player);
    }
    else if(opt=='M')
    {
        listMoveMent();
        handleMovement();
    }
    else if(opt=='E')
    {
        player.psaveRecord();
        isaveRecord();
        nsaveRecord();
        msaveRecord();
        cout<<endl<<"Goodbye!"<<endl;
        exit(0);
    }

}


void Dungeon::listMoveMent()
{

    Room* nr=player.getCurrentRoom();

    cout<<"\nChoose your next direction.\n\n";

    if(nr->getUpRoom()!=NULL)
    {
        cout<<"U:up\n\n";
    }
    if(nr->getDownRoom()!=NULL)
    {
        cout<<"D:down\n\n";
    }
    if(nr->getLeftRoom()!=NULL)
    {
        cout<<"L:left\n\n";
    }
    if(nr->getRightRoom()!=NULL)
    {
        cout<<"R:right\n\n";
    }

    cout<<"======================================================\n\n";

    cout<<"Please enter your option:"<<endl;

}
void Dungeon::handleMovement()
{
    Room* nr=player.getCurrentRoom();

    set<char> options;

    if(nr->getUpRoom()!=NULL)
    {
        options.insert('U');
    }
    if(nr->getDownRoom()!=NULL)
    {
        options.insert('D');
    }
    if(nr->getLeftRoom()!=NULL)
    {
        options.insert('L');
    }
    if(nr->getRightRoom()!=NULL)
    {
        options.insert('R');
    }

    player.setPreviousRoom(player.getCurrentRoom());

    char opt;
    cin>>opt;
    opt=toupper(opt);
    while(options.find(opt)==options.end())
    {
        cout<<"Wrong input, please enter again."<<endl;
        cin>>opt;
        opt=toupper(opt);
    }
    if(opt=='U')
    {
        player.setCurrentRoom(player.getCurrentRoom()->getUpRoom());
    }
    else if(opt=='D')
    {
        player.setCurrentRoom(player.getCurrentRoom()->getDownRoom());
    }
    else if(opt=='L')
    {
        player.setCurrentRoom(player.getCurrentRoom()->getLeftRoom());
    }
    else if(opt=='R')
    {
        player.setCurrentRoom(player.getCurrentRoom()->getRightRoom());
    }
}
bool Dungeon::checkGameLogic()
{

    if(player.checkIsDead())
    {
        win=false;
        return false;
    }
    else if(win==true)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool isAcorrectOption(char opt)
{
    if(opt=='U'||opt=='D'||opt=='L'||opt=='R')
        return true;
    else
        return false;
}

void Dungeon::isaveRecord()
{
    ofstream outItem;
    outItem.open("itemRecord.txt");
    outItem<<"A";

    int total=0;
    for(int i=0; i<rooms.size(); i++)
    {
        vector<Object*> obj=rooms[i].getObject();
        for(int j=0; j<obj.size(); j++)
        {
            if(obj[j]->get_tag()=="item")
            {
                total++;
            }
        }
    }

    outItem<<total<<" ";
    for(int i=0; i<rooms.size(); i++)
    {
        vector<Object*> obj=rooms[i].getObject();
        for(int j=0; j<obj.size(); j++)
        {
            if(obj[j]->get_tag()=="item")
            {
                outItem<<i<<" ";
            }
        }
    }
}

void Dungeon::msaveRecord()
{
    ofstream outMonster;
    outMonster.open("monsterRecord.txt");

    vector<Object*> obj=rooms[9].getObject();

    if(obj.size())
    {
        Monster* mon=dynamic_cast<Monster*>(obj[0]);
        outMonster<<mon->get_name()<<" "<<mon->get_maxHealth()<<" "<<mon->get_currentHealth()
                  <<" "<<mon->get_attack()<<" "<<mon->get_defense();
    }


}

void Dungeon::nsaveRecord()
{
    ofstream outNPC;
    outNPC.open("npcRecord.txt");

    for(int i=0; i<rooms.size(); i++)
    {
        vector<Object*> obj=rooms[i].getObject();
        for(int j=0; j<obj.size(); j++)
        {
            if(obj[j]->get_tag()=="npc")
            {
                NPC* np=dynamic_cast<NPC*>(obj[j]);
                outNPC<<i<<" "<<obj[j]->get_name()<<" ";

                if(np->getCommodity().size())
                {
                    outNPC<<np->getCommodity()[0].get_name()<<" ";
                }
                else
                {
                    outNPC<<"noitem"<<" ";
                }

            }

        }

    }
}




void Dungeon::handleRetreat()
{
    cout<<endl<<"You want to retreat? Ok"<<endl;
    cout<<endl<<"But you can only retreat to the previous room"<<endl;
    player.setCurrentRoom(player.getPreviousRoom());
}
bool Dungeon::handleEvent(Object*)
{
    return true;
}
bool Dungeon::checkMonsterRoom(vector<Object*>)
{
    return true;
}
void Dungeon::chooseAction(vector<Object*>)
{

}

void Dungeon::setkey()
{
    key.push_back(Item("key",100,100,100));

}

void Dungeon::setGiants()
{
    giants.push_back(Monster("big_giant",500,100,40));
    giants.push_back(Monster("armor_giant",500,100,40));
    giants.push_back(Monster("female_giant",500,100,40));
    giants.push_back(Monster("attack_giant",500,100,40));
    giants.push_back(Monster("monkey_giant",500,100,40));
    giants.push_back(Monster("bite_giant",500,100,40));
    giants.push_back(Monster("vehicle_giant",500,100,40));
    giants.push_back(Monster("original_giant",500,100,40));
    giants.push_back(Monster("hammer_giant",500,100,40));
}
void Dungeon::setNPC()
{
    vector<Item> Livi_commodity;
    vector<Item> Mikasa_commodity;
    vector<Item> Armin_commodity;
    Livi_commodity.push_back(Item("Akaman_blood",10,10,10));
    Mikasa_commodity.push_back(Item("scarf",10,10,10));
    Armin_commodity.push_back(Item("gold_hair",10,10,10));
    people.push_back(NPC("Livi","Which item do you want?",Livi_commodity));
    people.push_back(NPC("Mikasa","Which item do you want?",Mikasa_commodity));
    people.push_back(NPC("Armin","Which item do you want?",Armin_commodity));
}

///////////////////////////////////////////getter setter
Player Dungeon::getPlayer()
{
    return player;
}
vector<Room> Dungeon::getRoom()
{
    return rooms;
}

void Dungeon::setPlayer(Player p)
{
    player=p;
}

void Dungeon::setRoom(Room* r)
{

}

