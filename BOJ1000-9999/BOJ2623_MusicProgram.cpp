// key point : Topological Sort

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int arr[1000];
queue<int> result;

struct Node {
	int num;
	int in_degree;
	vector<Node*> adjList;
	Node(int num) {
		this->num = num;
		this->in_degree = 0;
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
	
	void link(int a, int b) {
		nodeList[a]->adjList.push_back(nodeList[b]);
		nodeList[b]->in_degree++;
	}

	void BFS() {
		queue<Node*> q;
		for (int i = 1; i <= n; i++)
			if (nodeList[i]->in_degree == 0)
				q.push(nodeList[i]);
		Node* cur;
		while (!q.empty()) {
			cur = q.front();
			q.pop();
			result.push(cur->num);
			for (int i = 0; i < cur->adjList.size(); i++) {
				if (cur->adjList[i]->in_degree > 0) {
					cur->adjList[i]->in_degree--;
					if (cur->adjList[i]->in_degree == 0)
						q.push(cur->adjList[i]);
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
	int s;
	Graph g;
	for (int i = 0; i < m; i++) {
		cin >> s;
		for (int j = 0; j < s; j++)	cin >> arr[j];
		for (int j = 0; j < s - 1; j++)
			g.link(arr[j], arr[j + 1]);
	}
	g.BFS();
	if (result.size() == n) {
		while (!result.empty()) {
			cout << result.front() << "\n";
			result.pop();
		}
	}
	else
		cout << 0;
	return 0;
}