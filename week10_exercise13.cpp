#include <iostream>
#include <string>

using namespace std;

class Employee {
private:

public:
	static string name;
	static int number;
	static int date;

	Employee() {
		name = "";
		number = 000;
		date = 31052000;
	}
	Employee(string n, int p, int d) {
		name = n;
		number = p;
		date = d;
	}
	void setName(string n) {
		name = n;
	}
	void setNumber(int p) {
		number = p;
	}
	void setDate(int d) {
		date = d;
	}
	string getName() {
		return name;
	}
	int getNumber() {
		return number;
	}
	int getDate() {
		return date;
	}

};

class ProductionWorker : public Employee {
private:
	int shift;
	double rate;
public:
	using Employee::Employee;

	ProductionWorker(int s, double r, string n, int num, int d) : Employee(n, num, d) {
		shift = s;
		rate = r;
	}
	void setShift(int s) {
		s = shift;
	}
	void setRate(double r) {
		r = rate;
	}
	int getShift() {
		return shift;
	}
	double getTrueRate() {
		return rate * shift;
	}


};

string Employee::name;
int Employee::number;
int Employee::date;

int main() {
	string name;
	int date;
	int num;
	int shift;
	int rate;

	ProductionWorker dood(0, 0, "", 0, 0);

	try
	{
		cout << "Shift:";
		cin >> shift;

		if (shift > 10)
		{
			throw 0;
		}
		dood.setShift(shift);
	}
	catch (int x)
	{
		cout << "Max shift is 10. Error:" << x << endl;
	}
	

	try
	{
		cout << "Actual rate:";
		cin >> rate;

		if (rate < 0)
		{
			throw 1;
		}
		dood.setRate(rate);
	}
	catch (int x)
	{
		cout << "Rate cant be negative. Error" << x << endl;
	}

	cout << "Name:";
	cin >> name;
	dood.setName(name);

	try
	{
		cout << "ID:";
		cin >> num;

		if (num < 0 || num > 9999)
		{
			throw 2;
		}
		dood.setNumber(num);
	}
	catch (int x)
	{
		cout << "ID number has to be between 0 and 9999. Error:" << x << endl;
	}

	cout << "Date:";
	cin >> date;
	dood.setDate(date);
}