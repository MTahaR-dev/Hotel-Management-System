#ifndef ADMIN_H
#define ADMIN_H
#include "guest.h"
#include "room.h"
#include "reservation.h"
#include "carparkingslot.h"

const int MAX_ROOMS = 100;
const int MAX_GUESTS = 100;
const int MAX_PARKING_SLOTS = 50;

class Admin 
{
	    Room rooms[MAX_ROOMS];
	    Guest guests[MAX_GUESTS];
	    Reservation* reservations[MAX_GUESTS];
	    CarParkingSlot parkingSlots[MAX_PARKING_SLOTS];
	    int guestCount, reservationCount;
	
	public:
	    Admin() : guestCount(0), reservationCount(0) 
		{
	        for (int i = 0; i < MAX_ROOMS; ++i) 
			{
	            string type = (i % 5 == 0) ? "Presidential" : (i % 3 == 0) ? "Deluxe" : "Normal";
	            rooms[i] = Room(100 + i, type);
	        }
	
	        for(int i = 0; i < MAX_PARKING_SLOTS; ++i)
	            {
	            	parkingSlots[i] = CarParkingSlot(i + 1);
				}
	        for(int i = 0; i < MAX_GUESTS; ++i)
	            {
	            	reservations[i] = nullptr;
				}
	    }
	
	    void addGuest(string name, int age) 
		{
	        try 
			{
	            if (guestCount >= MAX_GUESTS)
	               {
	               	 throw runtime_error("Guest list full. Cannot add more guests.");
				   }
	            guests[guestCount] = Guest(name, age, guestCount);
	            cout<<"Guest added with ID: "<<guestCount<<endl;
	            guestCount++;
	        } 
	        catch (...) 
			{
				cout<<"Something went wrong while booking the reservation."<<endl;
			}
	
	    }
	
	    void showAllRooms() 
		{
	        for(int i = 0; i < MAX_ROOMS; ++i)
	        {
	           	rooms[i].showInfo();
			}
	    }
	
	    void showGuests() 
		{
	        for (int i = 0; i < guestCount; ++i)
	            {
	            	guests[i].showInfo();
				}
	    }
	
	    void makeReservation(int guestID, string fromDate, string toDate, string roomType, string vehicleNumber) 
		{
	        try 
			{
	            	if (guestID >= guestCount)
	                {
	                	throw invalid_argument("Invalid Guest ID.");
					}
	
	            for (int j = 0; j < MAX_ROOMS; ++j) 
				{
	                rooms[j].freeRoomIfDue(fromDate);
	                if (rooms[j].available() && rooms[j].getRoomType() == roomType) 
					{
	                    for (int k = 0; k < MAX_PARKING_SLOTS; ++k) 
						{
	                        if (parkingSlots[k].available()) 
							{
	                            parkingSlots[k].assign(vehicleNumber);
	                            reservations[reservationCount++] = new Reservation(&guests[guestID], &rooms[j], fromDate, toDate);
	                            cout<<"Reservation successful! Parking Slot: "<<(k + 1)<<endl;
	                            return;
	                        }
	                    }
	                    throw runtime_error("No parking slot available.");
	                }
	            }
	            throw runtime_error("No available rooms of type " + roomType + ".");
	        } 
			catch (...) 
			{
			    cout<<"Something went wrong while booking the reservation."<<endl;
			}
	
	    }
	
	    void showReservations() 
		{
	        for (int i = 0; i < reservationCount; ++i)
	           {
	           		 reservations[i]->showInfo();
			   }
	        Reservation::showTotalReservations();
	    }
	
	    ~Admin() 
		{
	        for (int i = 0; i < reservationCount; ++i)
	            delete reservations[i];
	    }
};
#endif

