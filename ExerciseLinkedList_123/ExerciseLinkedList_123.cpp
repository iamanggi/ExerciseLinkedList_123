#include <iostream>
#include <string>
using namespace std;

class node {
public:
	int rollNumber;
	string name;
	node* next;
};

node* LAST = NULL;

class CircularLinkedList {
private:
	node* LAST;

public:
	CircularLinkedList() {
		LAST = NULL;
	}

	void addNode();
	bool search(int rollno, node** puspita, node** anggi);
	bool listEmpty();
	bool delNode();
	void traverse();
};

void CircularLinkedList::addNode(){
		int nim;
		string nama;
		node* newnode = new node();  // step 1 
		cout << "\nMasukan Nim : ";
		cin >> nim;
		cout << "\nMasukan Nama : ";
		cin >> nama;
		newnode->rollNumber = nim;
		newnode->name = nama;

		if (LAST == NULL || nim <= LAST->rollNumber) { // step 2
			if (LAST != NULL && nim == LAST->rollNumber)
			{
				cout << "NIM sudah ada" << endl;
				return;
			}

			newnode->next = LAST;  // step 3
			LAST = newnode; // step 4
			return;
		}

		node* puspita = LAST;
		node* anggi = LAST->next;

		while ((anggi != NULL) && (nim >= anggi->rollNumber))
		{
			if (nim == anggi->rollNumber) {
				cout << "NIM sudah ada" << endl;
				return;
			}
			puspita = anggi;
			anggi = anggi->next;
		}

		newnode->next = anggi;
		puspita->next = newnode;
	
}

bool CircularLinkedList::search(int rollno, node** puspita, node** anggi) {
	*puspita = LAST->next;
	*anggi = LAST->next;

	while (*anggi != LAST) {
		if (rollno == (*anggi)->rollNumber) {
			return true;
		}
		*puspita = *anggi;
		*anggi = (*anggi)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}


bool CircularLinkedList::listEmpty() {
	return LAST = NULL;
}

bool CircularLinkedList::delNode() {
	node* anggi = LAST;
	node* puspita = LAST;
	if (LAST !=NULL == false)
		return false;
	puspita->next = anggi->next;
	if (anggi == LAST)
		LAST = anggi->next;
	return true;

	delete anggi;
}

void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
		system("pause");
		system("cls");
		return;
	}
	else {
		cout << "\nRecords in the list are:\n";
		node* currentnode = LAST->next;
		while (currentnode != LAST) {
			cout << currentnode->rollNumber << "  " << currentnode->name << endl;
			currentnode = currentnode->next;
		}
		cout << LAST->rollNumber << "   " << LAST->name << endl;
	}
}


int main() {
	CircularLinkedList obj;
	while(true) {
		try {
			cout << "Menu" << endl;
			cout << "\n1. add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. exit" << endl;
			cout << "\npilihan: ";
			cout << "\nEnter your choice (1-5): ";

			char ch;
			cin >> ch;

			switch (ch) {
			case '1': {
				obj.addNode();
				break;
			}
			case'2': {
				obj.delNode();
				break;
			}
			case'3': {
				obj.traverse();
				break;
			}
			case'4': {
				return 0;
			}
			default: {
				cout << "invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
		return 0;
	}
}