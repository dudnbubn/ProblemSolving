#include <iostream>

using namespace std;

int n, k;
int arr[9];
bool visited[9];

int result = 0;

void Brute(int cnt, int weight) {
	if (cnt == n) {
		result++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i] && weight+arr[i]-k >= 500) {
			visited[i] = true;
			Brute(cnt + 1, weight + arr[i] - k);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)	cin >> arr[i];

	Brute(0, 500);
	cout << result;
	return 0;
}