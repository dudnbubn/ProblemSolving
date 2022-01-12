// key point : ��� Land ���� �ִ� �Ÿ��� ���Ͽ� ���� ū �Ÿ��� ������ �ִ� ���� ������ �Ÿ�
// ��� Land ���� BFS�� ���� �ð��� �ʹ� ���� �ɸ� ���̶� ���������� �״��� �����ɸ��� �ʴ� �� ����..

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
char board[51][51];
bool visited[51][51];
int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };

int BFS(int r, int c) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			visited[i][j] = false;

	int result = -1;
	queue<pair<int, int>> q;
	q.push({ r, c });
	visited[r][c] = true;
	pair<int, int> cur;
	int qsz, next_i, next_j;
	while (!q.empty()) {
		result++;
		qsz = q.size();
		for (int i = 0; i < qsz; i++) {
			cur = q.front();
			q.pop();
			for (int k = 0; k < 4; k++) {
				next_i = cur.first + di[k];
				next_j = cur.second + dj[k];
				if (next_i < 1 || next_j < 1 || next_i > n || next_j > m)
					continue;

				if (board[next_i][next_j] == 'L' && !visited[next_i][next_j]) {
					visited[next_i][next_j] = true;
					q.push({ next_i, next_j });
				}
			}
		}
	}
	//cout << "BFS(" << r << ", " << c << ") : " << result << "\n";
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> board[i][j];

	int maximum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] == 'L')
				maximum = max(maximum, BFS(i, j));
		}
	}
	cout << maximum;
	return 0;
}