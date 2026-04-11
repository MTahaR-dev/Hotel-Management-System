#ifndef CARPARKINGSLOT_H
#define CARPARKINGSLOT_H
#include <iostream>
using namespace std;

class CarParkingSlot 
{
	private:
	    string vehicleNumber;
	    int slotNumber;
	    bool isOccupied;
	public:
	    CarParkingSlot(int sNum = 0) : vehicleNumber(""), slotNumber(sNum), isOccupied(false) {}
	
	    bool available() const 
		{ 
			return !isOccupied; 
		}
	
	    void assign(string vNum) 
		{
	        vehicleNumber = vNum;
	        isOccupied = true;
	    }
	
	    void showInfo() 
		{
	        cout<<"Parking Slot: "<<slotNumber<<(isOccupied ? ", Vehicle: " + vehicleNumber : ", Available")<<endl;
	    }
};
#endif

