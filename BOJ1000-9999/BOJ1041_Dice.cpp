#include <iostream>
#include <algorithm>
using namespace std;

long long dice[7];

int main() {
	long long n;
	cin >> n;

	long long min_3d = 987654321;
	long long min_2d = 987654321;
	long long min_1d = 987654321;

	for (int i = 1; i <= 6; i++) {
		cin >> dice[i];
		min_1d = min(min_1d, dice[i]);
	}
	
	min_3d = min(min_3d, dice[1] + dice[2] + dice[3]);
	min_3d = min(min_3d, dice[1] + dice[2] + dice[4]);
	min_3d = min(min_3d, dice[1] + dice[3] + dice[5]);
	min_3d = min(min_3d, dice[1] + dice[4] + dice[5]);
	min_3d = min(min_3d, dice[2] + dice[3] + dice[6]);
	min_3d = min(min_3d, dice[2] + dice[4] + dice[6]);
	min_3d = min(min_3d, dice[3] + dice[5] + dice[6]);
	min_3d = min(min_3d, dice[4] + dice[5] + dice[6]);

	min_2d = min(min_2d, dice[1] + dice[2]);
	min_2d = min(min_2d, dice[1] + dice[3]);
	min_2d = min(min_2d, dice[1] + dice[4]);
	min_2d = min(min_2d, dice[1] + dice[5]);
	min_2d = min(min_2d, dice[2] + dice[3]);
	min_2d = min(min_2d, dice[2] + dice[4]);
	min_2d = min(min_2d, dice[2] + dice[6]);
	min_2d = min(min_2d, dice[3] + dice[5]);
	min_2d = min(min_2d, dice[3] + dice[6]);
	min_2d = min(min_2d, dice[4] + dice[5]);
	min_2d = min(min_2d, dice[4] + dice[6]);
	min_2d = min(min_2d, dice[5] + dice[6]);


	if (n == 1) {
		long long result = 0;
		long long maximum = 0;
		for (int i = 1; i <= 6; i++) {
			result += dice[i];
			maximum = max(maximum, dice[i]);
		}
		cout << result - maximum;
	}
	else if (n == 2) {
		cout << min_3d * 4 + min_2d * 4;
	}
	else {
		long long result = min_3d * 4 + min_2d * (8 * n - 12) + min_1d * (5 * n * n - 16 * n + 12);
		cout << result;
	}

	return 0;
}