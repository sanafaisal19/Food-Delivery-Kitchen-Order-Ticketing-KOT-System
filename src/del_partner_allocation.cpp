#include "../include/del_partner_allocation.h"
#include <iostream>

DeliveryPartner::DeliveryPartner(
    int i,
    const std::string& n,
    double d,
    double c
) : id(i), name(n), distance(d), capacity(c), available(true) {
}

std::string DeliveryPartner::getName() const {
    return name;
}

double DeliveryPartner::getDistance() const {
    return distance;
}

double DeliveryPartner::getCapacity() const {
    return capacity;
}

bool DeliveryPartner::isAvailable() const {
    return available;
}

void DeliveryPartner::setAvailable(bool a) {
    available = a;
}

void DeliveryPartner::display() const {
    std::cout << "Driver: " << name
              << " | Distance from Online Kitchen: " << distance
              << " km | Bag: " << capacity
              << " kg | Available: "
              << (available ? "Yes" : "No")
              << std::endl;
}

int DispatchEngine::assignPartner(
    DeliveryPartner drivers[],
    int count,
    double needed
) {
    int best = -1;
    double shortest = 999999.0;

    for (int i = 0; i < count; i++) {

        if (drivers[i].isAvailable() &&
            drivers[i].getCapacity() >= needed &&
            drivers[i].getDistance() < shortest) {

            best = i;
            shortest = drivers[i].getDistance();
        }
    }

    if (best != -1) {
        drivers[best].setAvailable(false);
    }

    return best;
}