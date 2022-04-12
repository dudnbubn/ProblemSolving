#include <iostream>

using namespace std;

int n, m, T;
int arr[55][55];
int index[55];
double average;
int cnt;
bool adjacent[55][55];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> T;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int x, d, k;
	bool existNumber, existAdjacent;
	for (int t = 0; t < T; t++) {
		cin >> x >> d >> k;
		existNumber = false;	existAdjacent = false;
		for (int i = x; i <= n; i += x) {
			if (d)	index[i] = (index[i] + k) % m;
			else	index[i] = (index[i] + m - k) % m;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++)
				adjacent[i][j] = false;
		}
		average = 0;	cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				if (!arr[i][(index[i] + j) % m])	continue;
				existNumber = true;
				if (arr[i][(index[i] + j) % m] == arr[i][(index[i] + j + 1) % m]) {
					adjacent[i][(index[i] + j) % m] = true;
					adjacent[i][(index[i] + j + 1) % m] = true;
					existAdjacent = true;
				}
				if (arr[i][(index[i] + j) % m] == arr[i + 1][(index[i + 1] + j) % m]) {
					adjacent[i][(index[i] + j) % m] = true;
					adjacent[i + 1][(index[i + 1] + j) % m] = true;
					existAdjacent = true;
				}
			}
		}
	
		if (existNumber) {
			for (int i = 1; i <= n; i++) {
				for (int j = 0; j < m; j++) {
					if (adjacent[i][j]) 
						arr[i][j] = 0;
					if (arr[i][j]) {
						average += arr[i][j];
						cnt++;
					}
				}
			}
			if (!existAdjacent && cnt) {
				average /= cnt;
				for (int i = 1; i <= n; i++) {
					for (int j = 0; j < m; j++) {
						if (arr[i][j] > average)	arr[i][j]--;
						else if (arr[i][j] && arr[i][j] < average)	arr[i][j]++;
					}
				}
			}
		}
	}
	int result = 0;
	for (int i = 1; i <= n; i++) 
		for (int j = 0; j < m; j++) 
			result += arr[i][(index[i] + j) % m];


	cout << result;
	return 0;
}