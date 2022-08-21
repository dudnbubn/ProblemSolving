#include <iostream>
#include <queue>

using namespace std;

int degrees[100001];
int nexts[100001];
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	int N;
	while (T--) {
		q = {};
		cin >> N;
		for (int i = 1; i <= N; i++)	degrees[i] = 0;
		for (int i = 1; i <= N; i++) {
			cin >> nexts[i];
			degrees[nexts[i]]++;
		}
		
		for (int i = 1; i <= N; i++)
			if (!degrees[i])
				q.push(i);

		int result = 0;
		int cur, next;
		while (!q.empty()) {
			cur = q.front();
			q.pop();
			result++;

			next = nexts[cur];
			if (!--degrees[next])
				q.push(next);
		}
		cout << result << "\n";
	}

	return 0;
}