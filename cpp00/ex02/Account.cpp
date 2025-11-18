/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 03:34:20 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/11/17 22:13:34 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:"
        << _amount << ";created" << std::endl;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:"
        << _amount << ";closed" << std::endl;
}

int Account::getNbAccounts()
{
    return _nbAccounts;
}

int Account::getTotalAmount()
{
    return _totalAmount;
}

int Account::getNbDeposits()
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount 
    << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) 
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) 
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
    if (withdrawal > _amount) 
    {
        std::cout << "refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout << withdrawal << ";amount:" << _amount
        << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

int Account::checkAmount() const
{
    return _amount;
}

void Account::displayStatus() const 
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
    << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp() 
{
    std::time_t t = std::time(NULL);
    std::tm* tm_info = std::localtime(&t);
    std::cout << "[" << (tm_info->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << (tm_info->tm_mon + 1)
              << std::setw(2) << std::setfill('0') << tm_info->tm_mday << "_"
              << std::setw(2) << std::setfill('0') << tm_info->tm_hour
              << std::setw(2) << std::setfill('0') << tm_info->tm_min
              << std::setw(2) << std::setfill('0') << tm_info->tm_sec << "] ";
}
