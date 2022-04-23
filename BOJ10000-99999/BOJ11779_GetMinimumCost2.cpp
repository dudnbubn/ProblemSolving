#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int previous[1001];
int dist[1001];

struct Node {
	int num;
	bool visited;
	vector<pair<int, Node*>> adjList;
	Node(int num) {
		this->num = num;
		this->visited = false;
	}
};

typedef pair<int, pair<Node*, int>> info;

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
		nodeList[a]->adjList.push_back({ c, nodeList[b] });
	}

	void Dijkstra(int start, int end) {
		priority_queue<info, vector<info>, greater<info>> pq;
		pq.push({ 0, {nodeList[start], -1} });
		info cur;
		for (int i = 0; i < n; i++) {
			cur = pq.top();
			pq.pop();
			while (cur.second.first->visited) {
				cur = pq.top();
				pq.pop();
			}

			cur.second.first->visited = true;
			previous[cur.second.first->num] = cur.second.second;
			dist[cur.second.first->num] = cur.first;
			if (cur.second.first->num == end)	return;
			for (int i = 0; i < cur.second.first->adjList.size(); i++) {
				if (!cur.second.first->adjList[i].second->visited) {
					pq.push({ cur.first + cur.second.first->adjList[i].first , {cur.second.first->adjList[i].second, cur.second.first->num} });
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
	int start, end;
	cin >> start >> end;
	g.Dijkstra(start, end);
	
	cout << dist[end] << "\n";

	stack<int> stk;
	while (start != end) {
		stk.push(end);
		end = previous[end];
	}
	stk.push(start);

	cout << stk.size() << "\n";
	while (!stk.empty()) {
		cout << stk.top() << " ";
		stk.pop();
	}
	return 0;

}