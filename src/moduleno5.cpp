
#include "../include/moduleno5.h"

using namespace std;

Review::Review(int i, string k, int f, int d, string c) {
    id = i;
    kitchen = k;
    foodRating = f;
    deliveryRating = d;
    comment = c;
}

int Review::getFoodRating() {
    return foodRating;
}

int Review::getDeliveryRating() {
    return deliveryRating;
}

void Review::display() {
    cout << "Review #" << id << " | " << kitchen << endl;
    cout << "Food: " << foodRating << "/5" << endl;
    cout << "Delivery: " << deliveryRating << "/5" << endl;
    cout << "Comment: " << comment << endl;
}

double AnalyticsEngine::averageFood(Review reviews[], int n) {
    if (n <= 0) return 0;

    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += reviews[i].getFoodRating();
    }

    return (double)sum / n;
}

double AnalyticsEngine::averageDelivery(Review reviews[], int n) {
    if (n <= 0) return 0;

    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += reviews[i].getDeliveryRating();
    }

    return (double)sum / n;
}
