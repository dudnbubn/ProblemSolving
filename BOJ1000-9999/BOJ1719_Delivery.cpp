#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define INF 987654321

int n, m;
int matrix[201][201];
int result[201][201];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		matrix[a][b] = c;
		matrix[b][a] = c;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (matrix[i][j] == 0) {
				if(i!=j)	matrix[i][j] = INF;
				result[i][j] = INF;
			}
			else {
				result[i][j] = j;
			}
		}
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (k == i)	continue;
			for (int j = 1; j <= n; j++) {
				if (k == i || k == j)	continue;
				
				if (matrix[i][j] > matrix[i][k] + matrix[k][j]) {
					matrix[i][j] = matrix[i][k] + matrix[k][j];
					result[i][j] = result[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (result[i][j] == INF)	cout << "- ";
			else	cout << result[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}