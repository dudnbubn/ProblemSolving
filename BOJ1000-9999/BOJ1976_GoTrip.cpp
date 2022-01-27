#include <iostream>
#include <algorithm>
using namespace std;

#define INF 987654321

int n, m;
int matrix[201][201];
int arr[1000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> matrix[i][j];
			if (matrix[i][j] == 0 && i != j)
				matrix[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++)	cin >> arr[i];

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (k == i)	continue;
			for (int j = 1; j <= n; j++) {
				if (k == i || k == j)	continue;
				matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
			}
		}
	}
	bool flag = true;
	for (int i = 0; i < m - 1; i++) {
		if (matrix[arr[i]][arr[i + 1]] >= INF) {
			flag = false;
			break;
		}
	}
	if (flag)	cout << "YES";
	else	cout << "NO";
	return 0;
}