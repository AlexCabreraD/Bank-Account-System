#include "Transaction.h"
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

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
        << "\nDescription: " << description;

    // Using localtime_s safely with a tm structure
    char timeBuffer[26]; // Buffer size for asctime_s (usually 26 characters)
    struct tm timeInfo;  // tm structure to hold local time information

    // Populate timeInfo using localtime_s
    if (localtime_s(&timeInfo, &timestamp) == 0 && asctime_s(timeBuffer, sizeof(timeBuffer), &timeInfo) == 0) {
        details << "\nTimestamp: " << timeBuffer;
    }
    else {
        details << "\nTimestamp: Error formatting timestamp";
    }

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