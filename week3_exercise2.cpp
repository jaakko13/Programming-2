#include <iostream>
#include <string>
using namespace std;

class employee {
private:
	string name;
	int idNumber;
	string department;
	string position;

public:
	employee(string n, int id, string d, string p) {
		name = n;
		idNumber = id;
		department = d;
		position = p;
	}

	employee(string n, int id) {
		name = n;
		idNumber = id;
		department = "";
		position = "";
	}

	employee() {
		name = "";
		idNumber = 0;
		department = "";
		position = "";
	}

	void setName(string n) {
		name = n;
	}
	void setID(int id) {
		idNumber = id;
	}
	void setDepartment(string d) {
		department = d;
	}
	void setPosition(string p) {
		position = p;
	}

	string getName() {
		return name;
	}
	int getID() {
		return idNumber;
	}
	string getDepartment() {
		return department;
	}
	string getPosition() {
		return position;
	}
};

	int main() {

		string word;
		int num;
		employee* one = nullptr;
		employee* two = nullptr;
		employee* three = nullptr;

		one = new employee;
		two = new employee;
		three = new employee;

		cout << "What is the first employee's name?";
		cin >> word;
		one->setName(word);
		cout << "What is the first employee's ID Number?";
		cin >> num;
		one->setID(num);
		cout << "What is the first employee's department?";
		cin >> word;
		one->setDepartment(word);
		cout << "What is the first employee's position?";
		cin >> word;
		one->setPosition(word);

		cout << "What is the second employee's name?";
		cin >> word;
		two->setName(word);
		cout << "What is the second employee's ID Number?";
		cin >> num;
		two->setID(num);
		cout << "What is the second employee's department?";
		cin >> word;
		two->setDepartment(word);
		cout << "What is the second employee's position?";
		cin >> word;
		two->setPosition(word);

		cout << "What is the third employee's name?";
		cin >> word;
		three->setName(word);
		cout << "What is the third employee's ID Number?";
		cin >> num;
		three->setID(num);
		cout << "What is the third employee's department?";
		cin >> word;
		three->setDepartment(word);
		cout << "What is the third employee's position?";
		cin >> word;
		three->setPosition(word);


		cout << "Name:" << one->getName() << "  " << "ID:" << one->getID() << "  " << "Department:" << one->getDepartment() << "  " << "Position:" << one->getPosition() << endl;
		cout << "Name:" << two->getName() << "  " << "ID:" << two->getID() << "  " << "Department:" << two->getDepartment() << "  " << "Position:" << two->getPosition() << endl;
		cout << "Name:" << three->getName() << "  " << "ID:" << three->getID() << "  " << "Department:" << three->getDepartment() << "  " << "Position:" << three->getPosition() << endl;

};