#include <string>
#include <list>
#include <iomanip>
#include <sstream>

#include "Transaction.h"

#pragma once

class Account
{
public:
    // Constructors
    Account(); 
    Account(const std::string& accountNumber, const std::string& accountHolderName, const std::string& accountType);
    Account(const std::string& accountNumber, const std::string& accountHolderName, const std::string& accountType, const double& balance, const bool& isActive);

    // Account Management Methods
    void closeAccount();  // Mark the account as inactive

    // Transaction Methods
    void deposit(double amount);               // Add funds to the account
    void withdraw(double amount);              // Deduct funds from the account
    void transfer(Account& toAccount, double amount); // Transfer funds to another account
    void logTransaction(const std::string& transactionType, double amount); // Record a transaction

    // Accessors
    bool isAccountActive() const;                     // Check if account is active
    double getBalance() const;                        // Get current balance
    void printAccountDetails() const;                 // Display account details

    std::string getAccountNumber() const; // Get account number
    std::string getAccountHolderName() const; // Get account holder name
    std::string getAccountType() const; // Get account type 
    std::string getTransactionFileName() const; // Name of transactions file for this account
private:
    // Account Attributes
    std::string accountNumber;         // Unique identifier for the account
    std::string accountHolderName;     // Name of the account holder
    double balance = 0.0;              // Current balance in the account
    std::string accountType;           // Type of account (e.g., savings, checking)
    bool isActive = true;              // Status of the account (active or inactive)

    // Creates the transaction file for a user
    void createTransactionFile() const;

};

