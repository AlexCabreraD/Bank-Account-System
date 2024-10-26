#include "Account.h"
#include <iostream>
#include <iomanip>

// Default constructor
Account::Account() : accountNumber(""), accountHolderName(""), accountType("") {}

// Parameterized constructor
Account::Account(const std::string& accountNumber, const std::string& accountHolderName, const std::string& accountType)
    : accountNumber(accountNumber), accountHolderName(accountHolderName), accountType(accountType), balance(0.0), isActive(true) {}

// Close account - mark as inactive
void Account::closeAccount() {
    isActive = false;
    std::cout << "Account closed." << std::endl;
}

// Deposit funds into the account
void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        logTransaction("Deposit", amount);
        std::cout << "Deposited: $" << amount << ". New balance: $" << getBalance() << std::endl;
    }
    else {
        std::cout << "Invalid deposit amount!" << std::endl;
    }
}

// Withdraw funds from the account
void Account::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        logTransaction("Withdrawal", amount);
        std::cout << "Withdrew: $" << amount << ". New balance: $" << getBalance() << std::endl;
    }
    else {
        std::cout << "Invalid withdrawal amount!" << std::endl;
    }
}

// Transfer funds to another account
void Account::transfer(Account& toAccount, double amount) {
    if (amount > 0 && amount <= balance) {
        withdraw(amount); // Withdraw from this account
        toAccount.deposit(amount); // Deposit into the target account
        logTransaction("Transfer", amount);
        std::cout << "Transferred: $" << amount << " to account " << toAccount.accountNumber << std::endl;
    }
    else {
        std::cout << "Invalid transfer amount!" << std::endl;
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
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "Account Holder: " << accountHolderName << std::endl;
    std::cout << "Account Type: " << accountType << std::endl;
    std::cout << "Balance: $" << std::fixed << std::setprecision(2) << balance << std::endl;
    std::cout << "Account Status: " << (isActive ? "Active" : "Closed") << std::endl;
}
