#include <iostream>
#include <algorithm>
using namespace std;

int len(int first, int second) {
	int temp;
	int cnt = 1;
	while (second >= 0) {
		temp = first - second;
		first = second;
		second = temp;
		cnt++;
	}
	return cnt;
}

int main() {
	int first, cnt = 0, save = 0, cur;
	cin >> first;
	for (int i = first / 2; i <= first; i++) {
		cur = len(first, i);
		if (cnt < cur) {
			cnt = cur;
			save = i;
		}	
	}
	int temp = 0;
	cout << cnt << "\n";
	while (first >= 0) {
		cout << first << " ";
		temp = first;
		first = save;
		save = temp - save;
	}
	return 0;
}