// key point : ������ �� ������ DFS�� ���� ���� �ָ� �ִ� �� u�� ���ϰ�
//				u���� �ٽ� DFS�� �Ͽ� ���� �ָ� �ִ� �� v�� ���ϸ� u-v ������ �Ÿ��� Ʈ���� �����̴�.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V;
int result;
int index;

struct Node {
	int num;
	bool visited;
	vector<pair<int, Node*>> adj_list;
	Node(int num) {
		this->num = num;
		this->visited = false;
	}
};

class Tree {
public:
	vector<Node*> node_list;
	Tree() {
		node_list.push_back(0);
		for (int i = 1; i <= V; i++) {
			Node* new_node = new Node(i);
			node_list.push_back(new_node);
		}
	}

	void clear() {
		for (int i = 1; i <= V; i++)
			node_list[i]->visited = false;
	}

	void link(int a, int b, int c) {
		node_list[a]->adj_list.push_back({ c, node_list[b] });
	}

	void DFS(int node, int dist) {
		if (dist > result) {
			result = dist;
			index = node;
		}
		node_list[node]->visited = true;
		for (pair<int, Node*> p : node_list[node]->adj_list) {
			if (!p.second->visited) 
				DFS(p.second->num, dist + p.first);
		}
	}
};

int main() {
	cin >> V;
	Tree t;
	int a, b, c;
	for (int i = 1; i <= V; i++) {
		cin >> a;
		while (true) {
			cin >> b;
			if (b == -1)	break;
			cin >> c;
			t.link(a, b, c);
		}
	}
	t.DFS(1, 0);
	t.clear();
	result = 0;
	t.DFS(index, 0);
	cout << result;
	return 0;
}