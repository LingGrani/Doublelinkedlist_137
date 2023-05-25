#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	int noMhs;
	string Nama;
	Node* next;
	Node* prev;
};

class Doublelinkedlist
{
public:
	Doublelinkedlist();
	void addNode();
	bool search(int rollNo, Node** previous, Node** current);
	bool deleteNode(int rollNo);
	bool listEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchdata();
private:
	Node* START;
};

Doublelinkedlist::Doublelinkedlist() {
	START = NULL;
}

void Doublelinkedlist::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of student";
	cin >> nim;
	cout << "\nEnter the name of the student: ";
	cin >> nm;
	Node* newnode = new Node(); //step 1
	newnode->noMhs = nim;//step 2
	newnode->Nama = nm;//step 2

	/*insert a node in the beginning of doubly - linked list*/
	if (START == NULL || nim<= START->noMhs){
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newnode->next = START; //step 3
		if (START != NULL){
			START->prev = newnode; //step 4
			newnode->prev = NULL; //step 5
			START = newnode; //step 6
			return;
		}
	}
	
};
int main()
{
    std::cout << "Hello World!\n";
}
