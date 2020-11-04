#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
	int i, random;
	int counter = 0;
	int x = 0;
	vector<int> numbers;
	vector<int> regular;

	for (i = 0; i < 7;)
	{
		cout << "Enter a lotto number(1-40):";
		cin >> x;
		if (x >= 1 && x <= 40)
		{
			numbers.push_back(x);
			i++;
		}
		else if (x < 1 || x > 40)
		{
			cout << "Only numbers between 1 and 40 are allowed. Try again." << endl;
		}
	}
	sort(numbers.begin(), numbers.end());
	reverse(numbers.begin(), numbers.end());
	cout << "Your numbers are: ";
	for (unsigned i = 0; i < numbers.size(); i++)
	{
		cout << numbers[i] << ", ";
	}
	cout << endl;

	srand(time(NULL));
	for (i = 0; i < 7; i++)
	{
		int random = (rand() % 40) + 1;
		regular.push_back(random);

		if (count(numbers.begin(), numbers.end(), random))
		{
			counter++;
		}
	}

	cout << "The lotto numbers are: ";
	sort(regular.begin(), regular.end());
	reverse(regular.begin(), regular.end());
	for (int i = 0; i < 7; ++i) {
		cout << regular[i] << ", ";
	}
	cout << endl;


	if (counter == 7)
	{
		cout << "YOU GOT ALL 7 NUMBERS CORRECT! YOU WON THE JACKPOT!";
	}
	else if (counter == 6)
	{
		cout << "You got 6 numbers correct. You won 2,000 euros.";
	}
	else if (counter == 5)
	{
		cout << "You got 5 numbers correct. You won 50 euros.";
	}
	else if (counter == 4)
	{
		cout << "You got 4 numbers correct. You won 10 euros.";
	}
	else if (counter == 3)
	{
		cout << "You got 3 numbers correct. You won 2 euros.";
	}
	else if (counter < 3)
	{
		cout << "You got " << counter << " numbers correct. You won no money.";
	}
}