#pragma once
#ifndef __ROOM_PROPERTY_H
#define __ROOM_PROPERTY_H
#include "Decorateable.h"
#include <iostream>
using namespace std;

class RoomProperty : public Decorateable
{
	Decorateable* theDecorate;
public:
	RoomProperty(Decorateable* theDecorate);
	virtual void decorateRoom() const;
};

#endif // __ROOM_PROPERTY_H