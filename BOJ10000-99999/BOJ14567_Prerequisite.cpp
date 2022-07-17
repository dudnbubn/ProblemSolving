#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int result[1001];
int degree[1001];
vector<int> v[1001];
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	int A, B;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		degree[B]++;
		v[A].push_back(B);
	}
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0)
			q.push(i);
	}

	int r = 0, qsz, cur;
	while (!q.empty()) {
		r++;
		qsz = q.size();
		for (int i = 0; i < qsz; i++) {
			cur = q.front();
			q.pop();
			result[cur] = r;

			for (int adj : v[cur]) {
				if (degree[adj] > 0) {
					degree[adj]--;
					if (degree[adj] == 0)
						q.push(adj);
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)
		cout << result[i] << " ";

	return 0;
}