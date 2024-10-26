#include "BankAccountSystem.h"
#include <iostream>
#include <string>

BankAccountSystem::BankAccountSystem() {
    // Load existing accounts from file when the system starts
    loadAccountsFromFile();
}

// Display the main menu to the user
void BankAccountSystem::displayMenu() {
    int choice;
    do {
        ui.printMenu();  // Print the menu options
        choice = ui.getUserInput();  // Get user choice

        switch (choice) {
        case 1: createAccount(); break;
        case 2: depositFunds(); break;
        case 3: withdrawFunds(); break;
        case 4: transferFunds(); break;
        case 5: viewAccountDetails(); break;
        case 6: viewTransactionHistory(); break;
        case 7: saveAccountsToFile(); break;
        case 8: exitSystem(); break;
        default: ui.displayMessage("Invalid choice, please try again.");
        }
    } while (choice != 8);
}

// Create a new account
void BankAccountSystem::createAccount() {
    std::string accountNumber, accountHolderName, accountType;

    // Prompt for account details
    accountNumber = ui.promptUserForInput("Enter account number: ");
    accountHolderName = ui.promptUserForInput("Enter account holder name: ");
    accountType = ui.promptUserForInput("Enter account type (e.g., savings, checking): ");

    Account newAccount(accountNumber, accountHolderName, accountType);
    accounts.push_back(newAccount);  // Add the new account to the list
    ui.displayMessage("Account created successfully.");
}

// Deposit funds into an account
void BankAccountSystem::depositFunds() {
    std::string accountNumber = ui.promptUserForInput("Enter account number: ");
    Account* account = findAccount(accountNumber);

    if (account) {
        double amount = std::stod(ui.promptUserForInput("Enter amount to deposit: "));
        account->deposit(amount);
        ui.displayMessage("Deposit successful.");
    }
    else {
        ui.displayMessage("Account not found.");
    }
}

// Withdraw funds from an account
void BankAccountSystem::withdrawFunds() {
    std::string accountNumber = ui.promptUserForInput("Enter account number: ");
    Account* account = findAccount(accountNumber);

    if (account) {
        double amount = std::stod(ui.promptUserForInput("Enter amount to withdraw: "));
        account->withdraw(amount);
        ui.displayMessage("Withdrawal successful.");
    }
    else {
        ui.displayMessage("Account not found.");
    }
}

// Transfer funds between accounts
void BankAccountSystem::transferFunds() {
    std::string fromAccountNumber = ui.promptUserForInput("Enter your account number: ");
    Account* fromAccount = findAccount(fromAccountNumber);

    if (fromAccount) {
        std::string toAccountNumber = ui.promptUserForInput("Enter recipient's account number: ");
        Account* toAccount = findAccount(toAccountNumber);

        if (toAccount) {
            double amount = std::stod(ui.promptUserForInput("Enter amount to transfer: "));
            fromAccount->transfer(*toAccount, amount);
            ui.displayMessage("Transfer successful.");
        }
        else {
            ui.displayMessage("Recipient account not found.");
        }
    }
    else {
        ui.displayMessage("Your account not found.");
    }
}

// View details of a specified account
void BankAccountSystem::viewAccountDetails() {
    std::string accountNumber = ui.promptUserForInput("Enter account number: ");
    Account* account = findAccount(accountNumber);

    if (account) {
        account->printAccountDetails();
    }
    else {
        ui.displayMessage("Account not found.");
    }
}

// View transaction history for a specified account
void BankAccountSystem::viewTransactionHistory() {
    std::string accountNumber = ui.promptUserForInput("Enter account number: ");
    Account* account = findAccount(accountNumber);

    if (account) {
        const std::list<Transaction>& history = account->getTransactionHistory();
        ui.displayTransactionHistory(history);
    }
    else {
        ui.displayMessage("Account not found.");
    }
}

// Load accounts from a file
void BankAccountSystem::loadAccountsFromFile() {
    accounts = fileManager.loadAccounts();
    ui.displayMessage("Accounts loaded successfully.");
}

// Save accounts to a file
void BankAccountSystem::saveAccountsToFile() {
    fileManager.saveAccounts(accounts);
    ui.displayMessage("Accounts saved successfully.");
}

// Find an account by its number
Account* BankAccountSystem::findAccount(const std::string& accountNumber) {
    for (auto& account : accounts) {
        if (account.getAccountNumber() == accountNumber) {
            return &account;  // Return pointer to the found account
        }
    }
    return nullptr;  // Return nullptr if not found
}

// Exit the system
void BankAccountSystem::exitSystem() {
    saveAccountsToFile();
    ui.displayMessage("Exiting the system. Goodbye!");
}
