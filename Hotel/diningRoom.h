#pragma once
#ifndef __DINING_ROOM_H
#define __DINING_ROOM_H
#include "person.h"

class DiningRoom
{
public:
	enum Status { OPEN, CLOSE };
	const static char* eStatus[];

private:
	int numOfTables;
	int numOfChairs;
	int* roomsRegistered; // array that will keep the room numbers whick registered to the meals
	Status status;
	int numOfRegisteredRooms; //keep the number of current room registered
public:

	static const int INIT_SIZE = 0;
	static const int MIN_NUM_SIZE = 0;

	DiningRoom(int numOfTables, int numOfChairs) throw (const char*);
	~DiningRoom();
	DiningRoom(const DiningRoom& other);
	const DiningRoom& operator= (const DiningRoom& other);
	friend std::ostream& operator<< (std::ostream& os, const DiningRoom& e);

	//getters and setters
	void setNumOfTables(int numOfTables) throw (const char*);
	void setNumOfChairs(int numOfChairs) throw (const char*);

	int getNumOfTables() const;
	int getNumOfChairs() const;
	
	//add the coppied room number to the roomRegistered array.
	const DiningRoom& operator+= (int roomNumber);

	//remove the coppied room number to the roomRegistered array.
	const DiningRoom& operator-= (int roomNumber);

	void openGates(); // the guests can enter the dining room now
	void closeGates();
};

#endif  // __DINING_ROOM_H