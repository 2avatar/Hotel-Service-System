#pragma once
#ifndef __HOTEL_H
#define __HOTEL_H
#include "employee.h"
#include "receptionist.h"
#include "suite.h"
#include "roomService.h"
#include "diningRoom.h"
#include "houseKeeper.h"
#include "shiftManager.h"
#include "IteratorFunctions.h"
#include "RoomForBirthday.h"
#include "RoomForAnniversary.h"
#include "IncreaseSalaryVisitor.h"
class Hotel
{
private:

	static Hotel theHotel;

	string name;
	int numOfFloors , numOfRoomsPerFloor, numOfUsedRooms;
	vector<Employee*> allEmployees;
	vector<Room*> rooms;
	DiningRoom* diningRoom;

	Hotel();
	Hotel(const Hotel& other);
	const Hotel& operator= (const Hotel& other);

public:

	~Hotel();
	static Hotel* getInstance();
	friend std::ostream& operator<<(std::ostream& os, const Hotel& e);

	// getters and setters
	void setName(const string& name) throw (const char*);

	int getNumOfFloors() const;
	const string& getName()	const;
	int getNumOfRoomsPerFloor() const;
	int getNumOfUsedRooms() const;
	vector<Employee*> getAllEmployees() const;
	vector<Room*> getRooms() const;

	int isGuestExist(Person* guest);
	bool isRoomOccupied(int roomNumber);
	Receptionist& getReceptionist() const;

	const RoomService& getRoomService() const; 

	const HouseKeeper& getHouseKeeper() const;

	const ShiftManager& getShiftManager() const;

	const DiningRoom& getDiningRoom() const;

	int checkIn(vector<Person*> guests, int numOfGuests, int decorationType, int roomDecoratorValue);  //rooms.checkInGuests(guests) return the room number
	void checkOut(int roomNumber) ;  //rooms.checkOutGuests(roomNumber)

	void initRooms();
	void acceptEmployees(IVisitor* visitor); // increase the salary for all the employees
	//adding an Employee to the allEmployee array
	const Hotel& operator+= (Employee& newEmployee);

	/*removing an Employee from the allEmployee array.*/
	const Hotel& operator-= (Employee& employee);
	void fireEmployee(int id);
	std::ostream& showHotelEmployees(std::ostream& os) const;

	std::ostream& showHotelDetails(std::ostream& os) const;

	std::ostream& showHotelRooms(std::ostream& os) const;

	std::ostream& showHotelDiningRoom(std::ostream& os) const;

	void openDRGates() const; //diningRoom.openGates() -> change the status enum to open and print some msg
	void closeDRGates() const;

	void registerRoomToDR(int roomNumber);
	bool handleComplaint(int roomNumber, const string& complaint) const;
	bool serveRoom(int roomNumber) const;
	bool cleanRoom(int roomNumber) const;
	bool cleanAllRooms() const;
	bool collectPayment(int roomNumber, int roomPayment) const;

};

#endif //__HOTEL_H