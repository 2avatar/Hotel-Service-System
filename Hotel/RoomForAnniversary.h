#pragma once
#ifndef __ROOM_FOR_ANNIVERSARY_H
#define __ROOM_FOR_ANNIVERSARY_H
#include "RoomProperty.h"
class RoomForAnniversary : public RoomProperty 
{
	int numOfBaloons;
public:
	RoomForAnniversary(Decorateable* theDecorate, int numOfBaloons);
	virtual void decorateRoom() const;
};
#endif // __ROOM_FOR_ANNIVERSARY_H
