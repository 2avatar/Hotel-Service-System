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
class Hotel
{
private:
	char* name;
	int numOfFloors , numOfRoomsPerFloor, numOfUsedRooms, numOfEmployees;
	Employee** allEmployees;
	Room** rooms;
	DiningRoom* diningRoom;

public:

	static const int MAX_EMPLOYEES = 50;

	Hotel(const char* name) throw (const char*);
	Hotel(const Hotel& other);
	const Hotel& operator= (const Hotel& other);
	~Hotel();

	friend std::ostream& operator<< (std::ostream& os, const Hotel& e);

	// getters and setters
	void setName(const char* name) throw (const char*);

	int getNumOfFloors() const;
	const char* getName()	const;
	int getNumOfRoomsPerFloor() const;
	int getNumOfUsedRooms() const;
	Employee** getAllEmployees() const;
	Room** getRooms() const;

	int isGuestExist(Person* guest) const;
	bool isRoomOccupied(int roomNumber);
	Receptionist& getReceptionist() const;

	const RoomService& getRoomService() const; 

	const HouseKeeper& getHouseKeeper() const;

	const ShiftManager& getShiftManager() const;

	const DiningRoom& getDiningRoom() const;

	int checkIn(Person** guests, int numOfGuests);  //rooms.checkInGuests(guests) return the room number
	void checkOut(int roomNumber);  //rooms.checkOutGuests(roomNumber)

	void initArrays();
	void increaseAllEmployeesSalary(float amount); // increase the salary for all the employees
	//adding an Employee to the allEmployee array
	const Hotel& operator+= (Employee& newEmployee);

	/*removing an Employee from the allEmployee array.*/
	const Hotel& operator-= (Employee& fireEmployee);
	void removeEmployee(int id);

	std::ostream & Hotel::showHotelDetails(std::ostream & os) const;

	std::ostream& showHotelEmployees(std::ostream& os) const;

	std::ostream& showHotelRooms(std::ostream& os) const;

	std::ostream& showHotelDiningRoom(std::ostream& os) const;

	void openDRGates() const; //diningRoom.openGates() -> change the status enum to open and print some msg
	void closeDRGates() const;

	void registerRoomToDR(int roomNumber);
	bool handleComplaint(int roomNumber, const char* complaint) const;
	bool serveRoom(int roomNumber) const;
	bool cleanRoom(int roomNumber) const;
	bool cleanAllRooms() const;
	bool collectPayment(int roomNumber, int roomPayment) const;

};

#endif //__HOTEL_H