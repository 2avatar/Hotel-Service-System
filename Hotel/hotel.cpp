#include "hotel.h"

Hotel Hotel::theHotel;

Hotel::Hotel() throw(const char *)
{
	numOfFloors = Receptionist::NUM_OF_FLOORS;
	numOfRoomsPerFloor = Receptionist::NUM_OF_ROOMS_PER_FLOOR;
	int numOfRooms = numOfFloors*numOfRoomsPerFloor;
	numOfUsedRooms = 0;
	name = "theHotel";
	diningRoom = new DiningRoom(numOfRooms, (Room::MAX_NUM_OF_BEDS)*numOfRooms);
	initRooms();
}

Hotel::~Hotel()
{
	delete[] diningRoom;
}

Hotel* Hotel::getInstance()
{
	return &theHotel;
}

void Hotel::setName(const string& name) throw(const char *)
{
	if (!name.empty())
		Hotel::name = name;
	else
		throw "Invalid name.\n";
}

int Hotel::getNumOfFloors() const
{
	return numOfFloors;
}

const string& Hotel::getName() const
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

vector<Employee*> Hotel::getAllEmployees() const
{
	return allEmployees;
}

vector<Room*> Hotel::getRooms() const
{
	return rooms;
}

int Hotel::isGuestExist(Person * guest)
{
	for (int i = 0; i < rooms.size(); i++)
	{
		if (rooms[i]->isGuestExist(*guest))
			return rooms[i]->getRoomNumber();
	}
	return Room::GUEST_NOT_EXIST;
}

bool Hotel::isRoomOccupied(int roomNumber)
{
	return rooms[roomNumber]->getNumberOfGuests() > 0;
}

Receptionist& Hotel::getReceptionist() const
{
	Receptionist* r = nullptr;
	return getEmployeeByType(allEmployees, *r);
}

const RoomService & Hotel::getRoomService() const
{
	RoomService* r = nullptr;
	return getEmployeeByType(allEmployees, *r);
}

const HouseKeeper & Hotel::getHouseKeeper() const
{
	HouseKeeper* r = nullptr;
	return getEmployeeByType(allEmployees, *r);
}

const ShiftManager & Hotel::getShiftManager() const
{
	ShiftManager* r = nullptr;
	return getEmployeeByType(allEmployees, *r);
}

const DiningRoom& Hotel::getDiningRoom() const
{
	return *diningRoom;
}

int Hotel::checkIn(const vector<Person*> guests, int numOfGuests, int userChoiceForDecoration, int roomDecoratorValue)
{
	Receptionist& r = getReceptionist();

	if (&r == nullptr)
		return Receptionist::NO_ROOM_AVAILBLE;

	int roomNumberAvailable = r.checkRoomAvailability(numOfGuests, rooms);

	if (roomNumberAvailable == Receptionist::NO_ROOM_AVAILBLE)
		return Receptionist::NO_ROOM_AVAILBLE;

	Room* roomAvailable;

	// get room by id
	roomAvailable = rooms[roomNumberAvailable - 1];

	switch (userChoiceForDecoration)
	{
	default:
	case 0:
	{
		roomAvailable->decorateRoom();
		break;
	}
	case 1:
	{
		Decorateable* birthdayRoom = new RoomForBirthday(roomAvailable, roomDecoratorValue);
		birthdayRoom->decorateRoom();
		break;
	}
	case 2:
	{
		Decorateable* anniversaryRoom = new RoomForAnniversary(roomAvailable, roomDecoratorValue);
		anniversaryRoom->decorateRoom();
		break;
	}
	}

	// check in guests
	if (roomAvailable != nullptr)
	{
		int end = guests.size();
		int start = end - numOfGuests;
		for (int i = start; i < end; i++)
			roomAvailable->checkInGuest(*guests[i]);

		numOfUsedRooms++;

		std::cout << "Hosting Guests: \n";
		std::cout << roomAvailable->getGuests() << "\n";
	}
	return roomNumberAvailable;
}

void Hotel::checkOut(int roomNumber)
{
	Room* room;

	room = rooms[roomNumber - 1];

	if (room != nullptr)
		if (room->getNumberOfGuests() > 0)
		{
			room->checkOutGuests(roomNumber);
			numOfUsedRooms--;
		}
}

void Hotel::initRooms()
{
	int indexHelper = 0;
	for (int i = 0; i < numOfFloors; i++)
		for (int j = 0; j < numOfRoomsPerFloor; j++)
		{
			if (i < numOfFloors - 1)
				rooms.push_back(new Room(indexHelper + 1, i + 1, (Room::MIN_ROOM_SIZE) + (i * 10)));
			// last floor is for suites only;
			else
				rooms.push_back(new Suite(indexHelper + 1, i + 1, (Room::MIN_ROOM_SIZE) + (i * 10), Suite::MIN_BALCONY_SIZE + (j * 2)));
			++indexHelper;
		}
}

void Hotel::acceptEmployees(IVisitor* visitor)
{
	acceptGeneric(allEmployees, visitor);
}

const Hotel & Hotel::operator+=(Employee & newEmployee)
{
	allEmployees.push_back(&newEmployee);
	return *this;
}

const Hotel & Hotel::operator-=(Employee & employee)
{
	fireEmployee(employee.getId());
	return *this;
}

void Hotel::fireEmployee(int id)
{
	removeEmployee(allEmployees, id);
}

std::ostream & Hotel::showHotelEmployees(std::ostream & os) const
{
	return printAll(allEmployees, os);
}

std::ostream & Hotel::showHotelDetails(std::ostream & os) const
{
	os << "Hotel " << getName().c_str() << ":\n";
	os << "Number of floors: " << getNumOfFloors() << "\n";
	os << "Number of rooms per floor: " << getNumOfRoomsPerFloor() << "\n";
	os << "Number of used rooms: " << getNumOfUsedRooms() << "\n";
	os << "Number of employees: " << getAllEmployees().size() << "\n";

	return os;
}
std::ostream & Hotel::showHotelRooms(std::ostream & os) const
{
	return printAll(rooms, os);
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
	diningRoom += roomNumber;
}

bool Hotel::handleComplaint(int roomNumber, const string& complaint) const
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



