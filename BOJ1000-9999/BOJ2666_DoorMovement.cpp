#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;
int minimum = (1 << 31) - 1;
int arr[20];

void Brute(int k, int o1, int o2, int move) {
	if (k == m) {
		minimum = min(minimum, move);
		return;
	}
	Brute(k + 1, arr[k], o2, move + abs(arr[k] - o1));
	Brute(k + 1, o1, arr[k], move + abs(arr[k] - o2));
}

int main() {
	cin >> n;
	int o1, o2;
	cin >> o1 >> o2;
	cin >> m;
	for (int i = 0; i < m; i++)	cin >> arr[i];
	Brute(0, o1, o2, 0);
	cout << minimum;

	return 0;
}