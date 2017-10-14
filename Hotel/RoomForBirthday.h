#pragma once
#ifndef __ROOM_FOR_BIRTHDAY_H
#define __ROOM_FOR_BIRTHDAY_H
#include "RoomProperty.h"
class RoomForBirthday : public RoomProperty
{
	int cakeDiamater;
public:
	RoomForBirthday(Decorateable* theDecorate, int cakeDiamater);
	virtual void decorateRoom() const;
};
#endif // __ROOM_FOR_BIRTHDAY_H