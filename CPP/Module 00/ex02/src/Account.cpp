#include "Account.hpp"
#include <iostream>

//	1-3. Initialize "static members": shared across all instances
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

//	1-2. Create accounts in the constructor
Account::Account( int initial_deposit ) : _amount(initial_deposit) {

// initialize current account
	this->_accountIndex = Account::getNbAccounts();
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
// display current account
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";created" << std::endl;
	Account::_totalAmount += this->_amount;
	Account::_nbAccounts++;
}

Account::~Account( void ) {

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";closed" << std::endl;
	Account::_totalAmount -= this->_amount;
	Account::_nbAccounts--;
}

void	Account::_displayTimestamp( void ) {

	std::cout << "[19920104_091532] ";
}

//	2. Define related functions
int	Account::getNbAccounts( void ) {

	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void ) {

	return Account::_totalAmount;
}

int	Account::getNbDeposits( void ) {

	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {

	return Account::_totalNbWithdrawals;
}

//	1-1. Manage the display
//	3. Manage the display
void	Account::displayAccountsInfos( void ) {

	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts();
	std::cout << ";total:" << Account::getTotalAmount();
	std::cout << ";deposits:" << Account::getNbDeposits();
	std::cout << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

//	4. Define the rest of the functions
void	Account::makeDeposit( int deposit ) {

	Account::_displayTimestamp();
//	We deposit and withdraw one by one, just like this. Don't complicate things.
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit;
	this->_amount += deposit;
	this->_nbDeposits++;
//	Don't forget static members need the prefix "Account::"
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

void	Account::displayStatus( void ) const {

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";withdrawal:";
	if (withdrawal > this->checkAmount()) {
		std::cout << "refused" << std::endl;
		return false;
	}
	std::cout << withdrawal;
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_withdrawals:" << this->_nbDeposits << std::endl;
	return true;
}

int		Account::checkAmount( void ) const {

	return this->_amount;
}

// 1-1. Manage Account::displayAccountsInfos();
// 1-2. Accounts need to be created before displayed
// 	→ create in the constructor
// Account::Account( int initial_deposit ) : _amount(initial_deposit)
// 	initializes the member variable _amount of the Account class with the value of initial_deposit.
// 1-3. In the constructor, we realize that we need to initialize "static members".
// 2. Then define related functions.
// 3. Manage the display
// 4. Define the rest of the functions
// 4-1. Deposit
// 4-2. As seen in the log and tests.cpp, Account::displayStatus comes between the deposit and withdrawal.
// 	std::for_each applies a given function to each element in a range.
// 4-3. Withdrawal