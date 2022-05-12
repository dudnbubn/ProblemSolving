#include <iostream>

using namespace std;

int r, c;
int arr[755][755][3];

int main() {
	char input;
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> input;
			arr[i][j][0] = input - '0';
			if (arr[i][j][0]) {
				arr[i][j][1] = arr[i - 1][j + 1][1] + 1;
				arr[i][j][2] = arr[i - 1][j - 1][2] + 1;
			}
		}
	}

	int result = 0;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (arr[i][j][0] && (arr[i][j][1] > result && arr[i][j][2] > result)) {
				int range = arr[i][j][1] < arr[i][j][2] ? arr[i][j][1] : arr[i][j][2];
				for (int k = result + 1; k <= range; k++) {
					if ((arr[i - k + 1][j - k + 1][1] >= k) && (arr[i - k + 1][j + k - 1][2] >= k))
						result = result > k ? result : k;
				}
			}
		}
	}
	cout << result;
	return 0;
}