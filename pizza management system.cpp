#include <iostream>
#include <map>
#include <sstream>
#include <iomanip>
#include <ctime>

using namespace std;

string doubleToString(double value) {
    stringstream ss;
    ss << fixed << setprecision(2) << value;
    return ss.str();
}

string intToString(int value) {
    stringstream ss;
    ss << value;
    return ss.str();
}

struct Employee {
    string name;
    string position;
    string phoneNumber;
};

class PizzaHutManagementSystem {
private:
    string name;
    string address;
    string phoneNumber;
    map<string, double> itemRates;
    double totalBill;
    string selectedItem;
    string selectedFlavor;
    string size;
    int paymentMethod;
    int confirmationNumber;
    string deliveryOption;
    string deliveryAddress;
    string specialRequest;
    pair<string, string> orderHistory;
    time_t orderTime;
    Employee employees[100]; // Assuming maximum 100 employees
    int numEmployees;
    pair<string, string> orderedItems[100]; // Assuming maximum 100 ordered items
    int numOrderedItems;

public:
    PizzaHutManagementSystem() {
        // Initialize item rates
        itemRates["Fajita"] = 10.99;
        itemRates["Pepperoni"] = 12.99;
        itemRates["Tikka"] = 11.99;
        itemRates["BBQ"] = 11.00;
        itemRates["Coke"] = 1.99;
        itemRates["Sprite"] = 1.99;
        itemRates["Fanta"] = 1.99;
        itemRates["Sting"] = 2.00;
        itemRates["Mountain Dew"] = 1.50;
        itemRates["Cheese Burger"] = 8.99;
        itemRates["Chicken Burger"] = 9.99;
        itemRates["Zinger Burger"] = 7.99;
        itemRates["Beef Burger"] = 10.00;
        itemRates["Crunch Burger"] = 7.00;

        // Initialize other member variables
        totalBill = 0.0;
        confirmationNumber = 1000; // Start confirmation numbers from 1000
        numEmployees = 0;
        numOrderedItems = 0;
    }

    // Method to check if an item has flavors
    bool hasFlavors(const string& item) {
        return (item == "Pizza");
    }

    void addEmployee(const string& name, const string& position, const string& phoneNumber) {
        if (numEmployees < 100) {
            employees[numEmployees].name = name;
            employees[numEmployees].position = position;
            employees[numEmployees].phoneNumber = phoneNumber;
            numEmployees++;
        }
    }

    void displayEmployees() {
        cout << "\nEmployee Information:" << endl;
        for (int i = 0; i < numEmployees; i++) {
            cout << "Name: " << employees[i].name << ", Position: " << employees[i].position << ", Phone Number: " << employees[i].phoneNumber << endl;
        }
    }

    void updateItemRate(const string& itemName, double newRate) {
        itemRates[itemName] = newRate;
    }

    // Function to display customer feedback
    void displayFeedback() {
        cout << "\nCustomer Feedback:" << endl;
        cout << "We value your feedback. Please share your experience with us!" << endl;
        // Code to fetch and display customer feedback from a database or file
    }

    void welcomeMessage() {
        cout << "Welcome to Pizza Hut Management System!" << endl;
        cout << "Enter your name: ";
        getline(cin, name);
        cout << "Enter your address: ";
        getline(cin, address);
        cout << "Enter your phone number: ";
        getline(cin, phoneNumber);
    }

    void displayItems() {
        cout << "\nAvailable Items:" << endl;
        cout << "1. Pizza" << endl;
        cout << "2. Cold Drinks" << endl;
        cout << "3. Burger" << endl;
    }

    void orderItem() {
        int itemNumber;
        cout << "\nEnter the item number to order: ";
        cin >> itemNumber;
        cin.ignore();

        switch (itemNumber) {
            case 1:
                orderPizza();
                break;
            case 2:
                orderColdDrink();
                break;
            case 3:
                orderBurger();
                break;
            default:
                cout << "Invalid item selected." << endl;
                return;
        }
    }

    void orderPizza() {
        cout << "Available Flavors:" << endl;
        cout << "1. Fajita" << endl;
        cout << "2. Pepperoni" << endl;
        cout << "3. Tikka" << endl;
        cout << "4. BBQ" << endl;
        int flavorNumber;
        cout << "\nEnter the flavor number to order: ";
        cin >> flavorNumber;
        cin.ignore();

        switch (flavorNumber) {
            case 1:
                selectedFlavor = "Fajita";
                break;
            case 2:
                selectedFlavor = "Pepperoni";
                break;
            case 3:
                selectedFlavor = "Tikka";
                break;
            case 4:
                selectedFlavor = "BBQ";
                break;
            default:
                cout << "Invalid flavor selected." << endl;
                return;
        }

        cout << "\nSelected Flavor: " << selectedFlavor << endl;

        double rate = itemRates[selectedFlavor];

        cout << "\nAvailable Sizes:" << endl;
        cout << "1. Small" << endl;
        cout << "2. Medium" << endl;
        cout << "3. Large" << endl;

        int sizeNumber;
        cout << "\nEnter the size number to order: ";
        cin >> sizeNumber;
        cin.ignore();

        switch (sizeNumber) {
            case 1:
                size = "Small";
                break;
            case 2:
                size = "Medium";
                break;
            case 3:
                size = "Large";
                break;
            default:
                cout << "Invalid size selected. Using default: Small" << endl;
                size = "Small";
                break;
        }

        orderedItems[numOrderedItems++] = make_pair("Pizza: " + selectedFlavor + " (" + size + ")", "");
        totalBill += rate;
    }

    void orderColdDrink() {
        cout << "Available Drinks:" << endl;
        cout << "1. Coke" << endl;
        cout << "2. Sprite" << endl;
        cout << "3. Fanta" << endl;
        cout << "4. Sting" << endl;
        cout << "5. Mountain Dew" << endl;
        cout << "Enter the drink number to order: ";
        int drinkNumber;
        cin >> drinkNumber;
        cin.ignore();
        string drink;
        switch (drinkNumber) {
            case 1:
                drink = "Coke";
                break;
            case 2:
                drink = "Sprite";
                break;
            case 3:
                drink = "Fanta";
                break;
            case 4:
                drink = "Sting";
                break;
            case 5:
                drink = "Mountain Dew";
                break;
            default:
                cout << "Invalid drink selected." << endl;
                return;
        }
        double rate = itemRates[drink];
        orderedItems[numOrderedItems++] = make_pair("Cold Drink: " + drink, "");
        totalBill += rate;
    }

    void orderBurger() {
        cout << "Available Burgers:" << endl;
        cout << "1. Cheese Burger" << endl;
        cout << "2. Chicken Burger" << endl;
        cout << "3. Zinger Burger" << endl;
        cout << "4. Beef Burger" << endl;
        cout << "5. Crunch Burger" << endl;
        int burgerNumber;
        cout << "\nEnter the burger number to order: ";
        cin >> burgerNumber;
        cin.ignore();
        string burger;
        switch (burgerNumber) {
            case 1:
                burger = "Cheese Burger";
                break;
            case 2:
                burger = "Chicken Burger";
                break;
            case 3:
                burger = "Zinger Burger";
                break;
            case 4:
                burger = "Beef Burger";
                break;
            case 5:
                burger = "Crunch Burger";
                break;
            default:
                cout << "Invalid burger selected." << endl;
                return;
        }
        double rate = itemRates[burger];
        orderedItems[numOrderedItems++] = make_pair("Burger: " + burger, "");
        totalBill += rate;
    }

    void selectPaymentMethod() {
        cout << "Payment Methods:" << endl;
        cout << "1. Cash on Delivery" << endl;
        cout << "2. Credit Card" << endl;
        cout << "Enter your payment method choice: ";
        cin >> paymentMethod;
        cin.ignore();

        if (paymentMethod == 2) {
            string accountNumber;
            cout << "Enter your account number: ";
            getline(cin, accountNumber);
            // Process credit card payment
        } else {
            // Process cash on delivery
        }
    }

    void generateConfirmationNumber() {
        confirmationNumber++; // Increment confirmation number for each order
    }

    void chooseDeliveryOption() {
        cout << "\nChoose Delivery Option:" << endl;
        cout << "1. Delivery" << endl;
        cout << "2. Pickup" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            deliveryOption = "Delivery";
            cout << "Enter your delivery address: ";
            getline(cin, deliveryAddress);
        } else if (choice == 2) {
            deliveryOption = "Pickup";
        } else {
            cout << "Invalid choice. Defaulting to Pickup." << endl;
            deliveryOption = "Pickup";
        }
    }

    void addSpecialRequest() {
        cout << "\nEnter any special requests (if any): ";
        getline(cin, specialRequest);
    }

    void addToOrderHistory() {
        // Not needed for array implementation
    }

    void displayOrderSummary() {
        cout << "\nOrder Summary:" << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Delivery Option: " << deliveryOption << endl;
        if (deliveryOption == "Delivery") {
            cout << "Delivery Address: " << deliveryAddress << endl;
        }
        cout << "Ordered Items:" << endl;
        for (int i = 0; i < numOrderedItems; i++) {
            cout << orderedItems[i].first << endl;
        }
        cout << "Total Bill: $" << doubleToString(totalBill) << endl;
        cout << "Payment Method: " << paymentMethod << endl;
        cout << "Confirmation Number: " << confirmationNumber << endl;
        cout << "Special Requests: " << specialRequest << endl;
        cout << "Order Time: " << ctime(&orderTime);
    }

    void startOrdering() {
        welcomeMessage();
        chooseDeliveryOption();
        displayItems();
        do {
            orderItem();
            cout << "Do you want to order something else? (yes/no): ";
            string choice;
            getline(cin, choice);
            if (choice != "yes") {
                break;
            }
        } while (true);
        selectPaymentMethod();
        addSpecialRequest();
        generateConfirmationNumber();
        time(&orderTime);
        displayOrderSummary();
    }

    void displayOrderHistory() {
        // Not needed for array implementation
    }
};

int main() {
    const string cyan = "\033[1;36m";
    const string yellow = "\033[1;33m";
    const string magenta = "\033[1;35m";
    const string green = "\033[1;32m";
    const string red = "\033[1;31m";
    const string reset = "\033[0m";
    cout << "\n";
    cout << cyan << "\t\t\t\t\t*********************************************************\n";
    
    cout << "\t\t\t\t\t* " << yellow << "************Pizza Hut Management System**************" << cyan << " *\n";
    
    cout << "\t\t\t\t\t*********************************************************\n\n";
    cout << magenta << "\t\t\t\t\t<< " << yellow << "****THANK YOU FOR VISITING OUR Pizza Restaurant****" << magenta << " >>\n\n\n\n";
    
    cout << reset;

    PizzaHutManagementSystem system;
    system.startOrdering();

    return 0;
}

