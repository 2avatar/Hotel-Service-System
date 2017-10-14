#pragma once
#ifndef __ROOM_H
#define __ROOM_H
#include <iostream>
#include "person.h"
#include "LinkedList.h"
#include "Decorateable.h"

class Room : public Decorateable
{
protected:
	int roomNumber;
	int numOfBeds;
	int numberOfGuests;
	int size;
	LinkedList<Person> guests = LinkedList<Person>();

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
	virtual void decorateRoom() const;
	const Room& operator+=(const Person& person);// an operator for adding an guest to the guests array

	void initArray();
	void setRoomNumber(int roomNumber) throw (const char*);
	void setNumOfBeds(int numOfBeds) throw (const char*);
	void setSize(int size) throw (const char*);
	const LinkedList<Person>& getGuests() const;
	int getNumberOfGuests() const;
	int getRoomNumber() const;
	int getNumOfBeds() const;
	int getSize() const;

	int isGuestExist(const Person& guests); // return the room number if the guest exist. else -> zero
	void checkInGuest(const Person& guest);
	void checkOutGuests(int roomNumber); // check out the guests of specific room 

	Room operator++(int); // increase number of guests (postfix)

};

#endif  //__ROOM_H