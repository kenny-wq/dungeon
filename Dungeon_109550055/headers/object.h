#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
using namespace std;

class Object
{
public:
	Object();
	Object(string,string);
	virtual bool triggerEvent(Object*)=0;
	virtual int vgetHealth()=0;
	virtual int vgetAttack()=0;
	virtual int vgetDefense()=0;

	string get_name();
	string get_tag();
	void set_name(string name_value);
	void set_tag(string tag_value);
private:
	string name;
	string tag;
};
#endif // OBJECT_H
