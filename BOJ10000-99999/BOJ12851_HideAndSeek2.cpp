#include <iostream>
#include <queue>

using namespace std;

int N, K;
queue<int> q;
queue<int> save;

int cnt[200000];
bool visited[200000];

int main() {
	cin >> N >> K;

	if (K <= N) {
		cout << N - K << "\n1";
	}
	else {
		q.push(N);
		visited[N] = true;
		cnt[N] = 1;
		
		int cur, level = -1, qsz;
		while (!q.empty()) {
			level++;
			qsz = q.size();
			for (int sz = 0; sz < qsz; sz++) {
				cur = q.front();
				q.pop();

				if (cur == K) {
					cout << level << "\n" << cnt[K];
					return 0;
				}

				if (cur > 0 && !visited[cur - 1]) {
					if (cnt[cur - 1] == 0) {
						q.push(cur - 1);
						save.push(cur - 1);
					}
					cnt[cur - 1] += cnt[cur];
				}
				if (cur < 100000 && !visited[cur + 1]) {
					if (cnt[cur + 1] == 0) {
						q.push(cur + 1);
						save.push(cur + 1);
					}
					cnt[cur + 1] += cnt[cur];
				}
				if (cur < 100000 && !visited[cur * 2]) {
					if (cnt[cur * 2] == 0) {
						q.push(cur * 2);
						save.push(cur * 2);
					}
					cnt[cur * 2] += cnt[cur];
				}
			}
			
			while (!save.empty()) {
				cur = save.front();
				save.pop();
				visited[cur] = true;
			}
		}
	}
	return 0;
}