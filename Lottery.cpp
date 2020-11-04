#include <iostream>
#include <cstdlib>
#include <random>
#include <time.h>
#include <ctime>
using namespace std;

//struct with next and prev pointers along with data int
struct node {
	int data;
	node* next;
	node* prev;
};


void transverseFWD(node* head);
void transverseBWD(node* end);
void deleteNode(node* head, int key);


int main() {
	//to make random actually random 
	srand(time(0));


	//pointers. head=first  end=last and n=new 
	node* head;
	node* end;
	node* n;


	//All the nodes from 1 to 40. First and last are unique as prev from first goes to last. Next from last goes to first.
	n = new node;
	n->data = 1;
	n->prev = NULL;
	head = n;
	end = n;
	head->prev = end;

	n = new node;
	n->data = 2;
	n->prev = end;
	end-> next = n;
	end = n;

	n = new node;
	n->data = 3;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 4;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 5;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 6;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 7;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 8;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 9;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 10;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 11;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 12;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 13;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 14;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 15;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 16;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 17;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 18;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 19;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 20;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 21;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 22;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 23;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 24;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 25;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 26;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 27;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 28;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 29;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 30;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 31;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 32;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 33;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 34;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 35;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 36;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 37;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 38;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 39;
	n->prev = end;
	end->next = n;
	end = n;

	n = new node;
	n->data = 40;
	n->prev = end;
	end->next = n;
	end = n;
	end->next = head;


	//Decides is the nodes are transversed forwards or backwards
	int decide = rand() % 100 + 1;

	if (decide % 2 ==0)
	{
		transverseFWD(head);
	}
	else
	{
		transverseBWD(end);
	}


	cout << "Hello and welcome to the lottery game. You will be asked 6 different numbers from 1 to 40. Each number can only be picked once. Good Luck!";

}

void transverseFWD(node* head) {
	int i = 0;
	int x = 0;
	srand(time(0));

	for (i = 0; i < 6; i++)
	{
		int random = rand() & 40 + 1;
		node* temp = head;

		while (x < random)
		{
			temp = temp->next;
			x++;
		}

		cout << temp->data << " " << endl;
		deleteNode(head, temp->data);

	}
	
}

void transverseBWD(node* end) {
	int x = 0;
	int i = 0;
	srand(time(0));

	for (i = 0; i < 6; i++)
	{
		int random = rand() & 40 + 1;
		node* temp = end;

		while (x < random)
		{
			temp = temp->prev;
			x++;
		}

		cout << temp->data << " " << endl;
		deleteNode(end, temp->data);
	}
	
}

void deleteNode(node* head, int key) { 
	{
		// If list is empty 
		if (head == NULL)
			return;

		// Find the required node 
		// Declare two pointers and initialize them 
		struct node* curr = head, * prev_1 = NULL;
		while (curr->data != key) {
			// If node is not present in the list 
			if (curr->next == head) {
				printf("\nList doesn't have node with value = %d", key);
				return;
			}

			prev_1 = curr;
			curr = curr->next;
		}

		// Check if node is the only node in list 
		if (curr->next == head && prev_1 == NULL) {
			(head) = NULL;
			free(curr);
			return;
		}

		// If list has more than one node, 
		// check if it is the first node 
		if (curr == head) {
			// Move prev_1 to last node 
			prev_1 = (head)->prev;

			// Move start ahead 
			head = (head)->next;

			// Adjust the pointers of prev_1 and start node 
			prev_1->next = head;
			(head)->prev = prev_1;
			free(curr);
		}

		// check if it is the last node 
		else if (curr->next == head) {
			// Adjust the pointers of prev_1 and start node 
			prev_1->next = head;
			(head)->prev = prev_1;
			free(curr);
		}
		else {
			// create new pointer, points to next of curr node 
			struct node* temp = curr->next;

			// Adjust the pointers of prev_1 and temp node 
			prev_1->next = temp;
			temp->prev = prev_1;
			free(curr);
		}
	}
}


