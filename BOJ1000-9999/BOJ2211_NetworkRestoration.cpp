#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int N, M;
int previous[1001];
set<pair<int, int>> result;

struct Node {
	int num;
	bool visited;
	vector<pair<int, Node*>> adj_list;
	Node(int num) {
		this->num = num;
		this->visited = false;
	}
};

typedef pair<pair<int, Node*>, int> pin;

class Graph {
public:
	vector<Node*> node_list;
	
	Graph() {
		node_list.push_back(0);
		for (int i = 1; i <= N; i++) {
			Node* new_node = new Node(i);
			node_list.push_back(new_node);
		}
	}

	void link(int A, int B, int C) {
		node_list[A]->adj_list.push_back({ C, node_list[B] });
		node_list[B]->adj_list.push_back({ C, node_list[A] });
	}

	void Dijkstra(int start) {
		priority_queue<pin, vector<pin>, greater<pin>> pq;
		pq.push({ {0, node_list[start] }, 0 });

		pin cur;
		for (int i = 1; i <= N; i++) {
			cur = pq.top();
			pq.pop();
			while (cur.first.second->visited) {
				cur = pq.top();
				pq.pop();
			}
			
			cur.first.second->visited = true;
			previous[cur.first.second->num] = cur.second;

			for (pair<int, Node*> n : cur.first.second->adj_list) {
				if (!n.second->visited) {
					pq.push({ {cur.first.first + n.first, n.second}, cur.first.second->num });
				}
			}
		}
		
		for (int i = 2; i <= N; i++) {
			int cur = i, prev = previous[i];
			while (cur != 1) {
				result.insert({ cur, prev });
				cur = prev;
				prev = previous[cur];
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	Graph g;
	int A, B, C;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		g.link(A, B, C);
	}

	g.Dijkstra(1);
	cout << result.size() << "\n";
	for (pair<int, int> s : result)
		cout << s.first << " " << s.second << "\n";
	return 0;
}