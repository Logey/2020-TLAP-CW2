#pragma once
#include <string>
#include <vector>
#include "pet.h"

using namespace std;

class Customer {
private:
	string name,
		address;
	int age,
		id;
	vector<Pet> pets = {};
public:
	// constructors
	Customer(string customerName, string customerAddress, int customerAge);
	Customer(string customerName);
	Customer(string customerName, string customerAddress);
	Customer(string customerName, int customerAge);
	Customer(int customerAge);
	Customer();
	// getters
	string getName() { return name; };
	string getAddress() { return address; };
	int getAge() { return age; };
	int getDiscount();
	int getID() { return id; };
	vector<Pet> getPets() { return pets; };
	// setters
	void setName(string customerName) { name = customerName; };
	void setAddress(string customerAddress) { address = customerAddress; };
	void setAge(int customerAge) { age = customerAge; };
	void setID(int customerID) { id = customerID; };
	// functions
	void adopt(Pet pet);
	void release(int index);
};