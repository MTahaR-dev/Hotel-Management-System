#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
using namespace std;

class Person 
{
	protected:
	    string name;
	    int age;
	public:
	    Person(string n = "", int a = 0) : name(n), age(a) {}
	    virtual void showInfo() 
		{
	        cout<<"Name: "<<name;
			cout<<"\nAge: "<<age<<endl;
	    }
};
#endif

