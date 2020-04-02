#pragma once
#include <string>
#include <time.h>

using namespace std;

class Pet {
protected:
	string name,
		description,
		type;
	bool trialPet = false;
	int id,
		moodIndex,
		energyLevel,
		hungerLevel,
		friendliness;
	double cost = 0.00;
public:
	// constructors
	Pet();
	// setters
	void setName(string petName) { name = petName; };
	void setDescription(string petDescription) { description = petDescription; };
	void setID(int petID) { id = petID; };
	void setEnergyLevel(int petEnergyLevel) { energyLevel = petEnergyLevel; };
	void setHungerLevel(int petHungerLevel) { hungerLevel = petHungerLevel; };
	void setFriendliness(int petFriendliness) { friendliness = petFriendliness; };
	void setTrial(bool petIsTrial) { trialPet = petIsTrial; };
	void setCost(double petCost) { cost = petCost; };
	void setPetType(string petType) { type = petType; };
	// getters
	string getName() { return name; };
	string getDescription() { return description; };
	int getID() { return id; };
	int getMoodIndex() { return moodIndex; };
	int getEnergyLevel() { return energyLevel; };
	int getHungerLevel() { return hungerLevel; };
	int getFriendliness() { return friendliness; };
	bool isTrial() { return trialPet; };
	double getCost() { return cost; };
	string getPetType() { return type; };
	// functions
	void display();
};