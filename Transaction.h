#include <string>
#include <ctime>

#pragma once

class Transaction {
public:
    // Constructor
    Transaction(const std::string& type, double amt, const std::string& desc); // Initializes a transaction with type, amount, and description
    Transaction(const std::string& type, double amt, const std::string& desc, const std::string transactionId, const time_t timestamp); // Initializes a transaction with all attributes

    // Methods
    std::string getTransactionDetails() const; // Returns a string with transaction details

    // Accessors
    std::string getTransactionType() const; // Get the type of transaction (e.g., "deposit", "withdrawal")
    double getAmount() const;               // Get the transaction amount
    time_t getTimestamp() const;            // Get the timestamp of when the transaction was created
    std::string getDescription() const;     // Get the description of the transaction

private:
    // Attributes
    std::string transactionType;   // Type of transaction
    double amount;                 // Amount involved in the transaction
    time_t timestamp;              // Time the transaction was created
    std::string transactionId;     // Unique identifier for the transaction
    std::string description;       // Description of the transaction

    // Helper Methods
    std::string generateTransactionId() const; // Generates a unique ID for the transaction
};
