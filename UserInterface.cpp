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

void UserInterface::getUserInput() {
    std::string input;
    
    while (true) {
        std::getline(std::cin, input);
        // TODO: HERE PROCCESS INPUTS
        if (input == "exit") {
            break;
        }
        // TODO: HERE HANDLE BEFORE APP CLOSES (IF ANY)
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