#pragma once

#include "pet.h"

using namespace std;

class Cat : public Pet {
private:
	string breed;
public:
	// constructors
	Cat(void);
	Cat(string catBreed);
	Cat(string catBreed, string catName);
	Cat(string catBreed, string catName, string catDescription);
	// getters
	string getBreed() { return breed; };
	// setters
	void setBreed(string catBreed) { breed = catBreed; };
};