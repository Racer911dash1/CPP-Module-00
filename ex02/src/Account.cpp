#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	_amount = initial_deposit;
	_totalAmount += _amount;
	_accountIndex = _nbAccounts;
	_nbAccounts += 1;
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";created\n";
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "closed\n";
}

int Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int Account::getTotalAmount( void )
{
	return _totalAmount;
}

int Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout	<< "accounts:" << _nbAccounts << ";"
				<< "total:" << _totalAmount << ";"
				<< "deposits:" << _totalNbDeposits << ";"
				<< "withdrawals:" << _totalNbWithdrawals << "\n";
}

void Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	_nbDeposits += 1;
	std::cout	<< "index:" << _accountIndex << ";"
			<< "p_amount:" << _amount << ";"
			<< "deposit:" << deposit << ";"
			<< "amount:" << _amount + deposit << ";"
			<< "nb_deposits:" << _nbDeposits << "\n";
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits += 1;
}

bool Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";";
	if (_amount > withdrawal)
	{
		_nbWithdrawals += 1;
		std::cout	<< "withdrawal:" << withdrawal << ";"
					<< "amount:" << _amount - withdrawal << ";"
					<< "nb_deposits:" << _nbWithdrawals << "\n";
		_amount -= withdrawal;
		_totalNbWithdrawals += 1;
		_totalAmount -= withdrawal;
		return (true);
	}
	std::cout	<< "withdrawal:refused\n";
	return (false);
}

int Account::checkAmount( void ) const
{
	return _amount;
}

void Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "deposits:" << _nbDeposits << ";"
				<< "withdrawals:" << _nbWithdrawals << "\n";
}

void Account::_displayTimestamp( void )
{
	std::time_t time = std::time(0);
	std::tm* now = std::localtime(&time);
	std::cout	<< "["
				<< std::setfill('0') << std::setw(4) << (now->tm_year + 1900)
				<< std::setfill('0') << std::setw(2) << (now->tm_mon + 1)
				<< std::setfill('0') << std::setw(2) << (now->tm_mday)
				<< "_"
				<< std::setfill('0') << std::setw(2) << (now->tm_hour)
				<< std::setfill('0') << std::setw(2) << (now->tm_min)
				<< std::setfill('0') << std::setw(2) << (now->tm_sec)
				<< "] ";
}
