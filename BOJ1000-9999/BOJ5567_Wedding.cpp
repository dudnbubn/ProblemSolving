#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int data;
	bool visited;
	vector<Node*> fri_list;
	Node(int data) {
		this->data = data;
		this->visited = false;
	}
};
class Alumni {
public:
	vector<Node*> node_list;
	Alumni(int n) {
		node_list.push_back(0);
		for (int i = 1; i <= n; i++) {
			Node* new_node = new Node(i);
			node_list.push_back(new_node);
		}
	}
	void link(int a, int b) {
		node_list[a]->fri_list.push_back(node_list[b]);
		node_list[b]->fri_list.push_back(node_list[a]);
	}

	int BFS() {
		int result = 0;
		queue<Node*> q;
		q.push(node_list[1]);
		node_list[1]->visited = true;
		int link = 0;
		while (!q.empty() && link < 2) {
			link++;
			int qsz = q.size();
			for (int i = 0; i < qsz; i++) {
				Node* cur = q.front();
				q.pop();
				for (int j = 0; j < cur->fri_list.size(); j++) {
					if (!cur->fri_list[j]->visited) {
						cur->fri_list[j]->visited = true;
						q.push(cur->fri_list[j]);
						result++;
					}
				}
			}
		}
		return result;
	}
};
int main() {
	int n;
	cin >> n;
	Alumni al(n);
	int m;
	cin >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		al.link(a, b);
	}
	cout << al.BFS();
	return 0;
}