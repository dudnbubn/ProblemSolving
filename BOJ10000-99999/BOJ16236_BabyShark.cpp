// key point : 먹을 수 있는 물고기가 맵에 존재하더라도
//				상어보다 크기가 큰 물고기들에게 둘러싸여 움직일 수 없는 경우
//				while문에서 무한루프를 돌게 된다는 점을 유의하자.

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int board[21][21];
int fish_cnt[7];
bool visited[21][21];
int shark_i, shark_j, shark_size = 2, eat;
int di[4] = { -1, 0, 0, 1 };
int dj[4] = { 0, -1, 1, 0 };

queue<pair<int, int>> q;
vector<pair<int, int>> v;

int getFish() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			visited[i][j] = false;
	
	q = {};
	q.push({ shark_i, shark_j });
	visited[shark_i][shark_j] = true;

	pair<int, int> cur;
	int t = -1, qsz;
	int next_i, next_j;
	while (!q.empty()) {
		v = {};
		t++;
		qsz = q.size();
		for (int sz = 0; sz < qsz; sz++) {
			cur = q.front();
			q.pop();
			if (board[cur.first][cur.second] != 9 && (0 < board[cur.first][cur.second] && board[cur.first][cur.second] < shark_size)) {
				fish_cnt[board[cur.first][cur.second]]--;
				if (shark_size < 7) {
					eat++;
					if (eat == shark_size) {
						eat = 0;
						shark_size++;
					}
				}

				board[shark_i][shark_j] = 0;
				board[cur.first][cur.second] = 9;
				shark_i = cur.first;
				shark_j = cur.second;

				return t;
			}

			for (int k = 0; k < 4; k++) {
				next_i = cur.first + di[k];
				next_j = cur.second + dj[k];

				if (next_i < 1 || next_j < 1 || next_i > N || next_j > N)
					continue;

				if (!visited[next_i][next_j] && board[next_i][next_j] <= shark_size) {
					visited[next_i][next_j] = true;
					v.push_back({ next_i, next_j });
				}
			}	
		}

		sort(v.begin(), v.end());
		for (pair<int, int> p : v)
			q.push(p);

	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
			
			if (board[i][j] == 9) {
				shark_i = i;
				shark_j = j;
			}
			else if (board[i][j] > 0)
				fish_cnt[board[i][j]]++;
		}
	}

	int t, T = 0;
	int can_eat = fish_cnt[1];
	while (can_eat > 0) {
		t = getFish();
		if (t == 0)	break;

		T += t;
		can_eat = 0;
		for (int i = 1; i < shark_size; i++)
			can_eat += fish_cnt[i];
	}
	cout << T;

	return 0;
}