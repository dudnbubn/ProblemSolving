// BFS를 이용하면 간단하게 해결되는 문제이다.
// 각 테스트케이스마다 큐를 비워줘야 한다는 것만 인지하도록 하자.
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int chess[300][300] = { 0, };
bool visited[300][300] = { 0, };
queue<pair<int, int>> q;
int di[8] = { -1, -2,-2,-1,1,2,2,1 };
int dj[8] = { -2,-1,1,2,2,1,-1,-2 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;
	cin >> testcase;
	while (testcase--) {
		cin >> n;
		while (!q.empty())
			q.pop();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				chess[i][j] = 0;
				visited[i][j] = 0;
			}
		}
		
		pair<int, int> start, end;
		bool arrive = false;
		cin >> start.first >> start.second;
		cin >> end.first >> end.second;
		visited[start.first][start.second] = true;
		if (start == end) {
			cout << 0 << "\n";
			continue;
		}
		q.push(start);
		int move = 0;
		while (!q.empty()) {
			move++;
			int qsz = q.size();
			for (int i = 0; i < qsz; i++) {
				pair<int, int> cur = q.front();
				q.pop();
				for (int k = 0; k < 8; k++) {
					int temp_i = cur.first + di[k];
					int temp_j = cur.second + dj[k];
					if (temp_i < 0 || temp_i >= n || temp_j < 0 || temp_j >= n)
						continue;
					if ((temp_i == end.first) && (temp_j == end.second)) {
						arrive = true;
						break;
					}
					if (!visited[temp_i][temp_j]) {
						visited[temp_i][temp_j] = true;
						q.push({ temp_i,temp_j });
					}
				}
				if (arrive)	break;
			}
			if (arrive)	break;
		}
		cout << move << "\n";
	}
	return 0;
}