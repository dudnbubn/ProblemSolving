#include <iostream>

using namespace std;

void recur(int k, int source, int destination) {
	if (k == 1) {
		cout << source << " " << destination << "\n";
		return;
	}
	int temp = 6 - (source + destination);
	recur(k - 1, source, temp);
	cout << source << " " << destination << "\n";
	recur(k - 1, temp, destination);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	int result = 1;
	for (int i = 0; i < n - 1; i++)
		result = result * 2 + 1;
	cout << result << "\n";
	recur(n, 1, 3);
	return 0;
}