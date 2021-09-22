#include <iostream>
#include <queue>
using namespace std;

int o = 0, v = 0;
int r, c;
char yard[251][251];
bool visited[251][251];
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };

void BFS(int i, int j) {
	int sheep = 0, wolf = 0;
	visited[i][j] = true;
	queue<pair<int, int>> q;
	q.push({ i,j });
	while (!q.empty()) {
		int cur_i = q.front().first;
		int cur_j = q.front().second;
		q.pop();
		if (yard[cur_i][cur_j] == 'o')	sheep++;
		if (yard[cur_i][cur_j] == 'v')	wolf++;
		int next_i, next_j;
		for (int k = 0; k < 4; k++) {
			next_i = cur_i + di[k];
			next_j = cur_j + dj[k];
			if (next_i < 1 || next_j < 1 || next_i > r || next_j > c)
				continue;
			if (yard[next_i][next_j] != '#' && !visited[next_i][next_j]) {
				visited[next_i][next_j] = true;
				q.push({ next_i,next_j });
			}
		}
	}
	if (sheep > wolf)	o += sheep;
	else	v += wolf;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> r >> c;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			cin >> yard[i][j];
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			if (yard[i][j] != '#' && !visited[i][j])
				BFS(i, j);
	cout << o << " " << v;
	
	return 0;
}