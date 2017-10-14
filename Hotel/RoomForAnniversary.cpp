#include "RoomForAnniversary.h"

RoomForAnniversary::RoomForAnniversary(Decorateable * theDecorate, int numOfBaloons) : RoomProperty(theDecorate), numOfBaloons(numOfBaloons)
{
}

void RoomForAnniversary::decorateRoom() const
{
	RoomProperty::decorateRoom();
	cout << numOfBaloons << " Baloons are waiting in your room \n";
}
