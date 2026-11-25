#ifndef KDS_AND_KOT_SYSTEM_H
#define KDS_AND_KOT_SYSTEM_H

#include <string>
#include <vector>

class OrderItem {
private:
    std::string name;
    int quantity;
    int prepMinutes;
    std::string station;
    double price;

public:
    OrderItem(std::string n, int q, int prep, std::string st, double p);

    std::string getName() const { return name; }
    int getQuantity() const { return quantity; }
    std::string getStation() const { return station; }

    bool setQuantity(int q);
    int totalPrepTime() const;
    double subtotal() const;
};

class KitchenTicket {
private:
    int ticketId;
    std::string customerName;
    std::string orderType;
    std::vector<OrderItem> items;
    std::string status;

public:
    KitchenTicket(int id, std::string customer, std::string type);

    int getId() const { return ticketId; }
    std::string getCustomerName() const { return customerName; }
    std::string getStatus() const { return status; }

    bool setCustomerName(std::string name);
    void addItem(const OrderItem& item);
    bool advanceStatus();
    bool cancel();
    int estimatedMinutes() const;
    double totalPrice() const;
    void display() const;
};

class Station {
private:
    std::string name;
    int currentLoad;
    int ticketsHandled;

public:
    Station(std::string n);

    std::string getName() const { return name; }
    int getLoad() const { return currentLoad; }

    bool addWork(int minutes);
    void display() const;
};

class KitchenDisplaySystem {
private:
    std::vector<KitchenTicket> tickets;
    std::vector<Station> stations;
    int nextTicketId;

    Station* findStation(const std::string& name);

public:
    KitchenDisplaySystem();

    int createTicket(const std::string& customer, const std::string& type,
                     const std::vector<OrderItem>& items);
    KitchenTicket* findTicket(int id);
    bool advanceTicket(int id);
    bool cancelTicket(int id);
    void showBoard() const;
    void showStations() const;
};

#endif