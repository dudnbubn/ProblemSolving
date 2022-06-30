// Dijkstra ���� �̹� �湮�� ��带 üũ�ϴ� ���
//	while (visited[cur.second]) {
//		cur = pq.top();
//		pq.pop();
//	}
// ���� �ڵ带 ������ ��� �ð� �ʰ��� �߻��Ѵ�.

// ������
//	if (visited[cur.second])	continue;
// �� �ۼ��ϴ� ��� �������� ó���� �ȴ�.

// �� �ڵ� ���̿� � ���̰� �ִ� ���� �𸣰ڴ�..

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, t;

bool destination[2001];
bool visited[2001];
int candidate[100];
vector<pair<int, int>> adj_list[2001];

typedef pair<pair<int, int>, int> info;	// �Ÿ�, gh ����, ��� ��ȣ

void Dijkstra(int s, int g, int h) {
	priority_queue<info, vector<info>, greater<info>> pq;

	pq.push({ {0, 1}, s });
	info cur;

	while (!pq.empty()) {
		cur = pq.top();
		pq.pop();

		if (visited[cur.second])	continue;
		
		if(cur.first.second == 0)	destination[cur.second] = true;
		visited[cur.second] = true;

		for (pair<int, int> p : adj_list[cur.second]) {
			if (!visited[p.second]) {
				if ((cur.second == g && p.second == h) || (cur.second == h && p.second == g)) 
					pq.push({ {cur.first.first + p.first, 0}, p.second });
				else 
					pq.push({ {cur.first.first + p.first, cur.first.second}, p.second });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	int s, g, h;
	while (T--) {
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		for (int i = 1; i <= n; i++) {
			destination[i] = false;
			visited[i] = false;
			adj_list[i] = {};
		}

		int a, b, d;
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> d;
			adj_list[a].push_back({ d, b });
			adj_list[b].push_back({ d, a });
		}

		for (int i = 0; i < t; i++) 
			cin >> candidate[i];
		sort(candidate, candidate + t);

		Dijkstra(s, g, h);
		
		for (int i = 0; i < t; i++) {
			if (destination[candidate[i]]) {
				cout << candidate[i] << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}