#include <iostream>
#include "../headers/object.h"

using namespace std;

Object::Object() {}
Object::Object(string name_value,string tag_value)
{
    name=name_value;
    tag=tag_value;
}



string Object::get_name()
{
    return name;
}

string Object::get_tag()
{
    return tag;
}
void Object::set_name(string name_value)
{
    name=name_value;
}
void Object::set_tag(string tag_value)
{
    tag=tag_value;
}
