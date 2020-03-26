#pragma once
#include <vector>
#include "pet.h"
#include "customer.h"

class PetShop {
private:
	int latestPetID = 0,
		latestCustomerID = 0;
	vector<Pet> pets = {};
	vector<string> names = {"Poppy", "Bella", "Molly", "Alfie", "Charlie", "Daisy", "Rosie", "Teddy", "Lola", "Millie",
		"Tilly", "Lola", "Coco", "Luna", "Phoebe", "Yuki"};
	vector<string> dogBreeds = {"Labrador Retriever", "German Shepherd", "Golden Retriever", "French Bulldog", "Bulldog",
		"Beagle", "Poodle", "Rottweiler", "German Shorthaired Pointer", "Yorkshire Terrier"};
	vector<string> catBreeds = {"Siamese", "Persian", "Maine Coon", "Ragdoll", "Bengal", "Abyssinian", "Birman",
		"Oriental Shorthair", "Sphynx", "Devon Rex", "Himalayan", "American Shorthair", "Russian Blue"};
	vector<Customer> customers = {};
public:
	// getters
	int getNewPetID() { return latestPetID++; };
	int getNewCustomerID() { return latestCustomerID++; };
	vector<Pet> getPets() { return pets; };
	vector<Customer> getCustomers() { return customers; };
	// functions
	void generatePets(int amount);
	void addPet(Pet pet);
	void removePet(int petIndex);
	void addCustomer(Customer customer);
};