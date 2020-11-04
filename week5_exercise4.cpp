#include <iostream>
using namespace std;

class NumDays {
private:
	int hours = 0;
	double days = 0;
public:
	NumDays() {
		hours = 0;
		days = 0;
	}
	NumDays(int hours) {
		hours = hours;
		days = (double)hours / 8;
	}
	void setHours(int hours) {
		hours = hours;
		days = (double)hours / 8;
	}
	int getHours() {
		return hours;
	}
	double getDays() {
		return days;
	}

	NumDays operator + (NumDays const& obj) {
		NumDays count;
		count.hours = hours + obj.hours;
		count.days = (double)count.hours / 8;
		return count;
	}
	NumDays operator - (NumDays const& obj) {
		NumDays count;
		count.hours = hours - obj.hours;
		count.days = (double)count.hours / 8;
		return count;
	}

	NumDays operator ++ (int) {
		hours++;
		days = (double)hours / 8;
		return hours;
	}
	NumDays operator -- () {
		hours--;
		days = (double)hours / 8;
		return hours;
	}
};

int main() {
	int hours;
	cout << "Enter amount of hours worked:";
	cin >> hours;

	NumDays work(hours);

	cout << "You've worked for " << work.getDays() << " days or " << hours << " hours." << endl;
}