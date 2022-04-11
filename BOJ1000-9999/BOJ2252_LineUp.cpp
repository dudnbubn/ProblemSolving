#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;

struct Node {
	int num;
	int adjCnt;
	bool visited;
	vector<Node*> adjList;
	Node(int num) {
		this->num = num;
		this->adjCnt = 0;
		this->visited = false;
	}
};

queue<Node*> q;

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

	void link(int a, int b) {
		nodeList[a]->adjList.push_back(nodeList[b]);
		nodeList[b]->adjCnt++;
	}
	
	void BFS() {
		Node* cur;
		while (!q.empty()) {
			cur = q.front();
			q.pop();
			cout << cur->num << " ";
			for (int i = 0; i < cur->adjList.size(); i++) {
				if (!cur->adjList[i]->visited) {
					cur->adjList[i]->adjCnt--;
					if (!cur->adjList[i]->adjCnt) {
						cur->adjList[i]->visited = true;
						q.push(cur->adjList[i]);
					}
				}
			}
		}
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
		if (!g.nodeList[i]->adjCnt) {
			g.nodeList[i]->visited = true;
			q.push(g.nodeList[i]);
		}
	}

	g.BFS();
	return 0;
}