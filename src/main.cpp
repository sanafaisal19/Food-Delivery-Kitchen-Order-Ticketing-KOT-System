#include <iostream>
#include "restaurant_menu_management.h"

using namespace std;

int main() {

    // Creating Restaurant Object
    Restaurant kitchen("ONLINE KITCHEN");

    // Adding Chinese Dishes
    kitchen.addDish(Dish("Chowmin", "Chinese", 450));
    kitchen.addDish(Dish("Manchurian", "Chinese", 550));
    kitchen.addDish(Dish("Black Pepper Chicken", "Chinese", 750));
    kitchen.addDish(Dish("Hotpot", "Chinese", 800));

    // Adding Continental Dishes
    kitchen.addDish(Dish("Steaks", "Continental", 1200));

    // Adding Fast Food
    kitchen.addDish(Dish("Fries", "Fast Food", 250));
    kitchen.addDish(Dish("Shawarma", "Fast Food", 300));
    kitchen.addDish(Dish("Burger", "Fast Food", 450));
    kitchen.addDish(Dish("Loaded Fries", "Fast Food", 400));
    kitchen.addDish(Dish("Curly Fries", "Fast Food", 300));

    // Adding Momos
    kitchen.addDish(Dish("Steamed Momos", "Momos", 350));
    kitchen.addDish(Dish("Chilli Momos", "Momos", 400));
    kitchen.addDish(Dish("Gravy Momos", "Momos", 450));
    kitchen.addDish(Dish("Cheese Momos", "Momos", 500));

    // Adding Rice Dishes
    kitchen.addDish(Dish("Chicken Biryani", "Rice", 300));
    kitchen.addDish(Dish("Beef Biryani", "Rice", 400));
    kitchen.addDish(Dish("Mutton Biryani", "Rice", 550));
    kitchen.addDish(Dish("Sajji with Rice", "Rice", 1300));

    // Adding Desi Dishes
    kitchen.addDish(Dish("Karahi", "Desi", 1000));
    kitchen.addDish(Dish("Boneless Handi", "Desi", 900));
    kitchen.addDish(Dish("Chicken Nihari", "Desi", 400));
    kitchen.addDish(Dish("Beef Nihari", "Desi", 500));
    kitchen.addDish(Dish("Mutton Nihari", "Desi", 650));
    kitchen.addDish(Dish("Brain Masala", "Desi", 700));
    kitchen.addDish(Dish("Haleem", "Desi", 250));

    // Adding Side Dishes
    kitchen.addDish(Dish("Raita", "Side", 80));

    // Adding Platters
    kitchen.addDish(Dish("Sajji Platter", "Platter", 1800));
    kitchen.addDish(Dish("Beef Platter", "Platter", 2000));
    kitchen.addDish(Dish("Mutton Platter", "Platter", 2200));

    // Adding Desserts
    kitchen.addDish(Dish("Kunafa", "Dessert", 450));
    kitchen.addDish(Dish("Ice Cream", "Dessert", 200));

    // Adding Tandoori and Bread Items
    kitchen.addDish(Dish("Cheese Naan", "Tandoori", 250));
    kitchen.addDish(Dish("Kulchay", "Bread", 80));
    kitchen.addDish(Dish("Kulcha", "Bread", 70));

    // Adding Breakfast Items
    kitchen.addDish(Dish("Chanay", "Breakfast", 180));
    kitchen.addDish(Dish("Halwa", "Breakfast", 150));
    kitchen.addDish(Dish("Puri", "Breakfast", 50));
    kitchen.addDish(Dish("Kachori", "Breakfast", 80));

    // Adding Chicken Dish
    kitchen.addDish(Dish("Red Sauce Chicken", "Chicken", 750));

    // Adding Beverages
    kitchen.addDish(Dish("Chillers", "Beverage", 180));
    kitchen.addDish(Dish("Cold Drink", "Beverage", 100));


    // Display Complete Menu
    kitchen.displayMenu();


    // Search Dish
    cout << "\nSearch result for Chicken Biryani:\n";

    kitchen.searchDish("Chicken Biryani");

    return 0;
}
