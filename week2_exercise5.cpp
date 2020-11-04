#include <iostream>
using namespace std;

class RetailItem {
private:
	string description;
	int unitsOnHand;
	double price;
public:
	RetailItem(string d, int u, double p) {
		description = d;
		unitsOnHand = u;
		price = p;
	}
	string getDescription() {
		return description;
	}
	int getUnitsOnHand() {
		return unitsOnHand;
	}
	double getPrice() {
		return price;
	}
};

int main() {
	RetailItem Item1("Jakcet", 12, 59.95);

	RetailItem Item2("Designer Jeans", 40, 34.95);

	RetailItem Item3("Shirt", 20, 24.95);
}
