#include "kds_and_kot_system.h"

#include <iomanip>
#include <iostream>

using std::cout;
using std::left;
using std::setw;
using std::string;
using std::vector;

OrderItem::OrderItem(string n, int q, int prep, string st, double p)
    : name(n), quantity(q), prepMinutes(prep), station(st), price(p) {
    if (quantity < 1) quantity = 1;
}

bool OrderItem::setQuantity(int q) {
    if (q < 1) return false;
    quantity = q;
    return true;
}

int OrderItem::totalPrepTime() const {
    return prepMinutes * quantity;
}

double OrderItem::subtotal() const {
    return price * quantity;
}

KitchenTicket::KitchenTicket(int id, string customer, string type)
    : ticketId(id), customerName(customer), orderType(type),
      status("RECEIVED") {}

bool KitchenTicket::setCustomerName(string name) {
    if (name.empty()) return false;
    customerName = name;
    return true;
}

void KitchenTicket::addItem(const OrderItem& item) {
    items.push_back(item);
}

bool KitchenTicket::advanceStatus() {
    if (status == "RECEIVED") {
        status = "PREPARING";
        return true;
    }
    if (status == "PREPARING") {
        status = "READY";
        return true;
    }
    if (status == "READY") {
        status = "SERVED";
        return true;
    }
    return false;
}

bool KitchenTicket::cancel() {
    if (status == "RECEIVED" || status == "PREPARING") {
        status = "CANCELLED";
        return true;
    }
    return false;
}

int KitchenTicket::estimatedMinutes() const {
    int longest = 0;
    for (size_t i = 0; i < items.size(); i++) {
        int stationTotal = 0;
        for (size_t j = 0; j < items.size(); j++) {
            if (items[j].getStation() == items[i].getStation())
                stationTotal += items[j].totalPrepTime();
        }
        if (stationTotal > longest) longest = stationTotal;
    }
    return longest;
}

double KitchenTicket::totalPrice() const {
    double sum = 0;
    for (size_t i = 0; i < items.size(); i++)
        sum += items[i].subtotal();
    return sum;
}

void KitchenTicket::display() const {
    cout << "\n----------------------------------------------\n";
    cout << " KOT #" << ticketId << "   [" << status << "]\n";
    cout << "----------------------------------------------\n";
    cout << " Customer : " << customerName << "\n";
    cout << " Type     : " << orderType << "\n";
    cout << " ----------------------------------------------\n";
    cout << left << " " << setw(5) << "Qty" << setw(20) << "Item"
         << setw(10) << "Station" << "Subtotal\n";
    for (size_t i = 0; i < items.size(); i++) {
        cout << " " << setw(5) << items[i].getQuantity()
             << setw(20) << items[i].getName()
             << setw(10) << items[i].getStation()
             << "Rs. " << items[i].subtotal() << "\n";
    }
    cout << " ----------------------------------------------\n";
    cout << " Estimated prep time : " << estimatedMinutes() << " min\n";
    cout << " Total               : Rs. " << totalPrice() << "\n";
    cout << "----------------------------------------------\n";
}

Station::Station(string n) : name(n), currentLoad(0), ticketsHandled(0) {}

bool Station::addWork(int minutes) {
    if (minutes <= 0) return false;
    currentLoad += minutes;
    ticketsHandled++;
    return true;
}

void Station::display() const {
    cout << " " << left << setw(10) << name
         << "Tickets: " << setw(4) << ticketsHandled
         << "Load: " << currentLoad << " min\n";
}

KitchenDisplaySystem::KitchenDisplaySystem() : nextTicketId(1001) {
    stations.push_back(Station("Grill"));
    stations.push_back(Station("Fryer"));
    stations.push_back(Station("Cold"));
    stations.push_back(Station("Drinks"));
}

Station* KitchenDisplaySystem::findStation(const string& name) {
    for (size_t i = 0; i < stations.size(); i++) {
        if (stations[i].getName() == name) return &stations[i];
    }
    return nullptr;
}

int KitchenDisplaySystem::createTicket(const string& customer, const string& type,
                                       const vector<OrderItem>& items) {
    KitchenTicket ticket(nextTicketId, customer, type);
    for (size_t i = 0; i < items.size(); i++) {
        ticket.addItem(items[i]);
        Station* st = findStation(items[i].getStation());
        if (st != nullptr) st->addWork(items[i].totalPrepTime());
    }
    tickets.push_back(ticket);
    return nextTicketId++;
}

KitchenTicket* KitchenDisplaySystem::findTicket(int id) {
    for (size_t i = 0; i < tickets.size(); i++) {
        if (tickets[i].getId() == id) return &tickets[i];
    }
    return nullptr;
}

bool KitchenDisplaySystem::advanceTicket(int id) {
    KitchenTicket* t = findTicket(id);
    if (t == nullptr) return false;
    return t->advanceStatus();
}

bool KitchenDisplaySystem::cancelTicket(int id) {
    KitchenTicket* t = findTicket(id);
    if (t == nullptr) return false;
    return t->cancel();
}

void KitchenDisplaySystem::showBoard() const {
    cout << "\n==============================================\n";
    cout << "        KITCHEN DISPLAY SYSTEM - BOARD\n";
    cout << "==============================================\n";
    for (size_t i = 0; i < tickets.size(); i++) {
        cout << " KOT #" << tickets[i].getId() << "  " << left << setw(15)
             << tickets[i].getCustomerName() << tickets[i].getStatus() << "\n";
    }
}

void KitchenDisplaySystem::showStations() const {
    cout << "\n========== STATION WORKLOAD ==========\n";
    for (size_t i = 0; i < stations.size(); i++)
        stations[i].display();
}