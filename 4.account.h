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
	Account(const Date& date, const string& id);
	void record(const Date& date, double amount, const string& desc);
	void error(const string& msg)const;
	string getId()const { return id; }
	double getBalance()const { return balance; }
	static double getTotal() { return total; }
	virtual void show()const;
	virtual void deposit(const Date& date, double amount, const string& desc)=0;
	virtual void withdraw(const Date& date, double amount, const string& desc)=0;
	virtual void settle(const Date& date)=0;
	
};
class SavingsAccount :public Account {
private:
	Accumulator acc;
	double rate;
public:
	SavingsAccount(const Date& date, const string& id, double rate);
	double getRate()const { return rate; }
	virtual void deposit(const Date& date, double amount, const string& desc);
	virtual void withdraw(const Date& date, double amount, const string& desc);
	virtual void settle(const Date& date);
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
	CreditAccount(const Date& date, const string& id, double credit, double rate, double fee);
	double getCredit()const { return credit; }
	double getRate()const { return rate; }
	double getFee()const { return fee; }
	double getAvailableCredit()const {
		if (getBalance() < 0)
			return credit + getBalance();
		else
			return credit;
	}
	virtual void deposit(const Date& date, double amount, const string& desc);
	virtual void withdraw(const Date& date, double amount, const string& desc);
	virtual void settle(const Date& date);
	virtual void show()const;
};
#endif
