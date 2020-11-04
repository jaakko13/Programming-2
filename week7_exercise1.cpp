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
	string getName()  {
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
int Employee:: date;

int main() {
	ProductionWorker dood(2, 20, "jaakko", 123, 3105);
	cout << "Name:" << dood.name << endl;
	cout << "ID:" << dood.number << endl;
	cout << "Date:" << dood.date << endl;
	cout << "Shift:" << dood.getShift() << endl;
	cout << "Actual rate:" << dood.getTrueRate() << endl;
}