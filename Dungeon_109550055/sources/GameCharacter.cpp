
#include "../headers/GameCharacter.h"


Gamecharacter::Gamecharacter()
{}
Gamecharacter::Gamecharacter(string name_value,string tag_value,int maxHealth_value,int attack_value,int defense_value)
:Object(name_value,tag_value)
{
	maxHealth=maxHealth_value;
	currentHealth=maxHealth_value;
	attack=attack_value;
	defense=defense_value;
}

Gamecharacter::Gamecharacter(string nam,string ta,int ma,int curr,int atta,int def)
:Object(nam,ta),maxHealth(ma),currentHealth(curr),attack(atta),defense(def)
{

}
bool Gamecharacter::checkIsDead()
{
	if(currentHealth<=0){
        return true;
	}
    else{
        return false;
    }
}
int Gamecharacter::takeDamage(int attac)
{
	int damage=attac-defense;
	if(damage>=0){
        currentHealth-=damage;
	    return damage;
	}
	else{
        return 0;
	}

}
int Gamecharacter::get_currentHealth()
{
	return currentHealth;
}
int Gamecharacter::get_maxHealth()
{
	return maxHealth;
}
int Gamecharacter::get_attack()
{
	return attack;
}
int Gamecharacter::get_defense()
{
	return defense;
}
void Gamecharacter::set_maxHealth(int maxHealth_value)
{
	maxHealth=maxHealth_value;
}
void Gamecharacter::set_currentHealth(int currentHealth_value)
{
	currentHealth=currentHealth_value;
}
void Gamecharacter::set_attack(int attack_value)
{
	attack=attack_value;
}
void Gamecharacter::set_defense(int defense_value)
{
	defense=defense_value;
}
