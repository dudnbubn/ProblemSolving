#include <iostream>
#include <algorithm>
using namespace std;

int n, maximum = 1;
int min_cnt[1001];
int sz[1001];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> sz[i];
		min_cnt[i] = 1;
	}
	int temp = 0;
	for (int i = 2; i <= n; i++) {
		temp = 0;
		for (int j = i - 1; j >= 1; j--) {
			if (sz[j] < sz[i]) {
				temp = max(temp, min_cnt[j]);
			}
		}
		min_cnt[i] = temp + 1;
		maximum = max(maximum, min_cnt[i]);
	}
	cout << maximum;
	return 0;
}