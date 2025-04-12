
#define ACCOUNT_H__
#include"date.h"
#include<string>
using namespace std;
class SavingsAccount {
private:
	string id;
	double balance;
	double rate;
	Date lastDate;//上次余额变动的日期
	double accumulation;//余额按日累加的总和，用于计算日均余额
	static double total;
public:
	void record(Date& date, double amount, const string& desc);
	void error(const string& msg)const;
	double accumulate(const Date& date)const {
		return accumulation + balance * date.distance(lastDate);
	};
	SavingsAccount( Date& date,const string& id, double rate);
	const string& getId()const {
		return id;
	}
	double getBalance() const {
		return balance;
	}
	double getRate() const {
		return rate;
	}
	static double getTotal() {
		return total;
	}
	void show()const;
	void deposit(Date date, double amount, const string& desc);
	void withdraw(Date date, double amount, const string& desc);
	void settle(Date date);
};


