#include "diningRoom.h"

const string DiningRoom::eStatus[] = { "Open", "Close" };

DiningRoom::DiningRoom(int numOfTables, int numOfChairs) throw(const char *)
{
	setNumOfTables(numOfTables);
	setNumOfChairs(numOfChairs);
	DiningRoom::status = CLOSE;
}

void DiningRoom::setNumOfTables(int numOfTables) throw(const char *)
{
	if (numOfTables > MIN_NUM_SIZE)
		DiningRoom::numOfTables = numOfTables;
	else
		throw "Invalid number of tables";
}

void DiningRoom::setNumOfChairs(int numOfChairs) throw(const char *)
{
	if (numOfChairs > MIN_NUM_SIZE)
		DiningRoom::numOfChairs = numOfChairs;
	else
		throw "Invalid number of chairs";
}

int DiningRoom::getNumOfTables() const
{
	return numOfTables;
}

int DiningRoom::getNumOfChairs() const
{
	return numOfChairs;
}

const DiningRoom & DiningRoom::operator+=(int roomNumber)
{
	roomsRegistered.push_back(roomNumber);

	return *this;
}

const DiningRoom & DiningRoom::operator-=(int roomNumber)
{
	vector<int>::iterator itrBegin = roomsRegistered.begin();
	vector<int>::iterator itrEnd = roomsRegistered.end();
	for (; itrBegin != itrEnd; ++itrBegin) 
	{
		if (*itrBegin == roomNumber)
		{
			roomsRegistered.erase(itrBegin);
			break;
		}
	}

	return *this;
}

void DiningRoom::openGates()
{
	DiningRoom::status = OPEN;
}

void DiningRoom::closeGates()
{
	DiningRoom::status = CLOSE;
	roomsRegistered.clear();
}

std::ostream & operator<<(std::ostream & os, const DiningRoom & e)
{
	vector<int>::const_iterator itrBegin = e.roomsRegistered.begin();
	vector<int>::const_iterator itrEnd = e.roomsRegistered.end();

	os << "Number of Chairs: " << e.numOfChairs << "\n";
	os << "Number of Tables: " << e.numOfTables << "\n";
	os << "Status: " << e.eStatus[e.status] << "\n";
	if (e.roomsRegistered.size() == e.INIT_SIZE)
		os << "No Current Rooms Registered \n";
	else
	{
	os << "Rooms Registered: \n";
	for ( ; itrBegin != itrEnd ; ++itrBegin)
	{
		os << "Room Number: " << *itrBegin << "\n";
	}
	}
	return os;
}
