#ifndef RESERVATION_H
#define RESERVATION_H
#include "guest.h"
#include "room.h"

class Reservation 
{
	private:
	    Guest* guest;
	    Room* room;
	    string fromDate, toDate;
	    static int totalReservations;
	
	public:
	    Reservation(Guest* g = nullptr, Room* r = nullptr, string from = "", string to = ""): guest(g), room(r), fromDate(from), toDate(to) 
		{
	        if (room != nullptr) room->bookRoom(to);
	        totalReservations++;
	    }
	
	    void showInfo() 
		{
	        cout << "Reservation: ";
	        if (guest && room) 
			{
	            guest->showInfo();
	            cout<<"-> Room "<<room->getRoomNumber()<<" ("<<room->getRoomType()<<")\n";
	            cout<<"   From: "<<fromDate<<" To: "<<toDate<<endl;
	        } 
			else 
			{
	            cout<<"Invalid reservation.\n";
	        }
	    }
	
	    static void showTotalReservations() 
		{
	        cout<<"Total Reservations: "<<totalReservations<<endl;
	    }
};
int Reservation::totalReservations = 0;
#endif

