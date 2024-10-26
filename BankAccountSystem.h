#include <list>
#include "Account.h"
#include "UserInterface.h"
#include "FileManager.h"

#pragma once

class BankAccountSystem {
public:
    // Constructor
    BankAccountSystem();

    // System Operation Methods
    void displayMenu();                // Display the main menu to the user
    void createAccount();              // Create a new account
    void depositFunds();               // Deposit funds into an account
    void withdrawFunds();              // Withdraw funds from an account
    void transferFunds();              // Transfer funds between accounts
    void viewAccountDetails();         // Display details of a specified account
    void viewTransactionHistory();     // Display transaction history for a specified account
    void loadAccountsFromFile();       // Load accounts from a file
    void saveAccountsToFile();         // Save accounts to a file
    void inputValidation();            // Validate user input (e.g., for account number or amount)
    void exitSystem();                 // Exit the system

private:
    // Attributes
    UserInterface ui;                  // Handles user interaction
    FileManager fileManager;           // Manages loading and saving of accounts to a file
    std::list<Account> accounts;     // List of accounts managed by the system

    // Helper Methods
    Account* findAccount(const std::string& accountNumber); // Locate an account by its number
};
