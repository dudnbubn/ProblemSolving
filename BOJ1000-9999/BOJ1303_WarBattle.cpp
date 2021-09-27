// "가로 크기 N"... 문제를 똑바로 읽도록 하자

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
char position[101][101] = { 0, };
bool visited[101][101] = { 0, };
int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0, -1,1 };

int BFS(int i, int j) {
	int result = 0;
	queue<pair<int, int>> q;
	visited[i][j] = true;
	q.push({ i,j });
	int cur_i, cur_j;
	int next_i, next_j;
	while (!q.empty()) {
		result++;
		cur_i = q.front().first;
		cur_j = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			next_i = cur_i + di[k];
			next_j = cur_j + dj[k];
			if (next_i < 1 || next_j < 1 || next_i > n || next_j > m)
				continue;
			if (!visited[next_i][next_j] && position[i][j] == position[next_i][next_j]) {
				visited[next_i][next_j] = true;
				q.push({ next_i, next_j });
			}
		}
	}
	return result;
}

int main() {
	int army = 0, enemy = 0;
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> position[i][j];
	int score = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visited[i][j]) {
				score = BFS(i, j);
				if (position[i][j] == 'W')	army += (score * score);
				else enemy += (score * score);
			}
		}
	}
	cout << army << " " << enemy;
	return 0;
}