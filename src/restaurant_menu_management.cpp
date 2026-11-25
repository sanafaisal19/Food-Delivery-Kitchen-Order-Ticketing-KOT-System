
#include "restaurant_menu_management.h"

// =================================
// DISH CLASS FUNCTION DEFINITIONS
// =================================

Dish::Dish() {
    name = "";
    category = "";
    price = 0;
    available = true;
}

Dish::Dish(string n, string c, double p) {
    name = n;
    category = c;
    price = p;
    available = true;
}

string Dish::getName() {
    return name;
}

double Dish::getPrice() {
    return price;
}

bool Dish::getAvailability() {
    return available;
}

void Dish::setPrice(double p) {
    if (p >= 0) {
        price = p;
    }
}

void Dish::setAvailability(bool a) {
    available = a;
}

void Dish::display() {
    cout << name << " | "
         << category << " | Rs. "
         << price << " | "
         << (available ? "Available" : "Unavailable")
         << endl;
}


// =================================
// RESTAURANT CLASS FUNCTION DEFINITIONS
// =================================

Restaurant::Restaurant(string n) {
    name = n;
    count = 0;
}

void Restaurant::addDish(Dish d) {
    if (count < 50) {
        menu[count] = d;
        count++;
    }
}

void Restaurant::displayMenu() {
    cout << "\n===== " << name << " MENU =====\n";

    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". ";
        menu[i].display();
    }
}

void Restaurant::searchDish(string n) {
    bool found = false;

    for (int i = 0; i < count; i++) {
        if (menu[i].getName() == n) {
            menu[i].display();
            found = true;
        }
    }

    if (!found) {
        cout << "Dish not found.\n";
    }
}
