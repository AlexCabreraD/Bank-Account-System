#include "FileManager.h"

#include "FileManager.h"
#include <fstream>
#include <iostream>

// Constructor
FileManager::FileManager() {
    // Constructor logic if needed, e.g., setting a file path
}

// Loads accounts from a file and returns them as a list
std::list<Account> FileManager::loadAccounts() {
    std::list<Account> accounts;
    std::ifstream file("accounts.txt"); // Open the file

    if (!file) {
        std::cerr << "Error opening file for reading!" << std::endl;
        return accounts; // Return empty list if file can't be opened
    }

    std::string accountNumber, accountHolderName, accountType;
    double balance;
    bool isActive;

    // Loop to read account data line-by-line
    while (std::getline(file, accountNumber)) {
        std::getline(file, accountHolderName);
        file >> balance;
        file.ignore(); // Ignore newline character after reading balance
        std::getline(file, accountType);
        file >> isActive;
        file.ignore(); // Ignore newline character after reading isActive

        // Create account with read values and add to the list
        Account account(accountNumber, accountHolderName, accountType, balance, isActive);

        accounts.push_back(account); // Add account to the list
    }

    file.close(); // Close the file
    return accounts;
}

// Saves accounts to a file
void FileManager::saveAccounts(const std::list<Account>& accounts) {
    std::ofstream file("accounts.txt"); // Open file for writing

    if (!file) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return;
    }

    // Write each account's data to the file
    for (const auto& account : accounts) {
        file << account.getAccountNumber() << '\n';
        file << account.getAccountHolderName() << '\n';
        file << account.getBalance() << '\n';
        file << account.getAccountType() << '\n';
        file << account.isAccountActive() << '\n';
    }

    file.close(); // Close the file
}
