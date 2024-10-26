#include "Account.h"
#include <iostream>
#include <iomanip>

// ANSI escape codes for styling
const std::string RESET = "\033[0m";
const std::string BOLD = "\033[1m";
const std::string UNDERLINE = "\033[4m";
const std::string GREEN = "\033[32m";
const std::string RED = "\033[31m";
const std::string YELLOW = "\033[33m";
const std::string CYAN = "\033[36m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";

// Default constructor
Account::Account() : accountNumber(""), accountHolderName(""), accountType("") {}

// Parameterized constructor
Account::Account(const std::string& accountNumber, const std::string& accountHolderName, const std::string& accountType)
    : accountNumber(accountNumber), accountHolderName(accountHolderName), accountType(accountType), balance(0.0), isActive(true) {}

// Parameterized constructor
Account::Account(const std::string& accountNumber, const std::string& accountHolderName, const std::string& accountType, const int& balance, const bool& isActive)
    : accountNumber(accountNumber), accountHolderName(accountHolderName), accountType(accountType), balance(balance), isActive(isActive) {}

// Close account - mark as inactive
void Account::closeAccount() {
    isActive = false;
    std::cout << CYAN << BOLD << "\n\nAccount closed." << RESET << std::endl;
}

// Deposit funds into the account
void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        logTransaction("Deposit", amount);
        std::cout << GREEN << BOLD << "\n\nDeposited: $" << amount << ". New balance: $" << getBalance() << RESET << std::endl;
    }
    else {
        std::cout << RED << "Invalid deposit amount!" << RESET << std::endl;
    }
}

// Withdraw funds from the account
void Account::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        logTransaction("Withdrawal", amount);
        std::cout << RED << BOLD << "\n\nWithdrew: $" << amount << ". New balance: $" << getBalance() << RESET << std::endl;
    }
    else {
        std::cout << RED << "Invalid withdrawal amount!" << RESET << std::endl;
    }
}

// Transfer funds to another account
void Account::transfer(Account& toAccount, double amount) {
    if (amount > 0 && amount <= balance) {
        withdraw(amount); // Withdraw from this account
        toAccount.deposit(amount); // Deposit into the target account
        logTransaction("Transfer", amount);
        std::cout << YELLOW << "\n\nTransferred: $" << amount << " to account " << toAccount.getAccountNumber() << RESET << std::endl;
    }
    else {
        std::cout << RED << "Invalid transfer amount!" << RESET << std::endl;
    }
}

// Log a transaction
void Account::logTransaction(const std::string& transactionType, double amount) {
    Transaction newTransaction(transactionType, amount, "Transaction for account: " + accountNumber);
    transactionHistory.push_back(newTransaction);
}

// Check if account is active
bool Account::isAccountActive() const {
    return isActive;
}

// Get current balance
double Account::getBalance() const {
    return balance;
}

// Retrieve transaction history
const std::list<Transaction>& Account::getTransactionHistory() const {
    return transactionHistory;
}

// Get account number
std::string Account::getAccountNumber() const {
    return accountNumber;
}

// Get account holder name
std::string Account::getAccountHolderName() const {
    return accountHolderName;
}

// Get account type
std::string Account::getAccountType() const {
    return accountType;
}

// Display account details
void Account::printAccountDetails() const {
    std::cout << BLUE << BOLD << "Account Details" << RESET << std::endl;
    std::cout << "=========================" << std::endl;
    std::cout << "Account Number: " << BOLD << accountNumber << RESET << std::endl;
    std::cout << "Account Holder: " << BOLD << accountHolderName << RESET << std::endl;
    std::cout << "Account Type: " << BOLD << accountType << RESET << std::endl;
    std::cout << "Balance: " << BOLD << "$" << std::fixed << std::setprecision(2) << balance << RESET << std::endl;
    std::cout << "Account Status: " << BOLD << (isActive ? "Active" : "Closed") << RESET << std::endl;
    std::cout << "=========================" << std::endl;
}
