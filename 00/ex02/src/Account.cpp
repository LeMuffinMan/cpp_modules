
#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;        
int Account::_totalNbDeposits = 0;     
int Account::_totalNbWithdrawals = 0; 

void Account::displayAccountsInfos(void)
{
  _displayTimestamp();
  std::cout << "accounts:" << getNbAccounts() << ";"
            << "total:" << getTotalAmount() << ";"
            << "deposits:" << getNbDeposits() << ";"
            << "withdrawals:" << getNbWithdrawals() << ";"
            << std::endl;
}

int Account::getNbAccounts(void)
{
  return _nbAccounts;
}

int Account::getTotalAmount(void)
{
  return _totalAmount;
}

int Account::getNbDeposits(void)
{
  return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
  return _totalNbWithdrawals;
}

void Account::_displayTimestamp()
{
    time_t  now = time(0);
    tm     *local = localtime(&now);

    std::cout << "["
              << 1900 + local->tm_year
              << (local->tm_mon + 1 < 10 ? "0" : "") << local->tm_mon + 1
              << (local->tm_mday < 10 ? "0" : "") << local->tm_mday
              << "_"
              << (local->tm_hour < 10 ? "0" : "") << local->tm_hour
              << (local->tm_min < 10 ? "0" : "") << local->tm_min
              << (local->tm_sec < 10 ? "0" : "") << local->tm_sec
              << "] ";
}

Account::Account(int initial_deposit)
{
  _displayTimestamp();
  _accountIndex = _nbAccounts;
  _nbAccounts++;
  _amount = initial_deposit;
  _totalAmount = _totalAmount + _amount;
  _nbDeposits = 0;
  _nbWithdrawals = 0;
  std::cout << "accounts: " << _nbAccounts << ";"
  				  << "total: " << _totalAmount << ";"
  				  << "deposits: " << _totalNbDeposits << ";"
  				  << "withdrawals: " << _totalNbWithdrawals << ";"
  				  << "created" << std::endl;
}

Account::~Account( void )
{
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
            << "amount:" << checkAmount() << ";"
            << "closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
  _displayTimestamp();
  _nbDeposits++;
  _amount = checkAmount() + deposit;
  std::cout << "index:" << _accountIndex << ";"
            << "p_amount:" << checkAmount() << ";"
            << "deposit:" << deposit << ";"
            << "amount:" << checkAmount() << ";"
            << "nb_deposits:" << _nbDeposits
            << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
  					<< "p_amount:" << checkAmount() << ";"
  					<< "withdrawal:";
  if (checkAmount() > withdrawal)
  {
    _amount = checkAmount() - withdrawal;
    _nbWithdrawals++;
    std::cout << withdrawal << ";"
    					<< "amount:" << checkAmount() << ";"
    					<< "nb_withdrawals:" << _nbWithdrawals
    					<< std::endl;
    return true;
  }
  else
  {
    std::cout << "refused" << std::endl;
    return false;
  }
}

int Account::checkAmount(void) const
{
  return _amount;
}

void Account::displayStatus(void) const
{
  _displayTimestamp();
  std::cout << "index: " << _accountIndex << ";"
  					<< "total: " << checkAmount() << ";"
  					<< "deposits: " << _nbDeposits << ";"
  					<< "withdrawals: " << _nbWithdrawals << ";"
  					<< std::endl;
}

