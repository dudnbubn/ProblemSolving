// key point : Floyd Warshall

#include <iostream>
#include <algorithm>
using namespace std;

#define INF 987654321

int n, m, r;
int matrix[101][101];
int item[101];

int main() {
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) matrix[i][j] = 0;
			else	matrix[i][j] = INF;
		}
	}
	for (int i = 1; i <= n; i++)	cin >> item[i];
	int a, b, l;
	for (int i = 0; i < r; i++) {
		cin >> a >> b >> l;
		matrix[a][b] = l;
		matrix[b][a] = l;
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (k == i)	continue;
			for (int j = 1; j <= n; j++) {
				if (k == i || k == j)	continue;
				matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
			}
		}
	}
	
	int maximum = 0;
	int sum;
	for (int i = 1; i <= n; i++) {
		sum = 0;
		for (int j = 1; j <= n; j++) {
			if (matrix[i][j] <= m)	sum += item[j];
		}
		maximum = max(maximum, sum);
	}
	cout << maximum;
	return 0;
}