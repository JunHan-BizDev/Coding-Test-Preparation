// The following definitions go into file ItemType.cpp. #include <fstream>#include <iostream>#include "ItemType.h"ItemType2::ItemType2(){   value = 0;}RelationType ItemType2::ComparedTo(ItemType2 otherItem) const{  if (value < otherItem.value)    return LESS;  else if (value > otherItem.value)    return GREATER;  else return EQUAL;}void ItemType2::Initialize(int number){  value = number;}void ItemType2::Print(std::ostream& out) const // pre:  out has been opened.// post: value has been sent to the stream out.{  out << value;}int ItemType2::getvalue(){    return this->value;}