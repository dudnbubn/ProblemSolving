#include <iostream>

using namespace std;

int N, M, H, result = 4;
bool visited[11][31];

void comb(int cnt, int si, int sj) {
	if (cnt > 3)	return;

	bool flag = true;
	for (int i = 1; i <= N; i++) {
		int ci = i;
		for (int j = 1; j <= H; j++) {
			if (visited[ci - 1][j])	ci--;
			else if (visited[ci][j])	ci++;
		}
		if (ci != i) {
			flag = false;
			break;
		}
	}
	if (flag) {
		result = result < cnt ? result : cnt;
	}
	else {
		for(int i=si;i<N;i++){
			for (int j = 1; j <= H; j++) {
				if (visited[i][j] || (i == si && j < sj)) continue;
				visited[i][j] = true;
				comb(cnt + 1, i, j + 1);
				visited[i][j] = false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N >> M >> H;

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		visited[b][a] = true;
	}

	comb(0, 1, 1);

	if (result > 3)	cout << -1;
	else	cout << result;

	return 0;
}