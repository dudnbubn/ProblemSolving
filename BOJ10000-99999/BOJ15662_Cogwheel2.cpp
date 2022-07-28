#include <iostream>
#include <algorithm>

using namespace std;

int T, K;
int status[1001][8];
int index[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;

	string input;
	for (int i = 1; i <= T; i++) {
		cin >> input;
		for (int j = 0; j < 8; j++) {
			status[i][j] = input[j] - '0';
		}
	}
	cin >> K;
	int num, dir;
	for (int i = 0; i < K; i++) {
		cin >> num >> dir;
		int len = 0;
		for (int j = num - 1; j >= 1; j--) {
			if (status[j][(index[j] + 2) % 8] != status[j + 1][(index[j + 1] + 6) % 8])
				len++;
			else
				break;
		}
		int temp = dir;
		for (int j = 1; j <= len; j++) {
			index[num - j] = (index[num - j] + 8 + temp) % 8;
			temp *= -1;
		}

		len = 0;
		for (int j = num + 1; j <= T; j++) {
			if (status[j][(index[j] + 6) % 8] != status[j - 1][(index[j - 1] + 2) % 8])
				len++;
			else
				break;
		}
		temp = dir;
		for (int j = 1; j <= len; j++) {
			index[num + j] = (index[num + j] + 8 + temp) % 8;
			temp *= -1;
		}

		index[num] = (index[num] + 8 - dir) % 8;
	}

	int result = 0;
	for (int i = 1; i <= T; i++) {
		if (status[i][index[i]]) {
			result++;
		}
	}

	cout << result;

	return 0;
}