#ifndef ROOM_H
#define ROOM_H
#include<string>
#include<iostream>
using namespace std;

class Room 
{
	private:
	    int roomNumber;
	    bool isAvailable;
	    string roomType;
	    double charges;
	    string reservedUntil;
	
	public:
	    Room(int num = 0, string type = "Normal") : roomNumber(num), isAvailable(true), roomType(type) 
		{
	        charges = (type == "Presidential") ? 5000 : (type == "Deluxe") ? 3000 : 2000;
	    }
	
	    void bookRoom(string untilDate) 
		{
	        isAvailable = false;
	        reservedUntil = untilDate;
	    }
	
	    void freeRoomIfDue(string currentDate) 
		{
	        if (currentDate >= reservedUntil) 
			{
	            isAvailable = true;
	            reservedUntil = "";
	        }
	    }
	
	    bool available() const 
		{ 
			return isAvailable; 
		}
	    int getRoomNumber() const 
		{ 
			return roomNumber; 
		}
	    double getCharges() const 
		{ 
			return charges; 
		}
	    string getRoomType() const 
		{ 
			return roomType; 
		}
	
	    void showInfo() 
		{
	        cout<<"Room "<<roomNumber<<" (" <<roomType<<", Rs. " <<charges<<") - ";
	        cout<<(isAvailable ? "Available" : "Booked until " + reservedUntil)<<endl;
	    }
};
#endif

