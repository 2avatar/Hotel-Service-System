#include "RoomProperty.h"

RoomProperty::RoomProperty(Decorateable * theDecorate) : theDecorate(theDecorate)
{
}

void RoomProperty::decorateRoom() const
{
	theDecorate->decorateRoom();
}
