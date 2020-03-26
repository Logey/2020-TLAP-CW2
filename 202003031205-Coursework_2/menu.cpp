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
Menu::Menu(PetShop petShop) { setPetShop(petShop); };
Menu::Menu(Customer customer) { setCustomer(customer); };
Menu::Menu(PetShop petShop, Customer customer) { setPetShop(petShop); setCustomer(customer); };

// utility functions
void Menu::clear() { for (int i = 0; i < 100; i++) cout << endl; };

void Menu::printLine(int amount, bool endLine) {
	for (int i = 0; i < amount; i++) cout << "-";
	if (endLine) cout << endl;
};
void Menu::printLine() { printLine(50, true); };
void Menu::printLine(int amount) { printLine(amount, true); };
void Menu::printLine(bool endLine) { printLine(50, endLine); };

void Menu::displayError(string errorMessage) {
	printLine();
	cout << pad(errorMessage, 50) << endl;
	printLine();
	cout << endl;
};

string Menu::pad(string message, int length) {
	string result = "";
	float padAmount = (length - message.length()) / 2.0f;
	for (int i = 0; i < (int)padAmount-1; i++) result += "-";
	result += " ";
	result += message;
	result += " ";
	if (fmod(padAmount, 1) > 0) padAmount++;
	for (int i = 0; i < (int)padAmount-1; i++) result += "-";
	return result;
};

// menu functions
void Menu::main(bool shouldClear) {
	if (shouldClear) clear();
	cout << "[MAIN MENU]  Please select an option by entering the corresponding number and pressing enter..." << endl;
	cout << "\t1. View pets" << endl;
	cout << "\t2. QUIT" << endl;
	int input; cin >> input;
	if (input == 1) {
		if (getPetShop().getPets().size() > 0) pets();
		else {
			clear();
			displayError("THE PET SHOP CURRENTLY HAS NO PETS TO VIEW!");
			main(false);
		}
	} else if (input == 2) {
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
			petIndex = petList.size() - 1; // TODO: check if correct
		}
		//petList.at(petIndex)->display();
		for (unsigned i = 0; i < petList.size(); ++i) petList[i].display();
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

void Menu::petID(bool shouldClear) {
	if (shouldClear) clear();
	cout << "[PETS/ID]  Please enter the ID of the pet you wish to view..." << endl;
	int input; cin >> input;
	if (input < 0 || input >= getPetShop().getPets().size()) {
		clear();
		displayError("THAT IS NOT A VALID PET ID! TRY AGAIN!");
		petID(false);
	} else pets(input, true);
};
void Menu::petID() { petID(true); };

void Menu::adopt(int petIndex, bool shouldClear) {
	if (shouldClear) clear();
	cout << "[ADOPT]  You are about to adopt the following pet:" << endl << endl;
	vector<Pet> petList = getPetShop().getPets();
	Pet pet = petList.at(petIndex);
	pet.display();
	cout << endl << "Are you sure you want to adopt this pet?" << endl;
	cout << "Enter 'y' for yes or 'n' for no:" << endl << "\t";
	string input; cin >> input;
	if (input == "y" || input == "Y") {
		getCustomer().adopt(pet);
		shop.removePet(petIndex);
		clear();
		displayError("You have just adopted " + pet.getName() + "!");
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