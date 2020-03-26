#include <iostream>
#include "pet_dog.h"
#include "pet.h"

using namespace std;

Dog::Dog(void) {
	setBreed("No breed entered...");
	setPetType("Dog (" + getBreed() + ")");
};

Dog::Dog(string breed) {
	setBreed(breed);
	setPetType("Dog (" + getBreed() + ")");
};

Dog::Dog(string breed, string name) {
	setBreed(breed);
	setName(name);
	setPetType("Dog (" + getBreed() + ")");
}

Dog::Dog(string breed, string name, string description) {
	setBreed(breed);
	setName(name);
	setDescription(description);
	setPetType("Dog (" + getBreed() + ")");
};