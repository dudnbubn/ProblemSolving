// key point : floyd-warshall algorithm

#include <iostream>
#include <algorithm>
using namespace std;

#define INF 987654321

int n, m;
int matrix[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			matrix[i][j] = INF;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		matrix[a][b] = min(matrix[a][b], c);
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (k == i)	continue;
			for (int j = 1; j <= n; j++) {
				if (i == j)	continue;
				matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (matrix[i][j] == INF)
				cout << 0 << " ";
			else 
				cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}