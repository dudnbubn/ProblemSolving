//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//int n, m;
//
//struct Node {
//	int num;
//	bool visited;
//	vector<Node*> smaller;
//	vector<Node*> taller;
//	Node(int num) {
//		this->num = num;
//		this->visited = false;
//	}
//};
//
//class Graph {
//public:
//	vector<Node*> node_list;
//	Graph() {
//		node_list.push_back(0);
//		for (int i = 1; i <= n; i++) {
//			Node* new_node = new Node(i);
//			node_list.push_back(new_node);
//		}
//	}
//
//	void clear() {
//		for (int i = 1; i <= n; i++)	
//			node_list[i]->visited = false;
//	}
//
//	void link(int a, int b) {
//		node_list[a]->taller.push_back(node_list[b]);
//		node_list[b]->smaller.push_back(node_list[a]);
//	}
//
//	int BFS(int start) {
//		clear();
//		int result = 1;
//		queue<pair<Node*, bool>> q;
//		q.push({ node_list[start], true });
//		q.push({ node_list[start], false });
//		node_list[start]->visited = true;
//		pair<Node*, bool> cur;
//		while (!q.empty()) {
//			cur = q.front();
//			q.pop();
//			if (cur.second) {
//				for (int i = 0; i < cur.first->smaller.size(); i++) {
//					if (!cur.first->smaller[i]->visited) {
//						result++;
//						cur.first->smaller[i]->visited = true;
//						q.push({ cur.first->smaller[i], cur.second });
//					}
//				}
//			}
//			else {
//				for (int i = 0; i < cur.first->taller.size(); i++) {
//					if (!cur.first->taller[i]->visited) {
//						result++;
//						cur.first->taller[i]->visited = true;
//						q.push({ cur.first->taller[i], cur.second });
//					}
//				}
//			}
//		}
//		return result;
//	}
//};
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	cin >> n >> m;
//	Graph g;
//	int a, b;
//	for (int i = 0; i < m; i++) {
//		cin >> a >> b;
//		g.link(a, b);
//	}
//
//	int result = 0;
//	for (int i = 1; i <= n; i++) {
//		if (g.BFS(i) == n)
//			result++;
//	}
//	cout << result;
//	return 0;
//}