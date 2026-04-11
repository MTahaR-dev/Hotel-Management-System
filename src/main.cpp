#include "admin.h"

int main() 
{
    Admin admin;
    int choice;
    do 
	{
        cout << "\n----- Hotel Management Menu -----\n";
        cout << "1. Add Guest\n";
        cout << "2. Show All Rooms\n";
        cout << "3. Show All Guests\n";
        cout << "4. Make Reservation\n";
        cout << "5. Show Reservations\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
		{
            case 1: 
			{
                string name;
                int age;
                cout<<"Enter name: "; 
				cin>>name;
                cout<<"Enter age: "; 
				cin>>age;
                admin.addGuest(name, age);
                break;
            }
            case 2:
                admin.showAllRooms();
                break;
            case 3:
                admin.showGuests();
                break;
            case 4: {
                admin.showGuests();
                int guestID;
                string fromDate, toDate, roomType, vehicleNumber;
                cout<<"\nEnter guest ID: "; 
				cin>>guestID;
                cout<<"\nFrom date (DD-MM-YYYY): "; 
				cin >> fromDate;
                cout<<"\nTo date (DD-MM-YYYY): "; 
				cin >> toDate;
                cout<<"\nRoom type (Normal/Deluxe/Presidential): "; 
				cin>>roomType;
                cout<<"\nVehicle number: ";
				cin>>vehicleNumber;
                admin.makeReservation(guestID, fromDate, toDate, roomType, vehicleNumber);
                break;
            }
            case 5:
                admin.showReservations();
                break;
            case 6:
                cout<<"Thank you for using the Hotel Management System!\n";
                break;
            default:
                cout<<"Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

