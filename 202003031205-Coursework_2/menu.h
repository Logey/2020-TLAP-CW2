#pragma once
#include <string>
#include "petshop.h"
#include "customer.h"

using namespace std;

class Menu {
private:
	PetShop shop;
	Customer cust;
public:
	// constructors
	Menu(void);
	Menu(PetShop petShop, Customer customer);
	Menu(PetShop petShop);
	Menu(Customer customer);
	// setters
	void setPetShop(PetShop petShop) { shop = petShop; };
	void setCustomer(Customer customer) { cust = customer; };
	// getters
	PetShop getPetShop() { return shop; };
	Customer getCustomer() { return cust; };
	// utility functions
	static void clear();
	static void printLine(char character, int amount, bool endLine);
	static void printLine(char character, int amount);
	static void printLine(char character, bool endLine);
	static void printLine(char character);
	static void printLine(int amount, bool endLine);
	static void printLine(int amount);
	static void printLine(bool endLine);
	static void printLine();
	static void displayError(string errorMessage);
	static void displayImportant(string message);
	static string pad(char character, string message, int length);
	static string pad(string message, int length);
	static string pad(string message);
	static string pad(char character, string message);
	// menu functions
	void main(bool shouldClear);
	void main();
	void pets(int petIndex);
	void pets(int petIndex, bool shouldClear);
	void pets(bool shouldClear);
	void pets();
	void petID(bool shouldClear);
	void petID();
	void adopt(int petIndex, bool shouldClear);
	void adopt(int petIndex);
	void adopt(bool shouldClear);
	void adopt();
};