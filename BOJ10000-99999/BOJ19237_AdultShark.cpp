#include <iostream>
#include <algorithm>

using namespace std;

int N, M, K, cnt;
pair<int, int> board[21][21];
pair<int, int> position[401];
int dir[401];
int priority[401][5][4];
bool die[401];

int di[5] = { 0, -1, 1, 0, 0 };
int dj[5] = { 0, 0, 0, -1, 1 };

// ³¿»õ »Ñ¸®±â
void spread() {
	int ci, cj;
	for (int i = 1; i <= M; i++) {
		if (die[i])	continue;
		ci = position[i].first;
		cj = position[i].second;
		board[ci][cj] = { i, K };
	}
}

// »ó¾î ÀÌµ¿
void move() {
	int ci, cj, cd, ni, nj, nd;
	bool flag;
	for (int i = 1; i <= M; i++) {
		if (die[i])	continue;
		flag = false;
		ci = position[i].first;
		cj = position[i].second;
		cd = dir[i];
		for (int d = 0; d < 4; d++) {
			nd = priority[i][cd][d];

			ni = ci + di[nd];
			nj = cj + dj[nd];
			if (ni < 1 || nj < 1 || ni > N || nj > N)
				continue;

			if (board[ni][nj].second == 0) {
				flag = true;
				dir[i] = nd;
				position[i] = { ni, nj };
				if (board[ni][nj].first > 0) {
					cnt++;
					die[i] = true;
				}
				else	board[ni][nj].first = i;
				break;
			}
		}
		if (!flag) {
			for (int d = 0; d < 4; d++) {
				nd = priority[i][cd][d];

				ni = ci + di[nd];
				nj = cj + dj[nd];
				if (ni < 1 || nj < 1 || ni > N || nj > N)
					continue;

				if (board[ni][nj].first == i) {
					dir[i] = nd;
					position[i] = { ni, nj };
					break;
				}
			}
		}
	}
}

// ³¿»õ ÁÙ¾îµé±â
void decrease() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (board[i][j].second > 0) {
				board[i][j].second--;
				if (board[i][j].second == 0)
					board[i][j].first = 0;
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j].first;
			board[i][j].second = 0;
			if (board[i][j].first)
				position[board[i][j].first] = { i, j };
		}
	}

	for (int i = 1; i <= M; i++)	cin >> dir[i];
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 0; k < 4; k++)
				cin >> priority[i][j][k];
		}
	}

	int ci, cj, cd;
	int ni, nj, nd;
	int t = 0;
	spread();
	while (cnt < M - 1 && t <= 1000) {
		t++;
		move();
		decrease();
		spread();
	}

	if (t > 1000)	cout << -1;
	else	cout << t;
	return 0;
}