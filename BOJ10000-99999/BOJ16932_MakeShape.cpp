#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int N, M;
int board[1001][1001];
bool visited[1001][1001];

int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };
vector<int> shapes;

void BFS(int i, int j, int index) {
	visited[i][j] = true;
	board[i][j] = index;
	queue<pair<int, int>> q;
	q.push({ i, j });
	pair<int, int> cur;
	int ci, cj, ni, nj;
	int cnt = 0;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		cnt++;

		ci = cur.first;
		cj = cur.second;
		for (int d = 0; d < 4; d++) {
			ni = ci + di[d];
			nj = cj + dj[d];

			if (ni < 1 || nj < 1 || ni > N || nj > M)
				continue;

			if (!visited[ni][nj] && board[ni][nj]) {
				visited[ni][nj] = true;
				q.push({ ni, nj });
				board[ni][nj] = index;
			}
		}
	}
	shapes.push_back(cnt);
}

bool compare(int a, int b) {
	return shapes[a] > shapes[b];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= M; j++)
			cin >> board[i][j];
	
	shapes.push_back(0);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (board[i][j] && !visited[i][j]) {
				BFS(i, j, shapes.size());
			}
		}
	}
	int result = 1;
	set<int> temp;
	int ni, nj;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!board[i][j]) {
				temp = {};
				for (int d = 0; d < 4; d++) {
					ni = i + di[d];
					nj = j + dj[d];

					if (ni < 1 || nj < 1 || ni > N || nj > M)
						continue;

					if (board[ni][nj])
						temp.insert(board[ni][nj]);
				}

				int res = 1;
				for (int t : temp)	res += shapes[t];
				result = result > res ? result : res;
			}
		}
	}

	cout << result;

	return 0;
}