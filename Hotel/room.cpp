#include "room.h"

Room::Room(int roomNumber, int numOfBeds, int size) throw(const char *)
{
	setRoomNumber(roomNumber);
	setNumOfBeds(numOfBeds);
	setSize(size);
	numberOfGuests = INIT_NUM_GUEST;
}

Room::Room(const Room & other)
{
	*this = other;
}

Room::~Room()
{	
}

const Room & Room::operator=(const Room & other)
{
	if (this != &other)
	{
		Room::roomNumber = other.roomNumber;
		Room::numOfBeds = other.numOfBeds;
		Room::size = other.size;
		Room::guests = other.guests;
		Room::numberOfGuests = other.numberOfGuests;
	}
	return *this;
}

void Room::toOs(std::ostream & os) const {}

void Room::decorateRoom() const
{
	cout << "\n *.** Chocolates are waiting in your room **.* \n";
}

const Room & Room::operator+=(const Person & person)
{
	guests += person;
	numberOfGuests++;
	return *this;
}

void Room::initArray()
{
}

void Room::setRoomNumber(int roomNumber) throw(const char *)
{
	if (roomNumber > 0)
		Room::roomNumber = roomNumber;
	else
		throw "Room number is Invalid.\n";
}

void Room::setNumOfBeds(int numOfBeds) throw(const char *)
{
	if ((numOfBeds >= MIN_NUM_OF_BEDS) && (numOfBeds <= MAX_NUM_OF_BEDS))
		Room::numOfBeds = numOfBeds;
	else
		throw "There are only rooms with 1-6 beds in this hotel.\n";
}

void Room::setSize(int size) throw(const char *)
{
	if ((size >= MIN_ROOM_SIZE) && (size <= MAX_ROOM_SIZE))
		Room::size = size;
	else
		throw "The rooms in this hotel are at the range of 50-200 square meter.\n";
}

const LinkedList<Person>& Room::getGuests() const
{
	return guests;
}

int Room::getNumberOfGuests() const
{
	return numberOfGuests;
}

int Room::getRoomNumber() const
{
	return roomNumber;
}

int Room::getNumOfBeds() const
{
	return numOfBeds;
}

int Room::getSize() const
{
	return size;
}

int Room::isGuestExist(const Person& guest)
{
	// if there are guests
	if (guests.isExists(guest))
		return roomNumber;
	return GUEST_NOT_EXIST;
}

void Room::checkInGuest(const Person & guest)
{
	*this += guest;
}

void Room::checkOutGuests(int roomNumber)
{
	guests.deleteAll();
	numberOfGuests = INIT_NUM_GUEST;
}

Room Room::operator++(int)
{
	numberOfGuests++;
	return *this;
}

std::ostream & operator<<(std::ostream & os, const Room & e)
{
	os << "Room number: " << e.roomNumber << "\n";
	os << "Number of beds: " << e.numOfBeds << "\n";
	os << "Number of guests: " << e.numberOfGuests << "\n";
	os << "Room size: " << e.size << "\n";
	if (typeid(e).name() == typeid(Room).name())
	os << "Room type: Normal \n";
	e.toOs(os);
	if (e.numberOfGuests > 0)
	{
		os << "Guests: \n";
		os << e.guests;
	}
	else
		os << "Room has no guests \n";
	return os;
}
