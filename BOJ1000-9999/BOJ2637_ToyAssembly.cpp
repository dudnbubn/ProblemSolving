// key point : Topological Sort

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
bool basic[101];

struct Node {
	int num;
	int in_degree;
	int cnt[101];
	vector<pair<int, Node*>> adjList;
	Node(int num) {
		this->num = num;
		this->in_degree = 0;
		for (int i = 0; i < 101; i++)	cnt[i] = 0;
		cnt[num] = 1;
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

	void link(int a, int b, int c) {
		nodeList[b]->adjList.push_back({ c, nodeList[a] });
		nodeList[a]->in_degree++;
	}

	void BFS() {
		queue<Node*> q;
		for (int i = 1; i <= n; i++) {
			if (nodeList[i]->in_degree == 0) {
				q.push(nodeList[i]);
				basic[i] = true;
			}
		}
		Node* cur;
		pair<int, Node*> next;
		while (!q.empty()) {
			cur = q.front();
			q.pop();
			for (int i = 0; i < cur->adjList.size(); i++) {
				next = cur->adjList[i];
				if (next.second->in_degree > 0) {
					for (int j = 1; j <= n; j++)
						next.second->cnt[j] += next.first * cur->cnt[j];
					next.second->in_degree--;
					if (next.second->in_degree == 0)
						q.push(next.second);
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
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		g.link(a, b, c);
	}
	g.BFS();
	
	for(int i=1;i<=n;i++)
		if (basic[i]) {
			cout << i << " " << g.nodeList[n]->cnt[i] << "\n";
		}
	return 0;
}