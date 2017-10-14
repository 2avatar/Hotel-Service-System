#include "hotel.h"

Hotel::Hotel(const char * name) throw(const char *)
{
	numOfFloors = Receptionist::NUM_OF_FLOORS;
	numOfRoomsPerFloor = Receptionist::NUM_OF_ROOMS_PER_FLOOR;
	int numOfRooms = numOfFloors*numOfRoomsPerFloor;
	numOfUsedRooms = 0;
	numOfEmployees = 0;
	setName(name);
	diningRoom = new DiningRoom(numOfRooms, (Room::MAX_NUM_OF_BEDS)*numOfRooms);
	allEmployees = new Employee*[MAX_EMPLOYEES];
	rooms = new Room*[numOfRooms];
	initArrays();
}

Hotel::Hotel(const Hotel & other)
{
	*this = other;
}

const Hotel & Hotel::operator=(const Hotel & other)
{
	if (this != &other)
	{
		Hotel::name = _strdup(name);
		Hotel::numOfFloors = other.numOfFloors;
		Hotel::numOfRoomsPerFloor = other.numOfRoomsPerFloor;
		Hotel::numOfUsedRooms = other.numOfUsedRooms;
		Hotel::numOfEmployees = other.numOfEmployees;
		for (int i = 0; i < other.numOfEmployees; i++)
			allEmployees[i] = other.allEmployees[i];
		for (int i = 0; i < numOfFloors*numOfRoomsPerFloor; i++)
			rooms[i] = other.rooms[i];

		Hotel::diningRoom = other.diningRoom;
	}
	return *this;
}

Hotel::~Hotel()
{

	for (int i = 0; i < MAX_EMPLOYEES; i++)
	{
		if (allEmployees[i] != nullptr)
			delete allEmployees[i];
	}
	for (int i = 0; i < numOfFloors*numOfRoomsPerFloor; i++)
	{
		if (rooms[i] != nullptr)
			delete rooms[i];
	}

	delete[] allEmployees;
	delete[] rooms;
	delete[] diningRoom;
	delete[] name;
}

void Hotel::setName(const char * name) throw(const char *)
{
	if (name != nullptr)
		Hotel::name = _strdup(name);
	else
		throw "Invalid name.\n";
}

int Hotel::getNumOfFloors() const
{
	return numOfFloors;
}

const char * Hotel::getName() const
{
	return name;
}

int Hotel::getNumOfRoomsPerFloor() const
{
	return numOfRoomsPerFloor;
}

int Hotel::getNumOfUsedRooms() const
{
	return numOfUsedRooms;
}

Employee ** Hotel::getAllEmployees() const
{
	return allEmployees;
}

Room ** Hotel::getRooms() const
{
	return rooms;
}

int Hotel::isGuestExist(Person * guest) const
{
	for (int i = 0; i < numOfFloors*numOfRoomsPerFloor; i++)
	{
		if (rooms[i]->isGuestExist((*guest).getId()))
			return rooms[i]->getRoomNumber();
	}
	return Room::GUEST_NOT_EXIST;
}


bool Hotel::isRoomOccupied(int roomNumber)
{
	return rooms[roomNumber]->getNumberOfGuests() > 0;
}



Receptionist & Hotel::getReceptionist() const
{
	for (int i = 0; i < MAX_EMPLOYEES; i++)
	{
		if (allEmployees[i] != nullptr)
			if (strcmp(typeid(*allEmployees[i]).name(), typeid(Receptionist).name()) == 0)
				return dynamic_cast<Receptionist&>(*allEmployees[i]);
	}
	Receptionist* r = nullptr;
	return *r;
}

const RoomService & Hotel::getRoomService() const
{
	for (int i = 0; i < MAX_EMPLOYEES; i++)
	{
		if (allEmployees[i] != nullptr)
			if (strcmp(typeid(*allEmployees[i]).name(), typeid(RoomService).name()) == 0)
				return dynamic_cast<RoomService&>((*allEmployees[i]));
	}
	RoomService* r = nullptr;
	return *r;
}

const HouseKeeper & Hotel::getHouseKeeper() const
{
	for (int i = 0; i < MAX_EMPLOYEES; i++)
	{
		if (allEmployees[i] != nullptr)
			if (strcmp(typeid(*allEmployees[i]).name(), typeid(HouseKeeper).name()) == 0)
				return dynamic_cast<HouseKeeper&>((*allEmployees[i]));
	}
	HouseKeeper* h = nullptr;
	return *h;
}

const ShiftManager & Hotel::getShiftManager() const
{
	for (int i = 0; i < MAX_EMPLOYEES; i++)
	{
		if (allEmployees[i] != nullptr)
			if (strcmp(typeid(*allEmployees[i]).name(), typeid(ShiftManager).name()) == 0)
				return dynamic_cast<ShiftManager&>((*allEmployees[i]));
	}
	ShiftManager* s = nullptr;
	return *s;
}

const DiningRoom& Hotel::getDiningRoom() const
{
	return *diningRoom;
}

int Hotel::checkIn(Person ** guests, int numOfGuests)
{
	Receptionist& r = getReceptionist();
	if (&r != nullptr) {

		int roomAvailable = r.checkRoomAvailability(numOfGuests, rooms);
		if (roomAvailable != Receptionist::NO_ROOM_AVAILBLE)
		{
			for (int i = 0; i < numOfGuests; i++)
			{
				(*rooms[roomAvailable - 1]).checkInGuest((*guests[i]));
			}
			numOfUsedRooms++;
		}
		return roomAvailable;
	}
	return Receptionist::NO_ROOM_AVAILBLE;
}

void Hotel::checkOut(int roomNumber)
{
	if ((*rooms[roomNumber - 1]).getNumberOfGuests() > 0) {
		(*rooms[roomNumber - 1]).checkOutGuests(roomNumber);
		numOfUsedRooms--;
	}
}

void Hotel::initArrays()
{
	for (int i = 0; i < MAX_EMPLOYEES; i++)
		allEmployees[i] = nullptr;

	int indexHelper = 0;
	for (int i = 0; i < numOfFloors; i++)
		for (int j = 0; j < numOfRoomsPerFloor; j++) {
			if (i < numOfFloors - 1) {
				rooms[indexHelper] = new Room(indexHelper + 1, i + 1, (Room::MIN_ROOM_SIZE) + (i * 10));
				++indexHelper;
			}
			// last floor is for suites only;
			else {
				rooms[indexHelper] = new Suite(indexHelper + 1, i + 1, (Room::MIN_ROOM_SIZE) + (i * 10), Suite::MIN_BALCONY_SIZE + (j * 2));
				++indexHelper;
			}
		}

}

void Hotel::increaseAllEmployeesSalary(float amount)
{
	for (int i = 0; i < MAX_EMPLOYEES; i++) {
		if (allEmployees[i] != nullptr)
		allEmployees[i]->setSalary(allEmployees[i]->getSalary() + amount);
	}
}

const Hotel & Hotel::operator+=(Employee & newEmployee)
{
	if (numOfEmployees < MAX_EMPLOYEES) {
		for (int i = 0; i < MAX_EMPLOYEES; i++) {
			if (allEmployees[i] == nullptr) {
				allEmployees[numOfEmployees] = &newEmployee;
				numOfEmployees++;
				break;
			}
		}
	}
	return *this;
}

const Hotel & Hotel::operator-=(Employee & fireEmployee)
{
	removeEmployee(fireEmployee.getId());
	return *this;
}



void Hotel::removeEmployee(int id)
{
	for (int i = 0; i < MAX_EMPLOYEES; i++) {
		if (allEmployees[i] != nullptr) {
			if (allEmployees[i]->getId() == id) {
				allEmployees[i] = nullptr;
				numOfEmployees--;
				break;
			}
		}
	}
}

std::ostream & Hotel::showHotelEmployees(std::ostream & os) const
{
	// print employees
	for (int i = 0; i < MAX_EMPLOYEES; i++)
	{
		if (allEmployees[i] != nullptr)
		{
			os << *allEmployees[i] << "\n";
		}
	}
	return os;
}

std::ostream & Hotel::showHotelDetails(std::ostream & os) const
{
	os << "Hotel " << getName() << ":\n";
	os << "Number of floors: " << getNumOfFloors() << "\n";
	os << "Number of rooms per floor: " << getNumOfRoomsPerFloor() << "\n";
	os << "Number of used rooms: " << getNumOfUsedRooms() << "\n";
	os << "Number of employees: " << numOfEmployees << "\n";

	return os;
}
std::ostream & Hotel::showHotelRooms(std::ostream & os) const
{
	for (int i = 0; i < numOfFloors*numOfRoomsPerFloor; i++)
	{
		if (rooms[i] != nullptr)
		{
			os << *rooms[i] << "\n";
		}
	}
	return os;
}

std::ostream & Hotel::showHotelDiningRoom(std::ostream & os) const
{
	os << *diningRoom;
	return os;
}
void Hotel::openDRGates() const
{
	diningRoom->openGates();
}

void Hotel::closeDRGates() const
{
	diningRoom->closeGates();
}

void Hotel::registerRoomToDR(int roomNumber)
{
	*diningRoom += roomNumber;
}

bool Hotel::handleComplaint(int roomNumber, const char* complaint) const
{
	const ShiftManager& sm = getShiftManager();

	if (&sm == nullptr)
		return false;

	sm.handleComplaint(roomNumber, complaint);
	return true;
}

bool Hotel::serveRoom(int roomNumber) const
{
	const RoomService& rs = getRoomService();
	
	if (&rs == nullptr)
		return false;

	rs.serveRoom(roomNumber);
	return true;

}

bool Hotel::cleanRoom(int roomNumber) const
{
	const HouseKeeper& hk = getHouseKeeper();
	
	if (&hk == nullptr)
		return false;

	hk.cleanRoom(roomNumber);
	return true;
	
}

bool Hotel::cleanAllRooms() const
{
	const HouseKeeper& hk = getHouseKeeper();

	if (&hk == nullptr)
		return false;

	hk.cleanAllRooms();
	return true;
}

bool Hotel::collectPayment(int roomNumber, int roomPayment) const
{
	Receptionist& r = getReceptionist();
	
	if (&r == nullptr)
		return false;

	r.collectPayment(roomNumber, roomPayment);
	return true;
}

std::ostream & operator<<(std::ostream & os, const Hotel & e)
{
	// print hotel details
	e.showHotelDetails(os);

	// print employees
	e.showHotelEmployees(os);

	// print rooms
	e.showHotelRooms(os);

	return os;
}

