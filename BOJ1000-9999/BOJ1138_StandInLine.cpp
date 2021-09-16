#include <iostream>
using namespace std;

int arr[11];

struct Node {
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

class LinkedList {
	Node* head;
public:
	LinkedList(int n) {
		this->head = new Node(n);
	}

	void insert(int n, int index) {
		Node* new_node = new Node(n);
		if (index == 0) {
			new_node->next = head;
			head = new_node;
		}
		else {
			Node* temp = head;
			for (int i = 0; i < index - 1; i++) temp = temp->next;
			new_node->next = temp->next;
			temp->next = new_node;
		}
	}

	void print() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
};

int main() {
	int n;
	cin >> n;
	LinkedList ll(n);
	for (int i = 1; i <= n; i++)	cin >> arr[i];
	for (int i = n - 1; i >= 1; i--) {
		ll.insert(i, arr[i]);
	}
	ll.print();
	return 0;
}