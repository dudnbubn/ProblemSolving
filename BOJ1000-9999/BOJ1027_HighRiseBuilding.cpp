#include <iostream>

using namespace std;

int arr[50];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	int result = 0, cnt;
	double dx, dy, height;
	bool flag;
	for (int i = 0; i < n; i++) {
		cnt = 0;
		if (i > 0) {
			for (int j = i - 1; j >= 0; j--) {
				flag = true;
				dx = j - i;		dy = arr[j] - arr[i];
				for (int k = i - 1; k > j; k--) {
					height = dy * (k - i) / dx + arr[i];
					if (height <= arr[k]) {
						flag = false;
						break;
					}
				}
				if (flag)
					cnt++;
			}
		}
		if (i < n - 1) {
			for (int j = i + 1; j < n; j++) {
				flag = true;
				dx = j - i;		dy = arr[j] - arr[i];
				for (int k = i + 1; k < j; k++) {
					height = dy * (k - i) / dx + arr[i];
					if (height <= arr[k]) {
						flag = false;
						break;
					}
				}
				if (flag)
					cnt++;
			}
		}
		result = result > cnt ? result : cnt;
	}
	cout << result;
	return 0;
}