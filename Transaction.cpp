#include "Transaction.h"
#include <sstream>
#include <iomanip>
#include <cstdlib>

Transaction::Transaction(const std::string& type, double amt, const std::string& desc)
	:transactionType(type),
	amount(amt),
	description(desc)
{
	timestamp = std::time(nullptr);
	transactionId = generateTransactionId();
}

// Get transaction details as a formatted string
std::string Transaction::getTransactionDetails() const {
    std::ostringstream details;
    details << "ID: " << transactionId
        << "\nType: " << transactionType
        << "\nAmount: $" << std::fixed << std::setprecision(2) << amount
        << "\nDescription: " << description
        << "\nTimestamp: " << std::asctime(std::localtime(&timestamp));
    return details.str();
}

// Getter methods
std::string Transaction::getTransactionType() const { return transactionType; }
double Transaction::getAmount() const { return amount; }
time_t Transaction::getTimestamp() const { return timestamp; }
std::string Transaction::getDescription() const { return description; }

// Generate a unique transaction ID
std::string Transaction::generateTransactionId() const {
    std::ostringstream id;
    id << "TX-" << timestamp << "-" << rand() % 1000; //Example output:TX-1698242047-487
    return id.str();
}