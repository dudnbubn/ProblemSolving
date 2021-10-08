#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];

bool compare(int a, int b) {
	return a > b;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	long long total = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		total += arr[i];
	}
	sort(arr, arr + n, compare);
	long long sale = 0;
	for (int i = 0; i < n; i++) {
		if ((i + 1) % 3 == 0)	sale += arr[i];
	}
	cout << total - sale;
	return 0;
}