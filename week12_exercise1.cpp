#include <iostream>
#include <cstdlib>
using namespace std;


class list {
private:
	typedef struct node {
		int data;
		node* next;
	}* nodePtr;

	nodePtr head;
	nodePtr curr;
	nodePtr temp;
public:
	list();
	void appendNode(int appendData);
	void deleteNode(int delData);

	~list() {
		while (head != NULL)
		{
			temp = head->next;
			delete head;
			head = temp;
		}
	}
};

list::list() {
	head = NULL;
	curr = NULL;
	temp = NULL;
}

void list::appendNode(int appendData) {
	nodePtr n = new node;
	n->next = NULL;
	n->data = appendData;

	if (head != NULL)
	{
		curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = n;
	}
	else
	{
		head = n;
	}
}

void list::deleteNode(int delData) {
	nodePtr delPtr = NULL;
	temp = head;
	curr = head;

	while (curr != NULL && curr->data != delData)
	{
		temp = curr;
		curr = curr->next;
	}

	if (curr == NULL)
	{
		cout << delData << " was not in the list.\n";
		delete delPtr;
	}
	else
	{
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;
		delete delPtr;
		cout << "The value " << delData << " was deleted.\n";
	}
}


int main() {
	int times, value, i, del;
	list mine;
	
	cout << "How many numbers would you like to add?";
	cin >> times;

	for ( i = 0; i < times; i++)
	{
		cout << "Enter a number to append:";
		cin >> value;

		mine.appendNode(value);
	}

	cout << "What number would you like to delete?";
	cin >> del;

	mine.deleteNode(del);


	
}