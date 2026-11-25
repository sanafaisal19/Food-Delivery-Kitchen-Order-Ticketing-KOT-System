#ifndef RESTAURANT_MENU_MANAGEMENT_H
#define RESTAURANT_MENU_MANAGEMENT_H

#include <iostream>
#include <string>
using namespace std;

// Dish Class
class Dish {
private:
    string name;
    string category;
    double price;
    bool available;

public:
    Dish();
    Dish(string n, string c, double p);

    string getName();
    double getPrice();
    bool getAvailability();

    void setPrice(double p);
    void setAvailability(bool a);

    void display();
};

// Restaurant Class
class Restaurant {
private:
    string name;
    Dish menu[50];
    int count;

public:
    Restaurant(string n);

    void addDish(Dish d);
    void displayMenu();
    void searchDish(string n);
};

#endif
