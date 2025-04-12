#ifndef ACCOUNT_H__
#define ACCOUNT_H__
#include<iostream>
#include<string>
#include"date.h"
#include"accumulator.h"
using namespace std;
class Account {
private:
	string id;
	double balance;
	static double total;
public:
	Account(const Date& date,const string& id);
	void record(const Date& date, double amount,const string& desc);
	void error(const string& msg)const;
	string getId()const { return id; }
	double getBalance()const { return balance; }
	void show()const;
	static double getTotal() { return total; }
};
class SavingsAccount :public Account {
private:
	Accumulator acc;
	double rate;
public:
	SavingsAccount(const Date& date,const string& id, double rate);
	double getRate()const { return rate; }
	void deposit(const Date& date, double amount,const string& desc);
	void withdraw(const Date& date, double amount,const string& desc);
	void settle(const Date& date);
};
class CreditAccount :public Account {
private:
	Accumulator acc;
	double credit;
	double rate;
	double fee;
public:
	double getDebt()const {
		double balance = getBalance();
		return (balance < 0 ? balance : 0);
	}
	CreditAccount(const Date& date,const string& id, double credit, double rate, double fee);
	double getCredit()const { return credit; }
	double getRate()const { return rate; }
	double getFee()const { return fee; }
	double getAvailableCredit()const {
		if (getBalance() < 0)
			return credit + getBalance();
		else
			return credit;
	}
	void deposit(const Date& date, double amount,const string& desc);
	void withdraw(const Date& date, double amount, const string& desc);
	void settle(const Date& date);
	void show()const;
};
#endif
