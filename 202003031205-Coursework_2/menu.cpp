#include <iostream>
#include <string>
#include <vector>
#include "menu.h"

using namespace std;

// constructors
Menu::Menu() {
	PetShop petShop = PetShop();
	Customer customer = Customer();
	petShop.addCustomer(customer);
	setCustomer(customer);
	setPetShop(petShop);
};
Menu::Menu(PetShop petShop) { Menu(); setPetShop(petShop); };
Menu::Menu(Customer customer) { Menu(); setCustomer(customer); };
Menu::Menu(PetShop petShop, Customer customer) { Menu(); setPetShop(petShop); setCustomer(customer); };

// utility functions
void Menu::clear() { for (int i = 0; i < 100; i++) cout << endl; };

void Menu::printLine(char character, int amount, bool endLine) {
	for (int i = 0; i < amount; i++) cout << character;
	if (endLine) cout << endl;
};
void Menu::printLine() { printLine('-', 50, true); };
void Menu::printLine(int amount) { printLine('-', amount, true); };
void Menu::printLine(bool endLine) { printLine('-', 50, endLine); };
void Menu::printLine(char character, int amount) { printLine(character, amount, true); };
void Menu::printLine(char character) { printLine(character, 50, true); };
void Menu::printLine(char character, bool endLine) { printLine(character, 50, endLine); };
void Menu::printLine(int amount, bool endLine) { printLine('-', amount, endLine); };

void Menu::displayError(string errorMessage) {
	cout << "-" << pad("ERROR!", 48) << "-" << endl;
	cout << pad(errorMessage, 50) << endl;
	printLine(true);
	cout << endl;
};

void Menu::displayImportant(string message) {
	cout << pad('#', "IMPORTANT!", 50) << endl;
	cout << pad('#', message, 50) << endl;
	printLine('#', 50, true);
	cout << endl;
};

string Menu::pad(char character, string message, int length) {
	string result = "";
	float padAmount = (length - message.length()) / 2.0f;
	for (int i = 0; i < (int)padAmount-1; i++) result += character;
	result += " ";
	result += message;
	result += " ";
	if (fmod(padAmount, 1) > 0) padAmount++;
	for (int i = 0; i < (int)padAmount-1; i++) result += character;
	return result;
};
string Menu::pad(string message, int length) { return pad('-', message, length); };
string Menu::pad(string message) { return pad('-', message, 50); };
string Menu::pad(char character, string message) { return pad(character, message, 50); };

double Menu::calculateCost(double cost, int discount) {
	if (discount == 0) return cost;
	return cost - (cost / 100 * discount);
};

// menu functions
void Menu::main(bool shouldClear) {
	if (shouldClear) clear();
	cout << "[MAIN MENU]  Please select an option by entering the corresponding number and pressing enter..." << endl;
	cout << "\t1. View the pet shop's pets" << endl;
	cout << "\t2. View your pets" << endl;
	cout << "\t3. QUIT" << endl;
	int input; cin >> input;
	if (input == 1) {
		if (getPetShop().getPets().size() > 0) pets();
		else {
			clear();
			displayError("THE PET SHOP CURRENTLY HAS NO PETS TO VIEW!");
			main(false);
		}
	} else if (input == 2) {
		if (getCustomer().getPets().size() > 0) customerPets();
		else {
			clear();
			displayError("YOU DO NOT HAVE ANY PETS TO VIEW!");
			main(false);
		}
	} else if (input == 3) {
		clear();
		cout << "Goodbye!" << endl;
	} else {
		clear();
		displayError("THAT IS NOT A VALID OPTION! TRY AGAIN!");
		main(false);
	}
};
void Menu::main() { main(true); };

void Menu::pets(int petIndex, bool shouldClear) {
	if (shouldClear) clear();
	vector <Pet> petList = getPetShop().getPets();
	if (petList.size() > 0) {
		if (petIndex < 0) {
			displayError("YOU ARE ALREADY VIEWING THE FIRST PAGE!");
			petIndex = 0;
		} else if (petIndex >= petList.size()) {
			displayError("YOU ARE ALREADY VIEWING THE LAST PAGE!");
			petIndex = petList.size() - 1;
		}
		petList[petIndex].display();
	}
	cout << "[PETS]  Please select an option by entering the corresponding number and pressing enter..." << endl;
	cout << "\t1. Previous pet" << endl;
	cout << "\t2. Next pet" << endl;
	cout << "\t3. Jump to pet ID" << endl;
	cout << "\t4. Adopt pet" << endl;
	cout << "\t5. Back to menu" << endl;
	int input; cin >> input;
	if (input == 1) pets(petIndex - 1);
	else if (input == 2) pets(petIndex + 1);
	else if (input == 3) petID();
	else if (input == 4) adopt(petIndex, true);
	else if (input == 5) main();
	else {
		clear();
		displayError("THAT IS NOT A VALID OPTION! TRY AGAIN!");
		pets(petIndex, false);
	}
};
void Menu::pets(int petIndex) { pets(petIndex, true); };
void Menu::pets(bool shouldClear) { pets(0, shouldClear); };
void Menu::pets() { pets(0, true); };

void Menu::customerPets(int petIndex, bool shouldClear) {
	if (shouldClear) clear();
	vector <Pet> petList = getCustomer().getPets();
	if (petList.size() > 0) {
		if (petIndex < 0) {
			displayError("YOU ARE ALREADY VIEWING THE FIRST PAGE!");
			petIndex = 0;
		} else if (petIndex >= petList.size()) {
			displayError("YOU ARE ALREADY VIEWING THE LAST PAGE!");
			petIndex = petList.size() - 1;
		}
		petList[petIndex].display();
	}
	cout << "[YOUR PETS]  Please select an option by entering the corresponding number and pressing enter..." << endl;
	cout << "\t1. Previous pet" << endl;
	cout << "\t2. Next pet" << endl;
	cout << "\t3. Jump to pet ID" << endl;
	cout << "\t4. Release pet" << endl;
	cout << "\t5. Back to menu" << endl;
	int input; cin >> input;
	if (input == 1) customerPets(petIndex - 1);
	else if (input == 2) customerPets(petIndex + 1);
	else if (input == 3) /* TODO: petID() but for customer pets */;
	else if (input == 4) /* TODO: release customer pet */;
	else if (input == 5) main();
	else {
		clear();
		displayError("THAT IS NOT A VALID OPTION! TRY AGAIN!");
		customerPets(petIndex, false);
	}
};
void Menu::customerPets(int petIndex) { customerPets(petIndex, true); };
void Menu::customerPets(bool shouldClear) { customerPets(0, shouldClear); };
void Menu::customerPets() { customerPets(0, true); };

void Menu::petID(bool shouldClear) {
	if (shouldClear) clear();
	cout << "[PETS/ID]  Please enter the ID of the pet you wish to view. Alternatively, type 'cancel' to go back to the main menu." << endl;
	vector<Pet> petList = getPetShop().getPets();
	string input; cin >> input;
	if (input == "cancel") return main();

	int id = stoi(input);
	// check if pet id exists, otherwise display error
	for (int i = 0; i < petList.size(); i++) {
		Pet pet = petList[i];
		if (pet.getID() == id) return pets(i, true);
	}
	clear();
	displayError("THAT IS NOT A VALID PET ID! TRY AGAIN!");
	petID(false);
};
void Menu::petID() { petID(true); };

void Menu::adopt(int petIndex, bool shouldClear) {
	if (shouldClear) clear();
	cout << "[ADOPT]  You are about to adopt the following pet:" << endl << endl;
	vector<Pet> petList = getPetShop().getPets();
	Pet pet = petList[petIndex];
	pet.display();
	double petCost = calculateCost(pet.getCost(), cust.getDiscount());
	cout << endl << "Adopting " << pet.getName() << " will cost " << petCost << (cust.getDiscount() ? " ("+to_string(cust.getDiscount())+"% off!)" : "") << "." << endl;
	cout << "Are you sure you want to adopt this pet?" << endl;
	cout << "Enter 'y' for yes or 'n' for no:" << endl << "\t";
	string input; cin >> input;
	if (input == "y" || input == "Y") {
		cust.adopt(pet);
		shop.removePet(petIndex);
		clear();
		displayImportant("You have just adopted " + pet.getName() + "!");
		main(false);
	} else if (input == "n" || input == "N") pets(petIndex, true);
	else {
		clear();
		displayError("THAT WAS AN INCORRECT RESPONSE. TRY AGAIN!");
		adopt(petIndex, false);
	};
};
void Menu::adopt(bool shouldClear) {
	if (shouldClear) clear();
	cout << "[ADOPT]  Please enter the ID of the pet you wish to adopt and press enter. Alternatively, type 'cancel' to go back to the main menu." << endl;
	string input; cin >> input;
	if (input == "cancel") main();
	else {
		int petIndex = stoi(input);
		vector<Pet> petList = getPetShop().getPets();
		if (petIndex < 0 || petIndex >= petList.size()) {
			clear();
			displayError("THAT IS NOT A VALID PET ID! TRY AGAIN!");
			adopt(false);
		} else adopt(petIndex, true);
	}
};
void Menu::adopt() { adopt(true); };
void Menu::adopt(int petIndex) { adopt(petIndex, true); };