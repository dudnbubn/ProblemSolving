#include <iostream>

using namespace std;

int n;
int matrix[21][21];

int main() {
	cin >> n;
	int result = 0;
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> matrix[i][j];
			result += matrix[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)	continue;
			for (int k = 1; k <= n; k++) {
				if (i == k || j == k)	continue;
				if (matrix[i][j] > matrix[i][k] + matrix[k][j])
					flag = false;
				if (matrix[i][j] == matrix[i][k] + matrix[k][j]) {
					result -= matrix[i][j];
					break;
				}
			}
		}
	}

	result /= 2;
	if (flag)	cout << result;
	else	cout << -1;
	return 0;
}