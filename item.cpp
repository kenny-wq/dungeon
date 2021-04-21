
#include "item.h"

Item::Item() :Object("","item")
{}
Item::Item(string name) :Object(name,"item")
{

}
Item::Item(string name_value,int health_value ,int attack_value,int defense_value)
:Object(name_value,"item")
{
    health=health_value;
    attack=attack_value;
    defense=defense_value;
}
bool operator ==(Item a,Item b)
{
    if((a.health==b.health)&&(a.attack==b.attack)&&(a.defense==b.defense)){
        return true;
    }
    else{
        return false;
    }
}
bool Item::triggerEvent(Object*){return true;}
void Item::set_health(int health_value)
{
    health=health_value;
}
void Item::set_attack(int attack_value)
{
    attack=attack_value;
}
void Item::set_defense(int defense_value)
{
	defense=defense_value;
}
int Item::get_health()
{
	return health;
}
int Item::get_attack()
{
	return attack;
}
int Item::get_defense()
{
	return defense;
}
