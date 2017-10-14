#pragma once
#ifndef __SHIFT_MANAGER_H
#define __SHIFT_MANAGER_H
#include "employee.h"
#include "receptionist.h"
#include "room.h"
#include "roomService.h"
class ShiftManager : public Receptionist, public RoomService
{
private:
	ShiftManager(const ShiftManager& other);
	const ShiftManager& operator= (const ShiftManager& other);
	
public:
	ShiftManager(const char* name, float salary) throw (const char*);

	void toOs(std::ostream& os) const;

	void handleComplaint(int roomNumber, const char* complaint) const throw (const char*);

};

#endif //__SHIFT_MANAGER_H