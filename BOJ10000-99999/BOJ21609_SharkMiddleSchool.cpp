#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int board[20][20];
int indexing[20][20];
bool visited[20][20];
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == -2)	cout << " \t";
			else	cout << board[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "\n";
}

void clear() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
			indexing[i][j] = 0;
		}
	}
}

int erase(int number) {
	int block = 0;
	q = {};
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (indexing[i][j] == number) {
				q.push({ i, j });
				block = board[i][j];
				board[i][j] = -2;
			}
		}
	}
	int result = 0;
	pair<int, int> cur;
	int ci, cj, ni, nj;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		result++;
		ci = cur.first;
		cj = cur.second;
		for (int d = 0; d < 4; d++) {
			ni = ci + di[d];
			nj = cj + dj[d];
			if (ni < 0 || nj < 0 || ni >= N || nj >= N)
				continue;

			if (board[ni][nj] == 0) {
				board[ni][nj] = -2;
				q.push({ ni, nj });
			}
		}
	}
	return result;
}

pair<int, int> BFS(int ci, int cj, int block, int number) {
	q = {};
	q.push({ ci, cj });
	indexing[ci][cj] = number;
	pair<int, int> cur;
	int ni, nj, cnt = 0, rainbow = 0;
	while (!q.empty()) {
		cur = q.front();
		q.pop();

		cnt++;
		ci = cur.first;
		cj = cur.second;
		for (int d = 0; d < 4; d++) {
			ni = ci + di[d];
			nj = cj + dj[d];
			if (ni < 0 || nj < 0 || ni >= N || nj >= N || indexing[ni][nj] == number)
				continue;
			
			if (board[ni][nj] == 0 || board[ni][nj] == block) {
				if (board[ni][nj] == 0)	rainbow++;
				indexing[ni][nj] = number;
				q.push({ ni, nj });
			}
		}
	}
	return { cnt, rainbow };
}

int get_score() {
	clear();
	int index = 0;
	pair<int, int> bfs;
	int cnt = 0, rainbow = 0, max_cnt = 0, max_rainbow = 0, number = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] > 0 && indexing[i][j] == 0) {
				bfs = BFS(i, j, board[i][j], ++index);
				cnt = bfs.first;
				rainbow = bfs.second;
				if (cnt > max_cnt) {
					max_cnt = cnt;
					max_rainbow = rainbow;
					number = index;
				}
				else if (cnt == max_cnt && rainbow >= max_rainbow) {
					max_rainbow = rainbow;
					number = index;
				}
			}
		}
	}
	int result = erase(number);
	return result * result;
}

void gravity() {
	int ni;
	for (int i = N - 2; i >= 0; i--) {
		for (int j = N - 1; j >= 0; j--) {
			if (board[i][j] < 0)	continue;
			
			ni = i + 1;
			while (board[ni][j] == -2) {
				ni++;
				if (ni >= N)	break;
			}
			ni--;
			if (ni == i)	continue;
			int temp = board[i][j];
			board[i][j] = board[ni][j];
			board[ni][j] = temp;
		}
	}
}

void rotate() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			indexing[i][j] = board[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[N - 1 - j][i] = indexing[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	int result = 0;
	
	int score = get_score();
	while (score > 1) {
		result += score;

		gravity();

		rotate();

		gravity();

		score = get_score();
	}
	cout << result;
	return 0;
}