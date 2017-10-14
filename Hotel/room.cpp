#include "room.h"

Room::Room(int roomNumber, int numOfBeds, int size) throw(const char *)
{
	setRoomNumber(roomNumber);
	setNumOfBeds(numOfBeds);
	setSize(size);
	numberOfGuests = INIT_NUM_GUEST;
	guests = new const Person*[numOfBeds];
}

Room::Room(const Room & other)
{
	*this = other;
}

Room::~Room()
{
	for (int i = 0; i < numberOfGuests; i++)
		delete[] guests[i];

	delete[] guests;
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

const Room & Room::operator+=(const Person & person)
{

	if (numberOfGuests <= numOfBeds) {
		guests[numberOfGuests] = &person;
		++numberOfGuests;
	}
	return *this;
}

void Room::initArray()
{
	for (int i = 0; i < numOfBeds; i++)
		guests[i] = nullptr;
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

const Person ** Room::getGuests() const
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

int Room::isGuestExist(int id) const
{
	// if there are guests
	if (numberOfGuests > 0) {
		for (int i = 0; i < numberOfGuests; i++)
		{
			if ((*guests[i]).getId() == id)
				return roomNumber;
		}
	}
	return GUEST_NOT_EXIST;
}

void Room::checkInGuest(const Person & guest)
{
	*this += guest;
}

void Room::checkOutGuests(int roomNumber)
{
	for (int i = 0; i < numberOfGuests; i++)
		guests[i] = nullptr;
	numberOfGuests = INIT_NUM_GUEST;
}

Room Room::operator++(int)
{
	numberOfGuests++;
	return *this;
}

const Person & Room::operator[](int index) const throw(const char *)
{ 
	if ((index >= 0) && (index < numberOfGuests))
		return (*guests[index]);
	else
		throw "Invalid index.\n";
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
		for (int i=0; i<e.getNumberOfGuests(); i++)
		os << *e.getGuests()[i];
	}
	else
		os << "Room has no guests \n";
	return os;
}
