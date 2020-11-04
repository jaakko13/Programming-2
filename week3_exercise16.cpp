#include <iostream>
using namespace std;

class substance {
private:
	string name;
	int freeze;
	int boil;
public:
	substance(string n, int f, int b) {
		name = n;
		freeze = f;
		boil = b;
	}
	substance() {
		name = "";
		freeze = 0;
		boil = 0;
	}
	void setName(string n) {
		name = n;
	}
	void setFreeze(int f) {
		freeze = f;
	}
	void setBoil(int b) {
		boil = b;
	}
	string getName() {
		return name;
	}
	int getFreeze() {
		return freeze;
	}
	int getBoil() {
		return boil;
	}

	bool isEthylFreezing(int temperature) {
		if (temperature <= freeze)
		{
			cout << "Ethyl will freeze at this temperature." << endl;
			return true;
		}
		else if (temperature > freeze) {
			return false;
		}
	}
	bool isEthylBoiling(int temperature) {
		if (temperature >= boil)
		{
			cout << "Ethyl will boil at this temperature." << endl;
			return true;
		}
		else if (temperature < boil) {
			return false;
		}
	}

	bool isOxygenFreezing(int temperature) {
		if (temperature <= freeze)
		{
			cout << "Oxygen will freeze at this temperature." << endl;
			return true;
		}
		else if (temperature > freeze) {
			return false;
		}
	}
	bool isOxygenBoiling(int temperature) {
		if (temperature >= boil)
		{
			cout << "Oxygen will boil at this temperature." << endl;
			return true;
		}
		else if (temperature < boil) {
			return false;
		}
	}

	bool isWaterFreezing(int temperature) {
		if (temperature <= freeze)
		{
			cout << "Water will freeze at this temperature." << endl;
			return true;
		}
		else if (temperature > freeze) {
			return false;
		}
	}
	bool isWaterBoiling(int temperature) {
		if (temperature >= boil)
		{
			cout << "Water will boil at this temperature." << endl;
			return true;
		}
		else if (temperature < boil) {
			return false;
		}
	}
};

int main() {

	substance one ("Ethyl alcohol", -173, 172);
	substance two ("Oxygen", -362, -306);
	substance three ("Water", 32, 212);

	int temperature;
	cout << "Enter a temperature in Fahrenheit:";
	cin >> temperature;

	one.isEthylFreezing(temperature) << one.isEthylBoiling(temperature);
	two.isOxygenFreezing(temperature) << two.isOxygenBoiling(temperature);
	three.isWaterFreezing(temperature) << three.isWaterBoiling(temperature);

	
}