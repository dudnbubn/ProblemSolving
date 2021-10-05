#include <iostream>
using namespace std;

int main() {;
	int n;
	cin >> n;
	int sum = 0, cnt = 0;
	int start = 1, end = 1;
	while (start <= n) {
		if (sum <= n) {
			if (sum == n)	cnt++;
			sum += end;
			end++;
		}
		else {
			sum -= start;
			start++;
		}
	}
	cout << cnt;
	return 0;
}