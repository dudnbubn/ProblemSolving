#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int H, W;
char board[100][100];
bool visited[100][100];
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

queue<pair<int, int>> q;

void clear() {
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			visited[i][j] = false;
}

void open(char key) {
	char door = (char)(key - 'a' + 'A');
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (key == board[i][j] || door == board[i][j])
				board[i][j] = '.';
		}
	}
}

void addEdges() {
	for (int i = 0; i < H; i++) {
		if (board[i][0] == '.' || ('a' <= board[i][0] && board[i][0] <= 'z')) {
			q.push({ i, 0 });
			visited[i][0] = true;
		}
		if (board[i][W - 1] == '.' || ('a' <= board[i][0] && board[i][W - 1] <= 'z')) {
			q.push({ i, W - 1 });
			visited[i][W - 1] = true;
		}
	}
	for (int j = 1; j < W - 1; j++) {
		if (board[0][j] == '.' || ('a' <= board[0][j] && board[0][j] <= 'z')) {
			q.push({ 0, j });
			visited[0][j] = true;
		}
		if (board[H - 1][j] == '.' || ('a' <= board[H - 1][j] && board[H - 1][j] <= 'z')) {
			q.push({ H - 1, j });
			visited[H - 1][j] = true;
		}
	}
}

int getDocuments() {
	int result = 0;
	q = {};
	clear();
	addEdges();

	pair<int, int> cur;
	int ci, cj, ni, nj;
	while (!q.empty()) {
		cur = q.front();
		q.pop();

		ci = cur.first;
		cj = cur.second;

		if (board[ci][cj] == '$') {
			result++;
			board[ci][cj] = '.';
		}
		else if ('a' <= board[ci][cj] && board[ci][cj] <= 'z') {
			open(board[ci][cj]);
			clear();
			addEdges();
			visited[ci][cj] = true;
		}

		for (int d = 0; d < 4; d++) {
			ni = ci + di[d];
			nj = cj + dj[d];

			if (ni < 0 || nj < 0 || ni >= H || nj >= W || visited[ni][nj] == true || board[ni][nj] == '*')
				continue;

			if (board[ni][nj] == '*' || ('A' <= board[ni][nj] && board[ni][nj] <= 'Z'))
				continue;

			visited[ni][nj] = true;
			q.push({ ni, nj });
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int TC;
	cin >> TC;

	for (int tc = 1; tc <= TC; tc++) {
		cin >> H >> W;
		int docs = 0;
		for (int i = 0; i < H; i++) 
			for (int j = 0; j < W; j++) 
				cin >> board[i][j];

		for (int i = 0; i < H; i++) {
			if (board[i][0] == '$') {
				board[i][0] = '.';
				docs++;
			}
			if (board[i][W - 1] == '$') {
				board[i][W - 1] = '.';
				docs++;
			}
		}
		for (int j = 1; j < W - 1; j++) {
			if (board[0][j] == '$') {
				board[0][j] = '.';
				docs++;
			}
			if (board[H - 1][j] == '$') {
				board[H - 1][j] = '.';
				docs++;
			}
		}
		
		string keys;
		cin >> keys;
		if (keys[0] != '0') {
			for (char key : keys)
				open(key);
		}

		cout << getDocuments() + docs << "\n";
	}
	return 0;
}