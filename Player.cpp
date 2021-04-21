#include "Player.h"

Player::Player()
{}
Player::Player(string name_value,int maxHealth_value,int attack_value,int defense_value)
:Gamecharacter(name_value,"player",maxHealth_value,attack_value,defense_value)
{}

////////////////////////////////////////////////////////////////////////////setter
void Player::setCurrentRoom(Room* croom)
{
	currentRoom= croom;
}
void Player::setPreviousRoom(Room* proom)
{
	previousRoom=proom;
}
void Player::setInventory(vector<Item> inv)
{
	inventory=inv;
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
void Player::addItem(Item thing)
{
	inventory.push_back(thing);
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
bool Player::triggerEvent(Object*)
{

}



























