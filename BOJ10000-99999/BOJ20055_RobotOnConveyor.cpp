#include <iostream>
using namespace std;

int n, k;
int arr[201];
bool robot[201];

int main() {
	cin >> n >> k;
	for (int i = 0; i < 2 * n; i++)	cin >> arr[i];

	int up = 0;
	int down = n - 1;
	int step = 0;

	while (k > 0) {
		step++;
		if (up == 0)	up = 2 * n - 1;
		else	up--;
		down = (up + n - 1) % (2 * n);
		if (robot[down]) {
			robot[down] = false;
		}
		
		if (down < n - 1) {
			for (int i = down - 1; i >= 0; i--) {
				if (arr[i + 1] > 0 && !robot[i + 1] && robot[i]) {
					arr[i + 1]--;
					if (arr[i + 1] == 0) {
						k--;
					}
					robot[i + 1] = true;
					robot[i] = false;
				}
			}
			if (arr[0] > 0 && !robot[0] && robot[2 * n - 1]) {
				arr[0]--;
				if (arr[0] == 0) {
					k--;
				}
				robot[0] = true;
				robot[2 * n - 1] = false;
			}
			for (int i = 2 * n - 2; i >= up; i--) {
				if (arr[i + 1] > 0 && !robot[i + 1] && robot[i]) {
					arr[i + 1]--;
					if (arr[i + 1] == 0) {
						k--;
					}
					robot[i + 1] = true;
					robot[i] = false;
				}
			}
			if (robot[down]) {
				robot[down] = false;
			}
		}
		else {
			for (int i = down - 1; i >= up; i--) {
				if (arr[i + 1] > 0 && !robot[i + 1] && robot[i]) {
					arr[i + 1]--;
					if (arr[i + 1] == 0) {
						k--;
					}
					robot[i + 1] = true;
					robot[i] = false;
				}
			}
			if (robot[down]) {
				robot[down] = false;
			}
		}
		if (arr[up] > 0) {
			robot[up] = true;
			arr[up]--;
			if (arr[up] == 0) {
				k--;
			}
		}
	}
	cout << step;
	return 0;
}