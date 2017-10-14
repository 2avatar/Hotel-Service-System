#pragma once
#ifndef __ROOM_SERVICE_H
#define __ROOM_SERVICE_H
#include "employee.h"
class RoomService : virtual public Employee
{
protected:
	RoomService(const RoomService& other);
	const RoomService& operator= (const RoomService& other);

public:
	RoomService(const char* name, float salary);
	virtual void toOs(std::ostream& os) const;

	virtual void serveRoom(int roomNumber) const throw (const char*);
};

#endif //__ROOM_SERVICE_H