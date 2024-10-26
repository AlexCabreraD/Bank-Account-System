#include <iostream>
#include "UserInterface.h"

UserInterface::UserInterface(){}

void UserInterface::printMenu() {
    std::cout << "===== Bank Account System Menu =====\n";
    std::cout << "1. Create Account\n";
    std::cout << "2. Deposit Funds\n";
    std::cout << "3. Withdraw Funds\n";
    std::cout << "4. Transfer Funds\n";
    std::cout << "5. View Account Details\n";
    std::cout << "6. View Transaction History\n";
    std::cout << "7. Close Account\n";
    std::cout << "8. Exit\n";
    std::cout << "====================================\n";
}

#include <iostream>
#include <string>

int UserInterface::getUserInput() {
    std::string input;
    int choice = 0;

    while (true) {
        std::getline(std::cin, input);

        try {
            choice = std::stoi(input);

            return choice;
        }
        catch (const std::invalid_argument&) {
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
        }
        catch (const std::out_of_range&) {
            std::cout << "Input is out of range. Please enter a number between 1 and 8." << std::endl;
        }
    }
}


std::string UserInterface::promptUserForInput(const std::string& promptMessage) {
    std::string input;

    std::cout << promptMessage << std::endl;
    std::getline(std::cin, input);

	return(input);
}

void UserInterface::displayMessage(const std::string& message){
	std::cout << message << std::endl;
}

void UserInterface::printAccountDetails(const Account& account) {
	account.printAccountDetails();
}

void UserInterface::displayTransactionHistory(const std::list<Transaction>& history) {
    std::cout << "Transaction History:\n";
    for (const auto& transaction : history) {
        std::cout << transaction.getTransactionDetails() << std::endl;
    }
}