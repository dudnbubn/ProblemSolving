#include <iostream>
#include <algorithm>

using namespace std;

int arr[200'000];
int counts[100'001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;
	for (int n = 0; n < N; n++)	cin >> arr[n];

	int result = 0;

	int start = 0;
	for (int end = 0; end < N; end++) {
		counts[arr[end]]++;
		while (counts[arr[end]] > K) {
			counts[arr[start]]--;
			start++;
		}
		result = max(result, end - start + 1);
	}
	cout << result;
}