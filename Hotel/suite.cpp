#include "suite.h"

Suite::Suite(const Suite & other) : Room(other)
{
	*this = other;
}

const Suite& Suite::operator=(const Suite & other)
{
	if (this != &other)
	{
		balconySize = other.balconySize;
		Room::operator=(other);
	}
	return *this;
}

Suite::Suite(int roomNumber, int numOfBeds, int size, int balconySize) 
	: Room(roomNumber, numOfBeds, size)
{
	setBalconySize(balconySize);
}

void Suite::toOs(std::ostream & os) const
{
	os << "Balcony size: " << balconySize << "\n";
	os << "Room type: Suite \n";
}

void Suite::decorateRoom() const
{
	Room::decorateRoom();
	cout << "     &.&& Wine is waiting in your room &&.&\n";
}

void Suite::setBalconySize(int balconySize) throw(const char *)
{
	if ((balconySize >= MIN_BALCONY_SIZE) && (balconySize <= MAX_BALCONY_SIZE))
		Suite::balconySize = balconySize;
	else
		throw "The balconys in this hotel are at the range of 5-30 square meter.\n";
}

int Suite::getBalconySize() const
{
	return balconySize;
}
