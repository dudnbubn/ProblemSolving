#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int>> coordinate;

int l = -1, r = -1, c = -1;
int dl[6] = { 0, 0, 0, 0, 1, -1 };
int dr[6] = { 1, -1, 0, 0, 0, 0 };
int dc[6] = { 0, 0, -1, 1, 0, 0 };

char dungeon[31][31][31];
bool visited[31][31][31];

int BFS(coordinate start, coordinate end) {
	queue<coordinate> q;
	q.push(start);
	int result = -1;
	while (!q.empty()) {
		result++;
		int qsz = q.size();
		int next_l, next_r, next_c;
		for (int i = 0; i < qsz; i++) {
			coordinate cur = q.front();
			q.pop();

			if (cur == end)		return result;

			for (int j = 0; j < 6; j++) {
				next_l = cur.first + dl[j];
				next_r = cur.second.first + dr[j];
				next_c = cur.second.second + dc[j];
				if (next_l < 1 || next_r < 1 || next_c < 1 || next_l > l || next_r > r || next_c > c)
					continue;
				if (!visited[next_l][next_r][next_c] && (dungeon[next_l][next_r][next_c] == '.' || dungeon[next_l][next_r][next_c] == 'E')) {
					visited[next_l][next_r][next_c] = true;
					q.push({ next_l, {next_r, next_c} });
				}
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	coordinate start, end;
	while (1) {
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0)	break;

		for (int i = 1; i <= l; i++) {
			for (int j = 1; j <= r; j++) {
				for (int k = 1; k <= c; k++) {
					cin >> dungeon[i][j][k];
					visited[i][j][k] = false;
					if (dungeon[i][j][k] == 'S') {
						start = { i, {j,k} };
						visited[i][j][k] = true;
					}
					else if (dungeon[i][j][k] == 'E')	
						end = { i, {j,k} };
				}
			}
		}
		int minute = BFS(start, end);
		if (minute == -1)	cout << "Trapped!\n";
		else	cout << "Escaped in " << minute << " minute(s).\n";
	}
	return 0;
}
