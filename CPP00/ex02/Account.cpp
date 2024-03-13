/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:35:47 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/13 16:29:41 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}
int Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}
int Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}
int Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}
void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}
Account::Account(void)
{
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::getNbAccounts();
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;
	std::cout << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	if (this->_amount < withdrawal)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal << ";amount:" <<  this->_amount <<";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	return (true);
}

int Account::checkAmount(void) const
{
	return (this->_amount);
}

void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	time_t	t;
	char tmp[18];

	time(&t);
	strftime(tmp, sizeof(tmp), "[%Y%m%d_%H%M%S]", localtime(&t));
	std::cout << tmp << " ";
}
