#include <iostream>
#include <algorithm>
using namespace std;

#define INF 987654321

int v, e;
int matrix[401][401];

int main() {
	cin >> v >> e;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i == j)	matrix[i][j] = 0;
			else matrix[i][j] = INF;
		}
	}
	int a, b, c;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		matrix[a][b] = c;
	}
	
	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			if (k == i)	continue;
			for (int j = 1; j <= v; j++) {
				if (k == i || k == j)	continue;
				matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
			}
		}
	}
	int result = INF;
	for (int i = 1; i < v; i++) {
		for (int j = i + 1; j <= v; j++) {
			result = min(result, matrix[i][j] + matrix[j][i]);
		}
	}
	if (result >= INF)	cout << -1;
	else	cout << result;
	return 0;
}