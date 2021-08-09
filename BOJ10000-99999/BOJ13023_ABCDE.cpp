#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool isUsed[2000] = { 0, };

struct Node {
	int data;
	vector<Node*> friends;
	Node(int data) {
		this->data = data;
	}
};

class Graph {
public:
	vector<Node*> node_list;

	Graph(int n) {
		for (int i = 0; i < n; i++) {
			Node* new_node = new Node(i);
			node_list.push_back(new_node);
		}
	}

	void connect(int a, int b) {
		Node* A = node_list[a];
		Node* B = node_list[b];
		A->friends.push_back(B);
		B->friends.push_back(A);
	}
	
	void Brute(Node* cur, int k) {
		if (k == 5) {
			cout << 1;
			exit(0);
		}
		if (cur->friends.size() == 0)
			return;
		for (int i = 0; i < cur->friends.size(); i++) {
			if (!isUsed[cur->friends[i]->data]) {
				isUsed[cur->friends[i]->data] = true;
				Brute(cur->friends[i], k + 1);
				isUsed[cur->friends[i]->data] = false;
			}
		}
		
	}
};

int main() {
	cin >> n >> m;
	Graph g(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g.connect(a, b);
	}
	for (int i = 0; i < n; i++) {
		g.Brute(g.node_list[i], 1);
	}
	cout << 0;
	return 0;
}