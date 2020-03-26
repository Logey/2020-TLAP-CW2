#include <iostream>
#include "pet.h"
#include "petshop.h"
#include <string>
#include "menu.h"

Pet::Pet() {
	setName("UNDEFINED");
	setDescription("UNDEFINED");
	setEnergyLevel(1 + rand() % 5);
	setHungerLevel(1 + rand() % 5);
	setFriendliness(1 + rand() % 5);
};

void Pet::display() {
	string firstLine = "ID: " + to_string(getID()) + " ";
	cout << firstLine;
	Menu::printLine(50 - firstLine.length(), true);
	cout << "\tAnimal (Breed):\t" << getPetType() << endl;
	cout << "\tName:\t\t" << getName() << endl;
	cout << "\tEnergy Level:\t" << getEnergyLevel() << endl;
	cout << "\tHunger Level:\t" << getHungerLevel() << endl;
	cout << "\tFriendliness:\t" << getFriendliness() << endl;
	Menu::printLine(50, true);
};