#include <iostream>

#include "kds_and_kot_system.h"

using std::cout;

int main() {
    OrderItem burger("Spicy Burger", 2, 8, "Grill", 350);
    OrderItem fries("Large Fries", 1, 5, "Fryer", 200);
    OrderItem cola("Cola", 2, 1, "Drinks", 100);
    OrderItem ribs("BBQ Ribs", 1, 15, "Grill", 750);
    OrderItem salad("Caesar Salad", 1, 3, "Cold", 280);

    KitchenDisplaySystem kds;

    int t1 = kds.createTicket("Ali Khan", "Delivery", {burger, fries, cola});
    int t2 = kds.createTicket("Sara Ahmed", "Dine-In", {ribs, salad});

    cout << "\n>>> New tickets received in the kitchen:";
    kds.findTicket(t1)->display();
    kds.findTicket(t2)->display();

    kds.showBoard();
    kds.showStations();

    cout << "\n>>> Encapsulation check (validation in setters):\n";
    if (!burger.setQuantity(0))
        cout << "    Quantity 0 rejected. Quantity stays " << burger.getQuantity() << ".\n";
    if (burger.setQuantity(3))
        cout << "    Quantity updated to " << burger.getQuantity() << ".\n";
    if (!kds.findTicket(t1)->setCustomerName(""))
        cout << "    Empty customer name rejected.\n";

    cout << "\n>>> Cook starts ticket " << t1 << "...\n";
    kds.advanceTicket(t1);
    cout << ">>> Ticket " << t1 << " finished cooking...\n";
    kds.advanceTicket(t1);

    cout << ">>> Customer cancels ticket " << t2 << "...\n";
    if (kds.cancelTicket(t2)) cout << "    Ticket cancelled.\n";

    cout << ">>> Trying to cancel ticket " << t1 << " (already READY)...\n";
    if (!kds.cancelTicket(t1)) cout << "    Cannot cancel - food is already cooked.\n";

    kds.showBoard();

    return 0;
}