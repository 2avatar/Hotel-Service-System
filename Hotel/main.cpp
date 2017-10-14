#include "hotel.h"
#include "houseKeeper.h"
#include "shiftManager.h"
#include <iostream>
using namespace std;

// Part 3

static const int DEFAULT_VAL = 0;
static const int INVALID_ID = 0;
static const int INVALID_INDEX = -1;
static const int DECORATE_NON = 0;
static const int DECORATE_BIRTHDAY = 1;
static const int DECORATE_ANNIVERSARY = 2;
static const int SALARY_TO_EMPLOYEES = 235;
static const int ROOM_PAYMENT = 700;

void showMenu();
void setHotelEmployees(Hotel& theHotel);
void fireEmployee(Hotel & theHotel);
void checkInGuests(Hotel& theHotel, vector<Person*>& guests);
void checkOutGuests(Hotel& theHotel);
void checkIfGuestExists(Hotel & theHotel, vector<Person*>& guests);
void openDiningRoomGates(Hotel& theHotel);
void closeDiningRoomGates(Hotel & theHotel);
void registerRoomToDiningRoom(Hotel& theHotel);
void handleComplaint(Hotel& theHotel);
void getComplaint(string& complaint);
void serveRoomByNumber(Hotel& theHotel);
void cleanRoomByNumber(Hotel& theHotel);
void cleanAllRooms(Hotel& theHotel);
void collectPaymentFromRoom(Hotel& theHotel);
void increaseSalaryToEmployees(Hotel& theHotel);
void showHotelDetails(Hotel& theHotel);
void showEmployeesDetails(Hotel& theHotel);
void showAllRoomsDetails(Hotel& theHotel);
void showDiningRoomDetails(Hotel& theHotel);
int getRoomNumber(Hotel& hotel);
void checkValidInput();
void clearBuffer();
int isValidId(vector<Person*> vec, int id);
void getNumberOfGuestsFromUser(int& numOfGuests);
void addGuests(vector<Person*>& guests, int& numOfGuests);
void setDecoratorByUser(int& response, int& roomDecoratorValue, int& userChoiceForDecoration);

void main()
{
	try
	{
		string name = "MyHotel";
		Hotel* theHotel = Hotel::getInstance();
		vector<Person*> guests;

		int choice = 0;
		while (choice != -1)
		{
			
			choice = 0;
			showMenu();
			cin >> choice;

			checkValidInput();

			switch (choice)
			{
			case 1:
			{
				setHotelEmployees(*theHotel);
				break;
			}
			case 2:
			{
				fireEmployee(*theHotel);
				break;
			}
			case 3:
				increaseSalaryToEmployees(*theHotel);
				break;
			case 4:
			{
				checkInGuests(*theHotel, guests);
				break;
			}
			case 5:
			{
				checkOutGuests(*theHotel);
				break;
			}
			case 6: 	
			{
				checkIfGuestExists(*theHotel, guests);
				break;
			}
			case 7: 
			{
				openDiningRoomGates(*theHotel);
				break;
			}
			case 8:
			{
				closeDiningRoomGates(*theHotel);
				break;
			}
			case 9:
			{
				registerRoomToDiningRoom(*theHotel);
				break;
			}
			case 10:
			{
				handleComplaint(*theHotel);
				break;
			}
			case 11:
			{		
				serveRoomByNumber(*theHotel);
				break;
			}
			case 12:
			{
				cleanRoomByNumber(*theHotel);
				break;
			}
			case 13:
				cleanAllRooms(*theHotel);
				break;
			case 14:
			{
				collectPaymentFromRoom(*theHotel);
				break;
			}
			case 15:
			{
				showHotelDetails(*theHotel);
				break;
			}
			case 16:
			{
				showEmployeesDetails(*theHotel);
				break;
			}
			case 17:
			{
				showAllRoomsDetails(*theHotel);
				break;
			}
			case 18:
			{
				showDiningRoomDetails(*theHotel);
				break;
			}
			case -1:
				break;
			default:
				cout << "wrong input, try again" << endl;
				break;
			}
		}
		cout << "bye bye" << endl;
	}
	catch (char* str)
	{
		std::cout << str;
	}
}


void setHotelEmployees(Hotel& theHotel)
{
	Employee* shiftManager = new ShiftManager("Momo", Employee::MIN_SALARY + 50.5);
	Employee* receptionist1 = new Receptionist("Lolo", Employee::MIN_SALARY + 45.0);
	Employee* receptionist2 = new Receptionist("Popo", Employee::MIN_SALARY + 23.5);
	Employee* houseKeeper = new HouseKeeper("Coco", Employee::MIN_SALARY + 22);
	Employee* roomService = new RoomService("Yoyo", Employee::MIN_SALARY + 21.5);

	theHotel += *shiftManager;
	theHotel += *receptionist1;
	theHotel += *receptionist2;
	theHotel += *houseKeeper;
	theHotel += *roomService;
	cout << "\nAll Employees: " << endl;
	cout << "------------------- " << endl;

	theHotel.showHotelEmployees(std::cout);	//prints the current Employees.

}

void fireEmployee(Hotel & theHotel)
{
	int employeeId = DEFAULT_VAL;

	cout << "Please enter employee's id: ";
	cin >> employeeId;
	checkValidInput();

	if (employeeId > INVALID_ID)
	{
		theHotel.fireEmployee(employeeId);
		cout << "employee was fired" << endl;
	}
	else
		cout << "Invalid id " << endl;
}

void checkInGuests(Hotel & theHotel, vector<Person*>& guests)
{
	int numOfGuests = DEFAULT_VAL;
	int userChoiceForDecoration = DECORATE_NON;
	int response = DEFAULT_VAL;
	int roomDecoratorValue = DEFAULT_VAL;

	getNumberOfGuestsFromUser(numOfGuests);
	addGuests(guests, numOfGuests);
	setDecoratorByUser(response, roomDecoratorValue, userChoiceForDecoration);

	int roomNumber = theHotel.checkIn(guests, numOfGuests, userChoiceForDecoration, roomDecoratorValue);
	if (roomNumber > Receptionist::NO_ROOM_AVAILBLE)
		cout << "The guests are now in room number: " << roomNumber << endl;
	else
		cout << "No Room or Recepetionist available " << endl;
}

void getNumberOfGuestsFromUser(int& numOfGuests)
{
	do
	{
		clearBuffer();
		cout << "How many guests? ";
		cin >> numOfGuests;
	} while ((numOfGuests <= 0) || cin.fail());
	cin.ignore(1, '\n');
}

void addGuests(vector<Person*>& guests, int& numOfGuests)
{
	for (int i = 0; i < numOfGuests; i++)
	{
		string name;
		cout << "Enter guest #" << (i + 1) << " name: ";
		getline(cin, name);
		guests.push_back(new Person(name));
	}
}

void setDecoratorByUser(int& response, int& roomDecoratorValue, int& userChoiceForDecoration)
{
	cout << "Is it your Anniversary? 1/0: ";
	cin >> response;
	checkValidInput();

	if (!response)
	{
		cout << "Is it your Birthday? 1/0: ";
		cin >> response;
		checkValidInput();

		if (response)
		{
			cout << "Diameter of cake: ";
			cin >> roomDecoratorValue;
			checkValidInput();
			userChoiceForDecoration = DECORATE_BIRTHDAY;
		}
	}
	else
	{
		cout << "Amount of baloons: ";
		cin >> roomDecoratorValue;
		checkValidInput();
		userChoiceForDecoration = DECORATE_ANNIVERSARY;
	}
}

void checkOutGuests(Hotel & theHotel)
{
	int roomForCheckOut = DEFAULT_VAL;

	roomForCheckOut = getRoomNumber(theHotel);
	checkValidInput();

	if (roomForCheckOut > Receptionist::NO_ROOM_AVAILBLE)
		theHotel.checkOut(roomForCheckOut);
	
}

void checkIfGuestExists(Hotel & theHotel, vector<Person*>& guests)
{
	int id, personId;

	cout << "Please enter guest id: ";
	cin >> id;
	checkValidInput();

	personId = isValidId(guests, id);
	if (personId == INVALID_INDEX)
		cout << "Invalid id" << endl;
	else
	{
		int roomNum = theHotel.isGuestExist(guests[personId]);
		if (roomNum != Room::GUEST_NOT_EXIST)
			cout << "Guest exist in room number " << roomNum  << endl;
		else
			cout << "Guest not exist" << endl;
	}
}

void openDiningRoomGates(Hotel & theHotel)
{
	theHotel.openDRGates();
	cout << "Dining room gates are now open " << endl;
}

void closeDiningRoomGates(Hotel & theHotel)
{
	theHotel.closeDRGates();
	cout << "Dining room gates are now closed " << endl;
	cout << "Refreshing list of registered rooms... " << endl;
}

void registerRoomToDiningRoom(Hotel & theHotel)
{
	int roomNumber = getRoomNumber(theHotel);
	if (roomNumber)
	{
		theHotel.registerRoomToDR(roomNumber);
		cout << "Registering room number " << roomNumber << endl;
	}
}

void handleComplaint(Hotel & theHotel)
{

	int roomNumber = getRoomNumber(theHotel);
			
	if (roomNumber == Receptionist::NO_ROOM_AVAILBLE)
		return;

	clearBuffer();

	string complaint;
	getComplaint(complaint);
	

	if (theHotel.handleComplaint(roomNumber, complaint))
		cout << "Complaint is handled " << endl;
	else
		cout << "There is no shift manager in the hotel. " << endl;

}

void getComplaint(string& complaint)
{
	cout << "what is your complaint? ";
	getline(cin, complaint);
}

void serveRoomByNumber(Hotel & theHotel)
{
	int roomNumber = getRoomNumber(theHotel);

	if (roomNumber == Receptionist::NO_ROOM_AVAILBLE)
		return;

	if (theHotel.serveRoom(roomNumber))
		cout << "Room was served " << endl;
	else
		cout << "There is no room service in the hotel." << endl;

}

int isValidId(vector<Person*> vec, int id)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i]->getId() == id)
			return i;
	}
	return INVALID_INDEX;
}

void checkValidInput()
{
	if (cin.fail())
	{
		clearBuffer();
	}
}

void clearBuffer()
{
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void cleanRoomByNumber(Hotel & theHotel)
{
	int roomNumber = getRoomNumber(theHotel);

	if (roomNumber == Receptionist::NO_ROOM_AVAILBLE)
		return;

	if (theHotel.cleanRoom(roomNumber))
		cout << "Room was cleaned " << endl;
	else
		cout << "There is no house keeper in the hotel." << endl;

}

void cleanAllRooms(Hotel & theHotel)
{
	if (theHotel.cleanAllRooms())
		cout << "Rooms were cleaned " << endl;
	else
		cout << "There is no house keeper in the hotel." << endl;
}

void collectPaymentFromRoom(Hotel & theHotel)
{
	int roomNumber = getRoomNumber(theHotel);

	if (roomNumber == Receptionist::NO_ROOM_AVAILBLE)
		return;

	if (theHotel.collectPayment(roomNumber, ROOM_PAYMENT))
		cout << "Thank you for your payment room #" << roomNumber << endl;
	else
		cout << "There is no receptionist to collect in the hotel. " << endl;
}

void increaseSalaryToEmployees(Hotel & theHotel)
{
	theHotel.acceptEmployees(new IncraseSalaryVisitor(SALARY_TO_EMPLOYEES));
	cout << "Increased all employees salary by " << SALARY_TO_EMPLOYEES << "$ " << endl;
}

void showHotelDetails(Hotel & theHotel)
{
	theHotel.showHotelDetails(cout);
}

void showEmployeesDetails(Hotel & theHotel)
{
	theHotel.showHotelEmployees(cout);
}

void showAllRoomsDetails(Hotel & theHotel)
{
	theHotel.showHotelRooms(cout);
}

void showDiningRoomDetails(Hotel & theHotel)
{
	theHotel.showHotelDiningRoom(cout);
}

int getRoomNumber(Hotel& hotel)
{
	int roomNumber = DEFAULT_VAL;
	cout << "Insert room number: ";
	cin >> roomNumber;
	checkValidInput();
	
	if (roomNumber > Receptionist::NO_ROOM_AVAILBLE)
	{
		if (hotel.isRoomOccupied(roomNumber-1))
		{
			return roomNumber;
		}
		else
			cout << "Room is empty " << endl;
	}
	else
		cout << "Invalid room  "<< endl;
	return Receptionist::NO_ROOM_AVAILBLE;
}

void showMenu()
{
	cout << "\nWhat action would you like to preform? " << endl;
	cout << " 1  --- Set hotel employees " << endl;
	cout << " 2  --- Fire employee" << endl;
	cout << " 3  --- Increase salary to employees" << endl;
	cout << " 4  --- Check in guests" << endl;
	cout << " 5  --- Check out guests" << endl;
	cout << " 6  --- Check if guest exists" << endl;
	cout << " 7  --- Open dining room gates" << endl;
	cout << " 8  --- Close dining room gates" << endl;
	cout << " 9  --- Register Room to dining room" << endl;
	cout << "10  --- Handle complaint" << endl;
	cout << "11  --- Serve room by number" << endl;
	cout << "12  --- Clean room by number" << endl;
	cout << "13  --- Clean all rooms" << endl;
	cout << "14  --- Collect payment from room" << endl;
	cout << "15  --- Show hotel details" << endl;
	cout << "16  --- Show employees details" << endl;
	cout << "17  --- Show all rooms details" << endl;
	cout << "18  --- Show dining room details" << endl;
	cout << "-1  --- Exit" << endl;
	cout << "Selection: ";
}