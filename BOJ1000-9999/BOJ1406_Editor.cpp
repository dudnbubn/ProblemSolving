//#include <iostream>
//using namespace std;
//
//struct Node {
//	char data;
//	Node* prev;
//	Node* next;
//	Node(char data) {
//		this->data = data;
//		this->prev = NULL;
//		this->next = NULL;
//	}
//};
//
//class Editor {
//	Node* header;
//	Node* trailer;
//	Node* cursor;
//public:
//	Editor() {
//		this->header = new Node('H');
//		this->trailer = new Node('T');
//		this->cursor = NULL;
//	}
//
//	void Left() {
//		if (cursor->prev != header)
//			cursor = cursor->prev;
//	}
//
//	void Right() {
//		if (cursor != trailer)
//			cursor = cursor->next;
//	}
//
//	void Remove() {
//		if (cursor->prev != header) {
//			Node* u = cursor->prev->prev;
//			u->next = cursor;
//			cursor->prev = u;
//		}
//	}
//
//	void Insert(char x) {
//		Node* new_node = new Node(x);
//		if (cursor == NULL) {
//			new_node->prev = header;
//			header->next = new_node;
//			new_node->next = trailer;
//			trailer->prev = new_node;
//			cursor = trailer;
//		}
//		else {
//			Node* u = cursor->prev;
//			u->next = new_node;
//			new_node->prev = u;
//			new_node->next = cursor;
//			cursor->prev = new_node;
//		}
//	}
//	
//	void Print() {
//		Node* temp = header->next;
//		while (temp != trailer) {
//			cout << temp->data;
//			temp = temp->next;
//		}
//	}
//};
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	string s;
//	Editor e;
//	int m;
//	char cmd;
//	cin >> s;
//	cin >> m;
//	for (int i = 0; i < s.size(); i++)
//		e.Insert(s[i]);
//	for (int i = 0; i < m; i++) {
//		cin >> cmd;
//		if (cmd == 'L')
//			e.Left();
//		else if (cmd == 'D')
//			e.Right();
//		else if (cmd == 'B')
//			e.Remove();
//		else if (cmd == 'P') {
//			cin >> cmd;
//			e.Insert(cmd);
//		}
//	}
//	e.Print();
//
//	return 0;
//}