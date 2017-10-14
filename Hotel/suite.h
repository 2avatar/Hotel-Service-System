#pragma once
#ifndef __SUITE_H
#define __SUITE_H
#include "room.h"

class Suite : public Room
{
private:
	int balconySize;

public:

	static const int MIN_BALCONY_SIZE = 5;
	static const int MAX_BALCONY_SIZE = 30;

	Suite(const Suite& other);
	const Suite& operator= (const Suite& other);

	Suite(int roomNumber, int numOfBeds, int size, int balconySize);
	virtual void toOs(std::ostream& os) const;
	virtual void decorateRoom() const;
	void setBalconySize(int balconySize) throw (const char*);

	int getBalconySize() const;

};

#endif // __SUITE_H