#include "receptionist.h"

Receptionist::Receptionist(const Receptionist & other) : Employee(other)
{
	*this = other;
}

const Receptionist & Receptionist::operator=(const Receptionist & other)
{
	if (this != &other)
	{
		Employee::operator=(other);
	}
	return *this;
}

Receptionist::Receptionist(const char * name, float salary) throw(const char *) : Employee(name, salary)
{
}

void Receptionist::toOs(std::ostream & os) const
{
	os << "Salary: " << salary << "\n";
	os << "Title: Receptionist\n";
}

int Receptionist::checkRoomAvailability(int numberOfGuests, Room ** rooms) throw(const char *)
{
	if ((numberOfGuests <= 0) || (numberOfGuests > Room::MAX_NUM_OF_BEDS))
		throw "Invalid number of guests.\n";

	int numOfRooms = NUM_OF_FLOORS*NUM_OF_ROOMS_PER_FLOOR;

	for (int i = 0; i < numOfRooms; i++)
	{
		if ((*rooms[i]).getNumOfBeds() >= numberOfGuests)
		{
			if ((*rooms[i]).getNumberOfGuests() == 0)
				return (*rooms[i]).getRoomNumber();
		}
	}

	return NO_ROOM_AVAILBLE;
}

void Receptionist::collectPayment(int roomNumber, float amount) throw(const char *)
{
	if ((amount <= 0) || (roomNumber <= 0))
		throw "Invalid payment params.\n";
	std::cout << "payment " << amount << " from room number: " << roomNumber << " has been collected.\n";
}
