#include <iostream>
#include <algorithm>
using namespace std;

char matrix[51][51];
bool linked[51];
int main() {
	int n, cnt, maximum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> matrix[i][j];

	for (int i = 1; i <= n; i++) {
		cnt = -1;
		for (int j = 1; j <= n; j++)	linked[j] = false;

		for (int j = 1; j <= n; j++) {
			if (matrix[i][j] == 'Y') {
				linked[j] = true;
				for (int k = 1; k <= n; k++) {
					if (matrix[j][k] == 'Y')
						linked[k] = true;
				}
			}
		}
		for (int j = 1; j <= n; j++)
			if (linked[j])	cnt++;
		maximum = max(maximum, cnt);
	}
	cout << maximum;
	return 0;
}