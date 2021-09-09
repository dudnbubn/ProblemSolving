#include <iostream>
using namespace std;

int main() {
	int testcase, n, m, cnt;
	cin >> testcase;
	while (testcase--) {
		cin >> n >> m;
		cnt = 0;
		for (int i = n; i <= m; i++) {
			int temp = i;
			if (temp == 0)	cnt++;
			else {
				while (temp > 0) {
					if (temp % 10 == 0)	cnt++;
					temp /= 10;
				}
			}
		}
		cout << cnt << "\n";
	}
	
	return 0;
}