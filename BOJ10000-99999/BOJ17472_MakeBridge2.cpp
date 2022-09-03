#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int board[11][11];
int parent[10];
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };

typedef pair<pair<int, int>, pair<int, int>> Sea;
vector<Sea> adjSea;

typedef pair<int, pair<int, int>> Edge;
priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

void BFS(int si, int sj, int island) {
	queue <pair<int, int>> q;
	q.push({ si, sj });
	board[si][sj] = island;

	pair<int, int> cur;
	int ni, nj;
	while (!q.empty()) {
		cur = q.front();
		q.pop();

		for (int d = 0; d < 4; d++) {
			ni = cur.first + di[d];
			nj = cur.second + dj[d];

			if (ni<1 || ni > N || nj < 1 || nj>M)
				continue;

			if (board[ni][nj] == 1) {
				board[ni][nj] = island;
				q.push({ ni, nj });
			}
			else if (board[ni][nj] == 0)
				adjSea.push_back({ {ni, nj}, {d, island} });
		}
	}
}

int Find(int x) {
	if (x == parent[x])	return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	parent[y] = x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> board[i][j];

	int island = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (board[i][j] == 1)
				BFS(i, j, ++island);
		}
	}

	for (int i = 2; i <= island; i++)	parent[i] = i;
	for (Sea sea : adjSea) {
		int d = sea.second.first;
		int i = sea.first.first;
		int j = sea.first.second;
		int is = sea.second.second;
		int len = 0;
		while (1 <= i && i <= N && 1 <= j && j <= M) {
			if (board[i][j] > 1) {
				if (len > 1 && board[i][j] != is)
					pq.push({ len, {is, board[i][j]} });
				break;
			}
			i += di[d];
			j += dj[d];
			len++;
		}
	}

	int result = 0, x, y;
	Edge e;
	for (int i = 0; i < island - 2;) {
		if (pq.empty()) {
			result = -1;
			break;
		}

		e = pq.top();
		pq.pop();
		x = e.second.first;
		y = e.second.second;

		if (Find(x) != Find(y)) {
			result += e.first;
			Union(x, y);
			i++;
		}
	}

	cout << result;

	return 0;
}