#pragma once
#ifndef __ROOM_H
#define __ROOM_H
#include <iostream>
#include "person.h"



class Room
{
protected:
	int roomNumber;
	int numOfBeds;
	int numberOfGuests;
	int size;
	const Person** guests;

public:

	static const int INIT_NUM_GUEST = 0;
	static const int MIN_NUM_OF_BEDS = 1;
	static const int MAX_NUM_OF_BEDS = 8;
	static const int MIN_ROOM_SIZE = 50;
	static const int MAX_ROOM_SIZE = 200;
	static const int GUEST_NOT_EXIST = 0;

	Room(int roomNumber, int numOfBeds, int size) throw (const char*);
	Room(const Room& other);
	virtual ~Room();
	const Room& operator= (const Room& other);
	friend std::ostream& operator<< (std::ostream& os, const Room& e);
	virtual void toOs(std::ostream& os) const;

	const Room& operator+=(const Person& person);// an operator for adding an guest to the guests array

	void initArray();
	void setRoomNumber(int roomNumber) throw (const char*);
	void setNumOfBeds(int numOfBeds) throw (const char*);
	void setSize(int size) throw (const char*);
	const Person** getGuests() const;
	int getNumberOfGuests() const;
	int getRoomNumber() const;
	int getNumOfBeds() const;
	int getSize() const;

	int isGuestExist(int id) const; // return the room number if the guest exist. else -> zero
	void checkInGuest(const Person& guest);
	void checkOutGuests(int roomNumber); // check out the guests of specific room 

	Room operator++(int); // increase number of guests (postfix)

	const Person& operator[](int index) const throw (const char*); 	// return guest at index i from array
};

#endif  //__ROOM_H