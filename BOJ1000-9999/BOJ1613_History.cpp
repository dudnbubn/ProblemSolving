#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int history[401][401];

struct Node {
	int num;
	bool visited;
	vector<Node*> prevList;
	vector<Node*> nextList;
	Node(int num) {
		this->num = num;
		this->visited = false;
	}
};

class History {
public:
	vector<Node*> nodeList;
	History() {
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
		nodeList[a]->nextList.push_back(nodeList[b]);
		nodeList[b]->prevList.push_back(nodeList[a]);
	}

	void BFS(int start) {
		clear();
		queue<Node*> q;
		q.push(nodeList[start]);
		Node* cur;
		while (!q.empty()) {
			cur = q.front();
			q.pop();
			for (int i = 0; i < cur->nextList.size(); i++) {
				if (!cur->nextList[i]->visited) {
					cur->nextList[i]->visited = true;
					q.push(cur->nextList[i]);
					history[start][cur->nextList[i]->num] = -1;
					history[cur->nextList[i]->num][start] = 1;
				}
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;
	History h;
	int a, b, s;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		h.link(a, b);
	}
	for (int i = 1; i <= n; i++)
		h.BFS(i);

	cin >> s;
	for (int i = 0; i < s; i++) {
		cin >> a >> b;
		cout << history[a][b] << "\n";
	}
	return 0;
}