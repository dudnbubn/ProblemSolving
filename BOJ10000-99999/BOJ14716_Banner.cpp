#include <iostream>
#include <queue>
using namespace std;

int n, m;
int banner[251][251];
bool visited[251][251] = { 0, };
int di[8] = { -1,-1,-1,1,1,1,0,0 };
int dj[8] = { -1,0,1,-1,0,1,-1,1 };

void BFS(int i, int j) {
	queue<pair<int, int>> q;
	visited[i][j] = true;
	q.push({ i,j });
	int cur_i, cur_j, next_i, next_j;
	while (!q.empty()) {
		cur_i = q.front().first;
		cur_j = q.front().second;
		q.pop();
		for (int k = 0; k < 8; k++) {
			next_i = cur_i + di[k];
			next_j = cur_j + dj[k];
			if (next_i < 1 || next_j < 1 || next_i > n || next_j > m)
				continue;
			if (banner[next_i][next_j] && !visited[next_i][next_j]) {
				visited[next_i][next_j] = true;
				q.push({ next_i,next_j });
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> banner[i][j];

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (banner[i][j] && !visited[i][j]) {
				cnt++;
				BFS(i, j);
			}
		}
	}
	cout << cnt;
	return 0;
}