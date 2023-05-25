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
	/*Inserting a Node Between Two Nodes in the list*/
	Node* current = START; //step 1.a
	Node* previous = NULL; //step 1.b
	while (current->next != NULL && current->next->noMhs < nim)//step 1.c
	{
		previous = current;//1.d
		current = current->next;//1.e
	}
	if (current->next != NULL && nim==current->next->noMhs){
		cout << "\nDuplicate number not allowed" << endl;
		return;
	}
	newnode->next = current->next; //step 4
	newnode->prev = current; //step 5
	if (current->next != NULL){
		current->next->prev = newnode;//step 6
		current->next = newnode; //step 7
	}
};

bool Doublelinkedlist::search(int rollNo, Node** previous, Node** current) {
	*previous = START; //step 1.a
	*current = START;//step 1.b
	while (*current != NULL && rollNo != (*current)->noMhs){
		*previous = *current;//step 1.d
		*current = (*current)->next;//step 1.e
	}
	return (*current != NULL);
};

bool Doublelinkedlist::deleteNode(int rollNo) {
	Node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false) {
		return false;
	};
	if (current->next != NULL) {
		current->next->prev = previous; //step 2
	};
	if (previous != NULL) {
		previous->next = current->next;//steap 3
	}
	else {
		START = current->next;
	};

	delete current; //step 4
	return true;
};

bool Doublelinkedlist::listEmpty() {
	return (START == NULL);
};

void Doublelinkedlist::traverse() {
	if (listEmpty())
		cout << "\nList is empty" << endl;
	else{
		cout << "\nRecords in ascending order of roll number are" << endl;
		Node* currentNode = START;
		while (currentNode!= NULL){
			cout << currentNode->noMhs << "" << currentNode->Nama << endl;
			currentNode = currentNode->next;
		}
	}
};

void Doublelinkedlist::revtraverse() {
	if (listEmpty())
		cout << "\nList is empty" << endl;
	else {
		cout << "\nRecords in descending order of roll number are" << endl;
		Node* currentNode = START;
		while (currentNode->next != NULL) {
			currentNode = currentNode->next;
		};
		while (currentNode != NULL) {
			cout << currentNode->noMhs << "" << currentNode->Nama << endl;
			currentNode = currentNode->prev;
		};
	}
};

void Doublelinkedlist::hapus() {
	if (listEmpty()){
		cout << "\nlist is empty" << endl;
	}
	cout << "\nEnter the roll number of the student whose record is to be delete";
	int rollNo;
	cin >> rollNo;
	cout << endl;
	if (Doublelinkedlist::deleteNode(rollNo) == false)
		cout << "Record not found" << endl;
	else
		cout << "Record with roll number" << rollNo << " deleted" << endl;
}

void Doublelinkedlist::searchdata() {
	if (listEmpty()) {
		cout << "\nlist is empty" << endl;
	};
	Node* prev, * curr;
	prev = curr = NULL;
	cout << "\nEnter the roll number of the student whose record you want to search: ";
	int num;
	if (Doublelinkedlist::search(num, &prev, &curr) == false)
		cout << "\nRecord not found" << endl;
	else{
		cout << "\nRecord found" << endl;
		cout << "\nRoll number" << curr->noMhs << endl;
		cout << "\nName" << curr->Nama << endl;
	}
}

int main(){
	Doublelinkedlist obj;
	while (true){
		try {
			cout << "\nMenu" << endl;
			cout << "\1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all record in the ascending order of roll numbers" << endl;
			cout << "4. View  all record in the descending order of roll number" << endl;
			cout << "5. Search for a record in the list" << endl;
			cout << "6. Exit" << endl;
			cout << "\nEnter your Choise (1-6): ";
			char ch;
			cin >> ch;
		}
	}
}
