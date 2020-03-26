#include <iostream>
#include <vector>
#include "pet.h"
#include "pet_cat.h"
#include "customer.h"
#include "petshop.h"
#include "menu.h"

using namespace std;

int main() {
    // set seed for rand
    srand(time(NULL));

    // create pet shop
    PetShop shop = PetShop();

    // get customer info
    string name, address;
    int age;
    Menu::clear();
    cout << "Please enter your name:" << endl << "\t";
    getline(cin, name);
    Menu::clear();
    cout << "Please enter your address:" << endl << "\t";
    getline(cin, address);
    Menu::clear();
    cout << "Please enter your age:" << endl << "\t";
    cin >> age;

    // create customer
    Customer customer = Customer(name, address, age);
    shop.addCustomer(customer);

    // generate pets
    shop.generatePets(5);
    cout << shop.getPets().size();

    // menu
    Menu menu = Menu(shop);
    menu.setCustomer(customer);
    menu.main();
}