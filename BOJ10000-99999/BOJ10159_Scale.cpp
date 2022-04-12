#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;

struct Node {
	int num;
	bool visited;
	vector<Node*> heavier;
	vector<Node*> lighter;
	Node(int num) {
		this->num = num;
		this->visited = false;
	}
};

class Graph {
public:
	vector<Node*> nodeList;
	Graph() {
		nodeList.push_back(0);
		for (int i = 1; i <= n; i++) {
			Node* newNode = new Node(i);
			nodeList.push_back(newNode);
		}
	}

	void clear() {
		for (int i = 1; i <= n; i++)
			nodeList[i]->visited = false;
	}

	void link(int a, int b) {
		nodeList[a]->lighter.push_back(nodeList[b]);
		nodeList[b]->heavier.push_back(nodeList[a]);
	}

	int relationCount(int num) {
		clear();
		int result = n - 1;
		queue<Node*> q;
		Node* cur;
		for (int i = 0; i < nodeList[num]->lighter.size(); i++) {
			if (!nodeList[num]->lighter[i]->visited) {
				nodeList[num]->lighter[i]->visited = true;
				q.push(nodeList[num]->lighter[i]);
			}
		}
		while (!q.empty()) {
			cur = q.front();
			q.pop();
			result--;
			for (int i = 0; i < cur->lighter.size(); i++) {
				if (!cur->lighter[i]->visited) {
					cur->lighter[i]->visited = true;
					q.push(cur->lighter[i]);
				}
			}
		}
		for (int i = 0; i < nodeList[num]->heavier.size(); i++) {
			if (!nodeList[num]->heavier[i]->visited) {
				nodeList[num]->heavier[i]->visited = true;
				q.push(nodeList[num]->heavier[i]);
			}
		}
		while (!q.empty()) {
			cur = q.front();
			q.pop();
			result--;
			for (int i = 0; i < cur->heavier.size(); i++) {
				if (!cur->heavier[i]->visited) {
					cur->heavier[i]->visited = true;
					q.push(cur->heavier[i]);
				}
			}
		}
		return result;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	Graph g;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		g.link(a, b);
	}
	for (int i = 1; i <= n; i++) {
		cout << g.relationCount(i) << "\n";
	}
	return 0;
}