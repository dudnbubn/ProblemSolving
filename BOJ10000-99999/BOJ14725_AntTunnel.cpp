#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;


struct Node {
	string name;
	vector<Node*> children;
	Node(string name) {
		this->name = name;
	}
};

bool compare(Node* a, Node* b) {
	return a->name < b->name;
}


void DFS(Node* node, int cnt) {
	for (int i = 0; i < cnt; i++)
		cout << "--";
	cout << node->name << "\n";

	sort(node->children.begin(), node->children.end(), compare);
	for (Node* n : node->children)
		DFS(n, cnt + 1);
}

int main() {
	cin >> N;

	Node* root = new Node(" ");
	Node* cur;
	string name;
	bool flag;
	for (int i = 0; i < N; i++) {
		cin >> K;
		cur = root;
		
		for (int j = 0; j < K; j++) {
			flag = true;
			cin >> name;
			for (Node* node : cur->children) {
				if (node->name == name) {
					flag = false;
					cur = node;
					break;
				}
			}
			if (flag) {
				Node* new_node = new Node(name);
				cur->children.push_back(new_node);
				cur = new_node;
			}
		}
	}

	sort(root->children.begin(), root->children.end(), compare);
	for (Node* node : root->children)
		DFS(node, 0);
	return 0;
}