#include <iostream>
using namespace std;

int n, m;
int arr[51][51];

int main() {
	int sz = 0;
	char input;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> input;
			arr[i][j] = input - '0';
		}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (n - i + 1 <= sz || m - j + 1 <= sz)	continue;
			for (int k = sz; i + k <= n && j + k <= m; k++) {
				if (arr[i][j] == arr[i + k][j] && arr[i][j] == arr[i][j + k] && arr[i][j] == arr[i + k][j + k])
					sz = k + 1;
			}
		}
	}
	if (sz == 0)	cout << 1;
	else	cout << sz * sz;
	return 0;
}