#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m, know_cnt, cnt;
int know[51];
bool known[51];
bool matrix[51][51];
vector<int> v[51];

void BFS() {
	queue<int> q;
	for (int i = 0; i < know_cnt; i++)	q.push(know[i]);
	int cur;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int j = 1; j <= n; j++) {
			if (matrix[cur][j] && !known[j]) {
				known[j] = true;
				q.push(j);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	cin >> know_cnt;
	for (int i = 0; i < know_cnt; i++) {
		cin >> know[i];
		known[know[i]] = true;
	}

	int num;
	for (int i = 0; i < m; i++) {
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			cin >> num;
			v[i].push_back(num);
		}
		for (int j = 0; j < cnt - 1; j++) {
			for (int k = j + 1; k < cnt; k++) {
				matrix[v[i][j]][v[i][k]] = matrix[v[i][k]][v[i][j]] = true;
			}
		}
	}
	BFS();
	int result = 0;
	bool flag;
	for (int i = 0; i < m; i++) {
		flag = false;
		for (int j = 0; j < v[i].size(); j++)
			flag |= known[v[i][j]];
		if (!flag)
			result++;
	}
	cout << result;
	return 0;
}