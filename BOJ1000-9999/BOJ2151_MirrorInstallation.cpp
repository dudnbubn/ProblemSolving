#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<pair<int, int>, pair<int, int>> info;
int n;
int door_i, door_j;
char board[51][51];
bool visited[51][51][4];
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };

struct compare {
	bool operator()(info a, info b) {
		if (a.second.second == b.second.second) {
			if (a.second.first == b.second.first) {
				if (a.first.second == b.first.second)
					return a.first.first > b.first.first;
				return a.first.second > b.first.second;
			}
			return a.second.first > b.second.first;
		}
		return a.second.second > b.second.second;
	}
};

priority_queue<info, vector<info>, compare> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
			if (board[i][j] == '#') {
				door_i = i;
				door_j = j;
			}
		}
	}
	for (int k = 0; k < 4; k++) {
		visited[door_i][door_j][k] = true;
		q.push({ {door_i, door_j}, {k, 0} });
	}

	int result = 2500;
	info cur;
	int next_i, next_j;
	while (!q.empty()) {
		cur = q.top();
		q.pop();
		//cout << "cur : { { " << cur.first.first << ", " << cur.first.second << " }, { " << cur.second.first << ", " << cur.second.second << " } }\n";
		if (board[cur.first.first][cur.first.second] == '#' && (cur.first.first != door_i || cur.first.second != door_j)) {
			//cout << "result : min(" << result << ", " << cur.second.second << ") = ";
			result = min(result, cur.second.second);
			//cout << result << "\n";
			continue;
		}
		next_i = cur.first.first + di[cur.second.first];
		next_j = cur.first.second + dj[cur.second.first];
		//cout << "\tnext : " << next_i << ", " << next_j << "\n";
		if (!(next_i < 1 || next_j < 1 || next_i > n || next_j > n || board[next_i][next_j] == '*')) {
			if (!visited[next_i][next_j][cur.second.first]) {
				visited[next_i][next_j][cur.second.first] = true;
				//cout << "\tq.push({ { " << next_i << ", " << next_j << " }, { " << cur.second.first << ", " << cur.second.second << " } }\n";
				q.push({ {next_i,next_j}, cur.second });
			}
		}
		if (board[cur.first.first][cur.first.second] == '!') {
			for (int k = 1; k <= 3; k += 2) {
				next_i = cur.first.first + di[(cur.second.first + k) % 4];
				next_j = cur.first.second + dj[(cur.second.first + k) % 4];
				if (next_i < 1 || next_j < 1 || next_i > n || next_j > n || board[next_i][next_j] == '*')
					continue;
				if (!visited[next_i][next_j][(cur.second.first + k) % 4]) {
					visited[next_i][next_j][(cur.second.first + k) % 4] = true;
					q.push({ {next_i,next_j}, {(cur.second.first + k) % 4, cur.second.second + 1} });
					//cout << "\tq.push({ { " << next_i << ", " << next_j << " }, { " << (cur.second.first + k) % 4 << ", " << cur.second.second + 1 << " } }\n";
				}
			}
		}
	}
	cout << result;
	return 0;
}