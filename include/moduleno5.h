
#ifndef MODULENO5_H
#define MODULENO5_H

#include <iostream>
#include <string>

class Review {
private:
    int id;
    int foodRating;
    int deliveryRating;
    std::string kitchen;
    std::string comment;

public:
    Review(int i, std::string k, int f, int d, std::string c);

    int getFoodRating();
    int getDeliveryRating();
    void display();
};

class AnalyticsEngine {
public:
    double averageFood(Review reviews[], int n);
    double averageDelivery(Review reviews[], int n);
};

#endif
