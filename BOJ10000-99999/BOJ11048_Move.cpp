#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int maze[1001][1001] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> maze[i][j];

	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) 
			maze[i][j] += max(maze[i - 1][j], maze[i][j - 1]);
		
	cout << maze[n][m];
	return 0;
}