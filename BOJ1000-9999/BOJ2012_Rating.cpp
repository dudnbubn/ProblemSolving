#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[500000];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	sort(arr, arr + n);

	long long gap = 0;
	for (int i = 0; i < n; i++)
		gap += abs(i + 1 - arr[i]);
	cout << gap;
	return 0;
}