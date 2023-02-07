#include "../headers/Monster.h"

Monster::Monster() {}

Monster::Monster(string name_value,int maxHealth_value,int attack_value,int defense_value)
    :Gamecharacter(name_value,"monster",maxHealth_value,attack_value,defense_value)
{}
Monster::Monster(string nam,int maxH,int currH,int att,int def)
    :Gamecharacter(nam,"monster",maxH,currH,att,def)
{

}
bool Monster::triggerEvent(Object* o)
{
    Player* plr=dynamic_cast<Player*> (o);

    int mattack=get_attack();
    int mdefense=get_defense();

    int pattack=plr->get_attack();
    int pdefense=plr->get_defense();

    if((pattack-mdefense)>=0)    //ª±®a§ðÀ»©Çª«
    {
        cout<<endl<<"You cause "<<pattack-mdefense<<" point harm to "<<get_name()<<endl;
        set_currentHealth(get_currentHealth()-(pattack-mdefense));
    }
    else
    {
        cout<<endl<<"You cause "<<0<<" point harm to "<<get_name()<<endl;
    }

    if((mattack-pdefense)>=0)   //©Çª«§ðÀ»ª±®a
    {
        cout<<endl<<get_name()<<" cause "<<mattack-pdefense<<" point harm to you"<<endl;
        plr->set_currentHealth(plr->get_currentHealth()-(mattack-pdefense));
    }
    else
    {
        cout<<endl<<get_name()<<" cause "<<0<<" point harm to you"<<endl;
    }

    cout<<endl<<"Your health is "<<plr->get_currentHealth()<<endl;

    cout<<endl<<get_name()<<"'s health is "<<get_currentHealth()<<endl;

    if(get_currentHealth()<=0)
    {
        return true;
    }
    return false;

}


int Monster::vgetHealth()
{
    return get_currentHealth();
}
int Monster::vgetAttack()
{
    return get_attack();
}
int Monster::vgetDefense()
{
    return get_defense();
}

