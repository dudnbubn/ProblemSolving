#include <iostream>
using namespace std;

struct Node {
	char data;
	Node* prev;
	Node* next;
	Node(char data) {
		this->data = data;
		this->prev = NULL;
		this->next = NULL;
	}
};

class KeyLogger {
public:
	Node* header;
	Node* trailer;
	Node* cursor;
	KeyLogger() {
		this->header = NULL;
		this->trailer = new Node(' ');
		this->cursor = NULL;
	}

	void insert(char data) {
		Node* new_node = new Node(data);
		if (header == NULL) {
			new_node->next = trailer;
			trailer->prev = new_node;
			header = new_node;
			cursor = trailer;
		}
		else if (cursor == header) {
			new_node->next = cursor;
			cursor->prev = new_node;
			header = new_node;
		}
		else {
			cursor->prev->next = new_node;
			new_node->prev = cursor->prev;
			cursor->prev = new_node;
			new_node->next = cursor;
		}
	}

	void remove() {
		if (cursor == NULL)	return;

		if (cursor == header)	return;
		else if (cursor->prev == header) {
			header = cursor;
		}
		else {
			cursor->prev->prev->next = cursor;
			cursor->prev = cursor->prev->prev;
		}
	}

	void left() {
		if (cursor == NULL)	return;
		if (cursor != header)
			cursor = cursor->prev;
	}

	void right() {
		if (cursor == NULL)	return;
		if (cursor != trailer)
			cursor = cursor->next;
	}

	void print() {
		Node* temp = header;
		while (temp != trailer) {
			cout << temp->data;
			temp = temp->next;
		}
		cout << "\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;
	cin >> testcase;
	string log;
	while (testcase--) {
		KeyLogger kl;
		cin >> log;
		for (int i = 0; i < log.size(); i++) {
			if (log[i] == '-')	kl.remove();
			else if (log[i] == '<')	kl.left();
			else if (log[i] == '>')	kl.right();
			else	kl.insert(log[i]);
		}
		kl.print();
	}
	return 0;
}