#include "petshop.h"
#include "pet_cat.h"
#include "pet_dog.h"
#include <iostream>

void PetShop::generatePets(int amount) {
	for (int i = 0; i < amount; i++) {
		int petType = rand() % 2;
		string name = names.at(rand() % names.size());
		if (petType == 0) {
			string breed = dogBreeds.at(rand() % dogBreeds.size());
			Dog dog = Dog(breed, name);
			dog.setID(getNewPetID());
			addPet(dog);
		} else if (petType == 1) {
			string breed = catBreeds.at(rand() % catBreeds.size());
			Cat cat = Cat(breed, name);
			cat.setID(getNewPetID());
			addPet(cat);
		}
	}
};

void PetShop::addPet(Pet pet) {
	pets.push_back(pet);
};

void PetShop::removePet(int petIndex) {
	pets.erase(pets.begin()+petIndex);
};

void PetShop::addCustomer(Customer* customer) {
	customer->setID(getNewCustomerID());
	customers.push_back(customer);
};