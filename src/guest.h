#ifndef GUEST_H
#define GUEST_H
#include "person.h"

class Guest : public Person 
{
	private:
	    int guestID;
	    string preferredRoomType;
	public:
	    Guest(string n = "", int a = 0, int id = 0, string rt = "Normal"): Person(n, a), guestID(id), preferredRoomType(rt) {}
	
	    void showInfo() override 
		{
	        cout << "[Guest] ";
	        Person::showInfo();
	        cout<<"Guest ID: "<<guestID<<endl;
	    }
	
	    int getID() const 
		{ 
			return guestID; 
		}
	    string getPreferredRoomType() const 
		{ 
			return preferredRoomType; 
		}
};
#endif

