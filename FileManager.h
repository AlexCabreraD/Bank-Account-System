#include <list>
#include "Account.h"

#pragma once
class FileManager
{
public:
	//constructor
	FileManager();


	// Load accounts on app start
	std::list<Account> loadAccounts();

	// Save account changes before closing app
	void saveAccounts(const std::list<Account>& accounts);
};

