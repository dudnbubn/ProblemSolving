// Dijkstra 에서 이미 방문한 노드를 체크하는 경우
//	while (visited[cur.second]) {
//		cur = pq.top();
//		pq.pop();
//	}
// 으로 코드를 실행할 경우 시간 초과가 발생한다.

// 하지만
//	if (visited[cur.second])	continue;
// 로 작성하는 경우 정답으로 처리가 된다.

// 두 코드 사이에 어떤 차이가 있는 지는 모르겠다..

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

typedef pair<pair<int, int>, int> info;	// 거리, gh 여부, 노드 번호

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