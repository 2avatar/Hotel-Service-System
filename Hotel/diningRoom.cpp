#include "diningRoom.h"
const char* DiningRoom::eStatus[] = { "Open", "Close" };

DiningRoom::DiningRoom(int numOfTables, int numOfChairs) throw(const char *)
{
	setNumOfTables(numOfTables);
	setNumOfChairs(numOfChairs);
	DiningRoom::status = CLOSE;
	DiningRoom::numOfRegisteredRooms = INIT_SIZE;
	DiningRoom::roomsRegistered = new int[numOfTables] {0};
}

DiningRoom::~DiningRoom()
{
	delete[] roomsRegistered;
}

DiningRoom::DiningRoom(const DiningRoom & other)
{
	*this = other;
}

const DiningRoom & DiningRoom::operator=(const DiningRoom & other)
{
	if (this != &other)
	{
		DiningRoom::numOfTables = other.numOfTables;
		DiningRoom::numOfChairs = other.numOfChairs;
		DiningRoom::status = other.status;
		DiningRoom::numOfRegisteredRooms = other.numOfRegisteredRooms;
		DiningRoom::roomsRegistered = new int[numOfTables];
		for (int i = 0; i < numOfRegisteredRooms; i++)
			DiningRoom::roomsRegistered[i] = other.roomsRegistered[i];
	}
	return *this;
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
	if (numOfRegisteredRooms < numOfTables)
	{
		for (int i = 0; i < numOfTables; i++)
		{
			if (roomsRegistered[i] == NULL) {
				roomsRegistered[i] = roomNumber;
				numOfRegisteredRooms++;
				break;
			}
		}
	}
	return *this;
}

const DiningRoom & DiningRoom::operator-=(int roomNumber)
{

	for (int i = 0; i < numOfTables; i++)
	{
		if (roomsRegistered[i] == roomNumber) {
			roomsRegistered[i] = NULL;
			numOfRegisteredRooms--;
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

	for (int i = 0; i < numOfTables; i++)
			roomsRegistered[i] = NULL;

	numOfRegisteredRooms = 0;
}

std::ostream & operator<<(std::ostream & os, const DiningRoom & e)
{
	os << "Number of chairs: " << e.numOfChairs << "\n";
	os << "Number of tables: " << e.numOfTables << "\n";
	os << "Status: " << e.eStatus[e.status] << "\n";
	os << "Rooms registered:\n";
	for (int i = 0; i < e.numOfRegisteredRooms; i++)
	{
		os << "Room number: " << e.roomsRegistered[i] << "\n";
	}
	return os;
}
