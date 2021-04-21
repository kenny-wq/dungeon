#include "Dungeon.h"

Dungeon::Dungeon(){}

void Dungeon::startGame()
{



    cout<<"Initialize map file...\n"<<endl;
    //Sleep(1000);
    createMap();

    cout<<"Initialize player file...\n"<<endl;
    //Sleep(1000);
    createPlayer();

    cout<<"Hello Alan,welcome to my Dungeon!\n"<<endl;
    //Sleep(1000);

    cout<<"Please enjoy your trip.\n"<<endl;
    //Sleep(1000);

    runDungeon();
}

void Dungeon::runDungeon()
{
    while(checkGameLogic()){
        if(player.getCurrentRoom()->getIndex()==5){
            player.set_currentHealth(player.get_currentHealth()-110);
        }
        player.getCurrentRoom()->printRoomItem();
        listOption();
        char opt;

        cin>>opt;

        cout<<"\n\n";
        handleMovement(opt);
    }
    if(win){
        cout<<"\n\nYou win!Thanks for playing.\n\n\n";
    }
    else{
        cout<<"\n\nYou lose.Don't be depressive and play one more time.XD\n\n\n";
    }
}
void Dungeon::createPlayer()
{
    player=Player("Alan",100,50,50);
    player.setCurrentRoom(&rooms[0]);


    player.setPreviousRoom(NULL);


}



void Dungeon::createMap()
{
    ifstream instream;

    instream.open("map.txt");
    if (!instream.good()) {
		cout << "Map file loads failed\n";
		exit(0);
	}

    int roomNum;
    instream>>roomNum;

    for(int i=0;i<roomNum;i++){
        rooms.push_back(Room());
        rooms[i].setIndex(i);
    }
    //6-7-8-9
    //| | |
    //5-4-3
    //| | |
    //0-1-2
    int x;
    for(int i=0;i<roomNum;i++){
        instream>>x;
        if(x!=-1){
            rooms[i].setUpRoom(&rooms[x]);
        }
        instream>>x;
        if(x!=-1){
            rooms[i].setDownRoom(&rooms[x]);
        }
        instream>>x;
        if(x!=-1){
            rooms[i].setLeftRoom(&rooms[x]);
        }
        instream>>x;
        if(x!=-1){
            rooms[i].setRightRoom(&rooms[x]);
        }

    }

    setFruits();
    setGiants();
    setNPC();

    for(int i=0;i<roomNum-1;i+=3){
        rooms[i].putItem(&fruits[rand()%5]);
        rooms[i].putItem(&giants[8]);
        rooms[i].putItem(&people[rand()%6]);
    }


    instream.close();

}
void Dungeon::listOption()
{

    Room* nr=player.getCurrentRoom();

    cout<<"\nAnd you have these options.\n\n";

    if(nr->getUpRoom()!=NULL){
        cout<<"U:up\n\n";
    }
    if(nr->getDownRoom()!=NULL){
        cout<<"D:down\n\n";
    }
    if(nr->getLeftRoom()!=NULL){
        cout<<"L:left\n\n";
    }
    if(nr->getRightRoom()!=NULL){
        cout<<"R:right\n\n";
    }

    cout<<"======================================================\n\n";

    cout<<"Please enter your option:";

}
void Dungeon::handleMovement(char opt)
{
    Room* nr=player.getCurrentRoom();
    player.setPreviousRoom(player.getCurrentRoom());
    if(opt=='U'){
        player.setCurrentRoom(player.getCurrentRoom()->getUpRoom());
    }
    else if(opt=='D'){
        player.setCurrentRoom(player.getCurrentRoom()->getDownRoom());
    }
    else if(opt=='L'){
        player.setCurrentRoom(player.getCurrentRoom()->getLeftRoom());
    }
    else if(opt=='R'){
        player.setCurrentRoom(player.getCurrentRoom()->getRightRoom());
    }


}
bool Dungeon::checkGameLogic()
{
    if(player.checkIsDead()){
        win=false;
        return false;
    }
    else if(player.getCurrentRoom()->getIndex()==9){
        win=true;
        return false;
    }
    else{
        return true;
    }
}
void Dungeon::setFruits()
{
    fruits.push_back(Item("apple"));
    fruits.push_back(Item("lemon"));
    fruits.push_back(Item("banana"));
    fruits.push_back(Item("orange"));
    fruits.push_back(Item("strawberry"));
}

void Dungeon::setGiants()
{
    giants.push_back(Monster("big giant",100,50,40));
    giants.push_back(Monster("armor giant",100,50,40));
    giants.push_back(Monster("female giant",100,50,40));
    giants.push_back(Monster("attack giant",100,50,40));
    giants.push_back(Monster("monkey giant",100,50,40));
    giants.push_back(Monster("bite giant",100,50,40));
    giants.push_back(Monster("vehicle giant",100,50,40));
    giants.push_back(Monster("original giant",100,50,40));
}
void Dungeon::setNPC()
{
    people.push_back(NPC("Livi"));
    people.push_back(NPC("Mikasa"));
    people.push_back(NPC("Armin"));
    people.push_back(NPC("Laina"));
    people.push_back(NPC("Gic"));
    people.push_back(NPC("Gabi"));

}
bool Dungeon::handleRetreat()
{

}
bool Dungeon::handleEvent(Object*)
{

}
bool Dungeon::checkMonsterRoom(vector<Object*>)
{

}
void Dungeon::chooseAction(vector<Object*>)
{

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




























