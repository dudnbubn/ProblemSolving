#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_N 2'000
#define MAX_K 100'000

int N, K;
int board[MAX_N + 1][MAX_N + 1];
int roots[MAX_K + 1];

int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };

typedef pair<pair<int, int>, int> piii;
queue<piii> q;
queue<piii> save;

int Find(int x) {
	if (x == roots[x])	return x;
	return roots[x] = Find(roots[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	roots[y] = x;
}

int BFS() {
	int result = 0;
	int link_count = 0;

	int qsz;
	piii current;
	int ci, cj, number, ni, nj;
	while (true) {
		while (!save.empty()) {
			current = save.front();
			save.pop();

			ci = current.first.first;
			cj = current.first.second;
			number = current.second;
			if (board[ci][cj] == 0) {
				board[ci][cj] = number;
				q.push(current);
			}

			for (int d = 0; d < 4; d++) {
				ni = ci + di[d];
				nj = cj + dj[d];

				if (ni < 1 || nj < 1 || ni > N || nj > N)	continue;

				if (board[ni][nj] && (Find(number) != Find(board[ni][nj]))) {
					link_count++;
					Union(number, board[ni][nj]);
				}
			}
		}
		
		if (link_count == K - 1)	return result;
		result++;
		
		while (!q.empty()) {
			current = q.front();
			q.pop();

			ci = current.first.first;
			cj = current.first.second;
			number = current.second;

			for (int d = 0; d < 4; d++) {
				ni = ci + di[d];
				nj = cj + dj[d];
				if (ni < 1 || nj < 1 || ni > N || nj > N || board[ni][nj])	continue;

				save.push({ {ni, nj}, number });
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;
	int a, b;
	for (int k = 1; k <= K; k++) {
		roots[k] = k;
		cin >> a >> b;
		board[a][b] = k;
		q.push({ {a, b}, k });
		save.push({ {a, b}, k });
	}

	cout << BFS();
	return 0;
}
