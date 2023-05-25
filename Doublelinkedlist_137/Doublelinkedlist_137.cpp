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
	
};
int main()
{
    std::cout << "Hello World!\n";
}
