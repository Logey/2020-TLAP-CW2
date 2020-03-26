#pragma once

#include "pet.h"

using namespace std;

class Dog : public Pet {
private:
	string breed;
public:
	// constructors
	Dog(void);
	Dog(string dogBreed);
	Dog(string dogBreed, string dogName);
	Dog(string dogBreed, string dogName, string dogDescription);
	// getters
	string getBreed() { return breed; };
	// setters
	void setBreed(string dogBreed) { breed = dogBreed; };
};