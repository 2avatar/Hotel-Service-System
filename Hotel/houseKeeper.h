#pragma once
#ifndef __HOUSE_KEEPER_H
#define __HOUSE_KEEPER_H
#include "employee.h"

class HouseKeeper : public Employee
{
private:
	HouseKeeper(const HouseKeeper& other);
	const HouseKeeper& operator= (const HouseKeeper& other);

public:
	HouseKeeper(const char* name, float salary) throw (const char*);
	void toOs(std::ostream& os) const;

	void cleanRoom(int roomNumber) const throw (const char*);
	void cleanAllRooms() const;
};

#endif //__HOUSE_KEEPER_H