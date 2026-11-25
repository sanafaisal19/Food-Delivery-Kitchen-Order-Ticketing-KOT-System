#ifndef DELIVERY_ALLOCATION_H
#define DELIVERY_ALLOCATION_H

#include <string>

class DeliveryPartner {
private:
    int id;
    std::string name;
    double distance;
    double capacity;
    bool available;

public:
    DeliveryPartner(int i, const std::string& n, double d, double c);

    std::string getName() const;
    double getDistance() const;
    double getCapacity() const;

    bool isAvailable() const;
    void setAvailable(bool a);

    void display() const;
};

class DispatchEngine {
public:
    int assignPartner(
        DeliveryPartner drivers[],
        int count,
        double needed
    );
};

#endif