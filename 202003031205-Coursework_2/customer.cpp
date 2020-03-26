#include "customer.h"
#include "pet.h"

using namespace std;

// constructors
Customer::Customer(string name, string address, int age) {
	setName(name);
	setAddress(address);
	setAge(age);
};

Customer::Customer(string customerName) {
	setName(customerName);
	setAddress("UNDEFINED");
	setAge(NULL);
};

Customer::Customer(string customerName, string customerAddress) {
	setName(customerName);
	setAddress(customerAddress);
	setAge(NULL);
};

Customer::Customer(string customerName, int customerAge) {
	setName(customerName);
	setAge(customerAge);
	setAddress("UNDEFINED");
};

Customer::Customer(int customerAge) {
	setAge(customerAge);
	setName("UNDEFINED");
	setAddress("UNDEFINED");
};

Customer::Customer() {
	setName("UNDEFINED");
	setAddress("UNDEFINED");
	setAge(NULL);
};

// getters
int Customer::getDiscount() {
	int age = getAge();
	if (age < 14) return 25;
	if (age > 70) return 50;
	else return 0;
};

// functions
void Customer::adopt(Pet pet) {
	pets.push_back(pet);
};

void Customer::release(int index) {
	pets.erase(pets.begin()+index);
};