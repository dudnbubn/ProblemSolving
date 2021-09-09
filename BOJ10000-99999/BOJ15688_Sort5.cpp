#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000000];

bool compare(int a, int b) {
	return a < b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n, compare);
	for (int i = 0; i < n; i++)	cout << arr[i] << "\n";
	return 0;
}