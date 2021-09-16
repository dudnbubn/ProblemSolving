#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, k, start, end, cnt = 0;
	string input;
	cin >> n >> k;
	cin >> input;
	int sz = input.size();
	for (int i = 0; i < sz; i++) {
		if (input[i] == 'P') {
			start = max(0, i - k);
			end = min(sz - 1, i + k);
			for (int j = start; j <= end; j++) {
				if (i == j)	continue;
				if (input[j] == 'H') {
					input[j] = 'X';
					cnt++;
					break;
				}
			}
		}
	}
	cout << cnt;
	return 0;
}