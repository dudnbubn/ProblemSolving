#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, k;
bool board[101][101] = { 0, };
bool visited[101][101] = { 0, };
vector<int> result;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int BFS(int x, int y) {
	queue<pair<int, int>> q;
	visited[y][x] = true;
	int cur_x, cur_y;
	int next_x, next_y;
	int result = 0;
	q.push({ y,x });
	while (!q.empty()) {
		result++;
		cur_x = q.front().second;
		cur_y = q.front().first;
		q.pop();
		for (int k = 0; k < 4; k++) {
			next_x = cur_x + dx[k];
			next_y = cur_y + dy[k];
			if (next_x < 0 || next_y < 0 || next_x >= m || next_y >= n)
				continue;
			if (!board[next_y][next_x] && !visited[next_y][next_x]) {
				visited[next_y][next_x] = true;
				q.push({ next_y, next_x });
			}
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	int x1, y1, x2, y2;
	for (int i = 0; i < k; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int x = x1; x < x2; x++) {
			for (int y = y1; y < y2; y++) {
				board[y][x] = 1;
			}
		}
	}
	for (int x = 0; x < m; x++) {
		for (int y = 0; y < n; y++) {
			if (board[y][x] == 0 && !visited[y][x])
				result.push_back(BFS(x, y));
		}
	}
	sort(result.begin(), result.end());

	cout << result.size() << "\n";
	for (int i : result)
		cout << i << " ";
	return 0;
}