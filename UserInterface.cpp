#include <iostream>
#include <string>
#include "UserInterface.h"

// ANSI escape codes for styling
const std::string RESET = "\033[0m";
const std::string BOLD = "\033[1m";
const std::string UNDERLINE = "\033[4m";
const std::string GREEN = "\033[32m";
const std::string RED = "\033[31m";
const std::string YELLOW = "\033[33m";
const std::string CYAN = "\033[36m";
const std::string BLUE = "\033[34m";

// Default constructor
UserInterface::UserInterface() {}

void UserInterface::printMenu() {
    std::cout << BLUE << BOLD << "\n\n\n===== Bank Account System Menu =====" << RESET << "\n";
    std::cout << "1. Create Account\n";
    std::cout << "2. Deposit Funds\n";
    std::cout << "3. Withdraw Funds\n";
    std::cout << "4. Transfer Funds\n";
    std::cout << "5. View Account Details\n";
    std::cout << "6. View Transaction History\n";
    std::cout << "7. Close Account\n";
    std::cout << "8. Exit\n";
    std::cout << BLUE << BOLD << "====================================" << RESET << "\n\n\n";
}

int UserInterface::getUserInput() {
    std::string input;
    int choice = 0;

    while (true) {
        std::cout << YELLOW << "Please enter your choice (1-8): " << RESET;
        std::getline(std::cin, input);

        try {
            choice = std::stoi(input);

            if (choice < 1 || choice > 8) {
                std::cout << RED << "Choice must be between 1 and 8." << RESET << std::endl;
                continue;
            }

            return choice;
        }
        catch (const std::invalid_argument&) {
            std::cout << RED << "Invalid input. Please enter a valid number." << RESET << std::endl;
        }
        catch (const std::out_of_range&) {
            std::cout << RED << "Input is out of range. Please enter a number between 1 and 8." << RESET << std::endl;
        }
    }
}

std::string UserInterface::promptUserForInput(const std::string& promptMessage) {
    std::string input;

    std::cout << CYAN << promptMessage << RESET << std::endl;
    std::getline(std::cin, input);

    return input;
}

void UserInterface::displayMessage(const std::string& message) {
    std::cout << GREEN << message << RESET << std::endl;
}

void UserInterface::printAccountDetails(const Account& account) {
    account.printAccountDetails();
}

void UserInterface::displayTransactionHistory(const std::list<Transaction>& history) {
    std::cout << BLUE << BOLD << "Transaction History:" << RESET << "\n";
    for (const auto& transaction : history) {
        std::cout << transaction.getTransactionDetails() << std::endl;
    }
}
