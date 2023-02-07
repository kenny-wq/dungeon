#include "../headers/Player.h"

Player::Player()
{}
Player::Player(string name_value,int maxHealth_value,int attack_value,int defense_value)
:Gamecharacter(name_value,"player",maxHealth_value,attack_value,defense_value)
{}

Player::Player(string nam,int ma,int curr,int atta,int def,vector<Item> inv)
:Gamecharacter(nam,"player",ma,curr,atta,def),inventory(inv)
{

}


void Player::addItem(Item thing)
{
	inventory.push_back(thing);
}
void Player::printInventory()
{
    cout<<endl;
    for(int i=0;i<inventory.size();i++){
        cout<<inventory[i].get_name()<<" ";
    }
    cout<<endl<<endl;
}
void Player::increaseStates(int add_blood,int add_attack,int add_defense)
{
	this->set_currentHealth(get_currentHealth()+add_blood);
    this->set_attack(get_attack()+add_attack);
	this->set_defense(get_defense()+add_defense);
}
void Player::lootRoom(Room* ro)
{
    currentRoom=ro;
    previousRoom=NULL;
}
void Player::changeRoom(Room* ro)
{
    previousRoom=currentRoom;
    currentRoom=ro;

}
bool Player::triggerEvent(Object* obj)
{
    Player* pla=dynamic_cast<Player*>(obj);
    vector<Item> bag=pla->getInventory();
    cout<<endl<<"Your status:"<<endl;
    cout<<endl<<"health: "<<pla->get_currentHealth()<<endl;
    cout<<endl<<"attack: "<<pla->get_attack()<<endl;
    cout<<endl<<"defense: "<<pla->get_defense()<<endl;
    cout<<endl<<"Your bag has:"<<endl;
    pla->printInventory();
    return true;
}


void Player::psaveRecord()
{


    ofstream outputStream;
    outputStream.open("playerRecord.txt");
    if(!outputStream.good()){
        cout<<"fail"<<endl;
        exit(0);
    }

    Room* nr=getCurrentRoom();
    Room* ur=nr->getUpRoom();
    Room* dr=nr->getDownRoom();
    Room* lr=nr->getLeftRoom();
    Room* rr=nr->getRightRoom();

    outputStream<<"A"<<get_name()<<" "<<get_maxHealth()
    <<" "<<get_currentHealth()<<" "<<get_attack()<<" "<<get_defense()<<" "<<nr->getIndex()
    <<" "<<getPreviousRoom()->getIndex()<<" "<<inventory.size()<<endl;

    for(int i=0;i<inventory.size();i++){
        outputStream<<inventory[i].get_name()
        <<" "<<inventory[i].get_health()<<" "<<inventory[i].get_attack()<<" "<<inventory[i].get_defense()<<endl;
    }



}

////////////////////////////////////////////////////////////////////////////setter
void Player::setCurrentRoom(Room* croom)
{
	currentRoom= croom;
}
void Player::setPreviousRoom(Room* proom)
{
	previousRoom=proom;
}
void Player::setInventory(Item it)
{
	inventory.push_back(it);
}
////////////////////////////////////////////////////////////////////////////setter

/////////////////////////////////////////////////////////////////////////////getter
Room* Player::getPreviousRoom()
{
	return previousRoom;
}
Room* Player::getCurrentRoom()
{
	return currentRoom;
}
vector<Item> Player::getInventory()
{
	return inventory;
}
//////////////////////////////////////////////////////////////////////////////getter
int Player::vgetHealth()
{
    return get_currentHealth();
}
int Player::vgetAttack()
{
    return get_attack();
}
int Player::vgetDefense()
{
    return get_defense();
}


