#include "Monster.h"

Monster::Monster() {}

Monster::Monster(string name_value,int maxHealth_value,int attack_value,int defense_value)
    :Gamecharacter(name_value,"monster",maxHealth_value,attack_value,defense_value)
{}
bool Monster::triggerEvent(Object* o)
{
    Player* plr=dynamic_cast<Player*> (o);
    if(plr==NULL)
    {
        return false;
    }
    cout<<"You encounter a monster. ";
	char opt;
	int success=0;
	while(!success)
	{

		cout<<"Please choose an action.\n";
		cout<<"(A)run away\n(B)battle\n";
		cout<<"Enter your option here:";
		cin>>opt;

		if(opt=='A')
		{
			cout<<"run";
			success=1;
		}
		else if(opt=='B')
		{
			cout<<"battle";
			success=1;
		}
		else
		{
			cout<<"Wrong input! Please enter again.\n";
		}
	}


}































