#include <iostream>
#include <algorithm>
using namespace std;

long long koong[70] = { 0, };
int arr[70];

int main() {
	int testcase, n, maximum = 0;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		cin >> arr[i];
		maximum = max(maximum, arr[i]);
	}
	koong[0] = 1;	koong[1] = 1;	koong[2] = 2;	koong[3] = 4;

	for (int i = 4; i <= maximum; i++)
		koong[i] = koong[i - 1] + koong[i - 2] + koong[i - 3] + koong[i - 4];

	for (int i = 0; i < testcase; i++)	cout << koong[arr[i]] << "\n";

	return 0;
}