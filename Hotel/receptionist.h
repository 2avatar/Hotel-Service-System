#pragma once
#ifndef __RECEPTIONIST_H
#define __RECEPTIONIST_H
#include "employee.h"
#include "person.h"
#include "room.h"

class Receptionist : virtual public Employee
{	
protected:	
	Receptionist(const Receptionist& other);
	const Receptionist& operator= (const Receptionist& other);

public:

	static const int NUM_OF_FLOORS = 6;
	static const int NUM_OF_ROOMS_PER_FLOOR = 8;
	static const int NO_ROOM_AVAILBLE = 0;

	Receptionist(const char* name, float salary) throw (const char*);
	virtual void toOs(std::ostream& os) const;

	virtual int checkRoomAvailability(int numberOfGuests, Room** rooms) throw (const char*); // return the matching room for this size of guests
	virtual void collectPayment(int roomNumber, float amount) throw (const char*);
};

#endif //__RECEPTIONIST_H