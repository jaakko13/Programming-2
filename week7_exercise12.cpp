#include <iostream>
using namespace std;

class Ship {
public:
	static string name;
	static string build;
	Ship() {
		name = "";
		build = "";
	}
	Ship(string n, string b) {
		name = n;
		build = b;
	}

	void setName(string n) {
		name = n;
	}
	void setBuild(string b) {
		build = b;
	}

	string getName() {
		return name;
	}
	string getBuild() {
		return build;
	}

	void print();
};

class CruiseShip : public Ship {
private:
	int maxp;
public:
	CruiseShip(string n, string b, int m) : Ship(n, b) {
		maxp = m;
	}

	void setMaxp(int m) {
		maxp = m;
	}
	int getMaxp() {
		return maxp;
	}

	void printcruise();
};

class CargoShip : public Ship {
private:
	int cap;
public:
	CargoShip(string n, string b, int c) : Ship(n, b) {
		cap = c;
	}

	void setCap(int c) {
		cap = c;
	}
	int getCap() {
		return cap;
	}

	void printcargo();
};

string Ship::name;
string Ship::build;


void Ship::print() {
	cout << "Name: " << name << endl;
	cout << "Year built: " << build << endl;
}

void CruiseShip::printcruise() {
	cout << "Name: " << name << endl;
	cout << "Max number of passengers: " << maxp << " people." << endl;
}

void CargoShip::printcargo() {
	cout << "Name: " << name << endl;
	cout << "Cargo capacity: " << cap << " tonnes." << endl;
}


int main() {
	Ship one("titanic", "1999");
	one.print();

	CruiseShip two("SS something", "1998", 200);
	two.printcruise();

	CargoShip three("SS something else", "1997", 500);
	three.printcargo();
}