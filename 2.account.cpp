#include "account.h"
#include<iostream>
#include<cmath>
using namespace std;
double SavingsAccount::total = 0;
SavingsAccount::SavingsAccount( Date& date, const string& id, double rate) :id(id), balance(0), rate(rate), lastDate(date), accumulation(0) {
	date.show();
	cout << "\t#" << id << "created" << endl;
}
void SavingsAccount::show() const{
	cout << id << "\tBalance:" << balance;
}
//记录交易
void SavingsAccount::record( Date& date, double amount, const string& desc) {
	accumulation = accumulate(date);
	lastDate = date;
	amount = floor(amount * 100 + 0.5) / 100;
	balance += amount;
	total += amount;
	date.show();
	cout << "\t#" << id << "\t" << amount << "\t" << balance << "\t" << desc << endl;
}
//存款
void SavingsAccount::deposit( Date date, double amount, const string& desc) {
	record(date, amount, desc);
}
//取款
void SavingsAccount::withdraw(Date date, double amount, const string& desc) {
	if (amount > getBalance())error("not enough money");
	else
		record(date, -amount, desc);
}
//结算利息
void SavingsAccount::settle(Date date) {
	double interest = accumulate(date) * rate/date.distance(Date(date.getYear()-1,1,1));
	if (interest != 0) {
		record(date, interest, "interest");
	}
	accumulation = 0;
}
void SavingsAccount::error(const string& msg)const {
	cout << "Error(#" << id << "):" << msg << endl;
}
