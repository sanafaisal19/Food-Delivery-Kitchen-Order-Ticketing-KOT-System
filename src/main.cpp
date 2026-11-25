
#include <iostream>
#include "../include/moduleno5.h"

using namespace std;

int main() {

    Review reviews[3] = {
        Review(1, "Online Kitchen", 5, 4,
        "Good food and quick delivery."),

        Review(2, "Online Kitchen", 4, 5,
        "Very tasty food."),

        Review(3, "Online Kitchen", 5, 4,
        "Excellent experience.")
    };

    cout << "===== CUSTOMER REVIEWS =====" << endl;

    for (int i = 0; i < 3; i++) {
        reviews[i].display();
        cout << "------------------------" << endl;
    }

    AnalyticsEngine a;

    cout << endl;
    cout << "===== KITCHEN ANALYTICS =====" << endl;

    cout << "Average food rating: "
         << a.averageFood(reviews, 3) << "/5" << endl;

    cout << "Average delivery rating: "
         << a.averageDelivery(reviews, 3) << "/5" << endl;

    return 0;
}
