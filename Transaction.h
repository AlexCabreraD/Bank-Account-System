#include <string>
#include <ctime>

#pragma once

class Transaction {
public:
    // Constructor
    Transaction(const std::string& type, double amt, const std::string& desc);

    // Methods
    std::string getTransactionDetails() const;

    // Getter methods
    std::string getTransactionType() const;
    double getAmount() const;
    time_t getTimestamp() const;
    std::string getDescription() const;

private:
    // Attributes
    std::string transactionType;
    double amount;
    time_t timestamp;
    std::string transactionId;
    std::string description;

    // Helper methods
    std::string generateTransactionId() const;
};
