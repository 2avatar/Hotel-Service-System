#include "RoomForBirthday.h"

RoomForBirthday::RoomForBirthday(Decorateable * theDecorate, int cakeDiamater) : RoomProperty(theDecorate), cakeDiamater(cakeDiamater)
{
}

void RoomForBirthday::decorateRoom() const
{
	RoomProperty::decorateRoom();
	cout << "Cake in the size of " << cakeDiamater << " is waiting in your room \n";
}
