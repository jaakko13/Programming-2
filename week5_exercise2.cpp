#include <iostream>
using namespace std;

class DayofYear {
private:
	int day;
public:
	static int EndDay[];
	static string month[];

	DayofYear(int d) {
		day = d;
	}
	void setDay(int d) {
		day = d;
	}
	int getDay() {
		return day;
	}
	void print();
};

int DayofYear::EndDay[] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 366 };
string DayofYear::month[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

int main() {
	int day;

	cout << "Enter a day between 1 and 365:";
	cin >> day;

	DayofYear a(day);

	a.print();

}

void DayofYear::print() {
	int user;
	int i;

	if (day < DayofYear::EndDay[0] && day > 0)
	{
		cout << month[0] << " " << day << endl;
	}

	for (i = 0; i < 12; i++)
	{
		if (day < DayofYear::EndDay[i + 1] && day > DayofYear::EndDay[i])
		{
			user = day - EndDay[i];
			cout << month[i + 1] << " " << user << endl;
		}
	}
}