#include <iostream>
using namespace std;

int arr[100001] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, x, y;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		cout << arr[y] - arr[x - 1] << "\n";
	}
	return 0;
}