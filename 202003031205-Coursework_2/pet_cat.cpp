#include <iostream>
#include "pet_cat.h"

Cat::Cat(void) {
	setBreed("No breed entered...");
	setPetType("Cat (" + getBreed() + ")");
};

Cat::Cat(string breed) {
	setBreed(breed);
	setPetType("Cat (" + getBreed() + ")");
};

Cat::Cat(string breed, string name) {
	setBreed(breed);
	setName(name);
	setPetType("Cat (" + getBreed() + ")");
};

Cat::Cat(string breed, string name, string desc) {
	setBreed(breed);
	setName(name);
	setDescription(desc);
	setPetType("Cat (" + getBreed() + ")");
};