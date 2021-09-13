#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> balloons;

struct Node {
	int data;
	int index;
	Node* prev;
	Node* next;
	Node(int data, int index) {
		this->data = data;
		this->index = index;
		this->prev = NULL;
		this->next = NULL;
	}
};

class CircularArray {
	Node* head;
	Node* tail;
	int size;
public:
	CircularArray() {
		this->size = 0;
		this->head = NULL;
		this->tail = NULL;
	}
	
	void insert(int data) {
		Node* new_node = new Node(data, size + 1);
		if (head == NULL) {
			head = new_node;
		}
		else if (tail == NULL) {
			tail = new_node;
			head->next = tail;
			head->prev = tail;
			tail->next = head;
			tail->prev = head;
		}
		else {
			tail->next = new_node;
			new_node->prev = tail;
			new_node->next = head;
			head->prev = new_node;
			tail = new_node;
		}
		size++;
	}

	void print() {
		Node* cur = head;
		Node* save;
		for (int i = 0; i < size; i++) {
			save = cur;
			cout << cur->index << " ";
			cur->next->prev = cur->prev;
			cur->prev->next = cur->next;
			if (cur->data > 0) {
				for (int j = 0; j < cur->data; j++)
					save = save->next;
			}
			else {
				for (int j = 0; j < (-1) * cur->data; j++)
					save = save->prev;
			}	
			cur = save;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int input;
	CircularArray ca;
	for (int i = 0; i < n; i++) {
		cin >> input;
		ca.insert(input);
	}
	ca.print();
	return 0;
}