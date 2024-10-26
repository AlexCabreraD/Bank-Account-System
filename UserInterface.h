#include <string>
#include <list>
#include "Account.h"
#include "Transaction.h"

#pragma once

class UserInterface {
public:
    // Constructor
    UserInterface();

    // Menu Display
    void printMenu(); // Display the main menu to the user

    // User Input Handling
    int getUserInput(); // Get user input from the console
    std::string promptUserForInput(const std::string& promptMessage); // Prompt user with a message and return the input

    // Message Display
    void displayMessage(const std::string& message); // Display a message to the user

    // Account and Transaction Information
    void printAccountDetails(const Account& account); // Print details of a specific account
    void displayTransactionHistory(const std::list<Transaction>& history); // Display the transaction history for an account
};
