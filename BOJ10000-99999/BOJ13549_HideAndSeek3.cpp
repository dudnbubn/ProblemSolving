// BFS를 돌 때 순간이동 시 해당 위치의 * 2의 제곱수 들은 모두 같은 레벨에 위치하게 되는데
// 이 때 해당 위치가 0 이면 for 문에서 2의 제곱수를 곱하여도 계속 0 이므로 무한 루프를 돌게 된다는 점을 주의해야한다.

#include <iostream>
#include <queue>
using namespace std;

int n, k;
queue<int> q;
bool visited[200001] = { 0, };
int sec = 0;

int main() {
	cin >> n >> k;

	if (n == 0) {
		if (n == k) {
			cout << sec;
			return 0;
		}
		visited[n] = true;
		q.push(n);
	}
	else {
		for (int i = 1; i * n <= 200000; i *= 2) {
			if (i * n == k) {
				cout << sec;
				return 0;
			}
			visited[i * n] = true;
			q.push(i * n);
		}
	}

	while (!q.empty()) {
		sec++;
		int qsz = q.size();
		for (int i = 0; i < qsz; i++) {
			int cur = q.front();
			q.pop();

			int next;
			for (int l = 0; l < 2; l++) {
				if (l == 0)	next = cur - 1;
				else if (l == 1)	next = cur + 1;

				if (next == 0) {
					visited[next] = true;
					if (next == k) {
						cout << sec;
						return 0;
					}
				}
				else if (next > 0) {
					for (int j = 1; j * next <= 200000; j *= 2) {
						if (j * next == k) {
							cout << sec;
							return 0;
						}
						if (!visited[j * next]) {
							visited[j * next] = true;
							q.push(j * next);
						}
					}
				}
			}
		}
	}

	return 0;
}