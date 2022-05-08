#include <iostream>
#include <unordered_set>

using namespace std;

int n;
int arr[13];
unordered_set<int> us;

void Brute(int k, int result) {
	if (k == n) {
		us.insert(result);
		return;
	}
	Brute(k + 1, result);
	Brute(k + 1, result - arr[k]);
	Brute(k + 1, result + arr[k]);
}

int main() {
	cin >> n;
	int end = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		end += arr[i];
	}
	Brute(0, 0);

	int result = 0;
	for (int i = 1; i <= end; i++) {
		if (us.find(i) == us.end())
			result++;
	}
	cout << result;

	return 0;
}