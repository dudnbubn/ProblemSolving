#include <iostream>

using namespace std;

#define MAX_N 250'000

int arr[MAX_N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, X;
	cin >> N >> X;

	int result = 0, subsum = 0, cnt = 0;
	for (int n = 0; n < N; n++) {
		cin >> arr[n];
		subsum += arr[n];
		if (n >= X) subsum -= arr[n - X];
		
		if (result < subsum) {
			result = subsum;
			cnt = 1;
		}
		else if (result == subsum) {
			cnt++;
		}
	}
	
	if (result)	cout << result << "\n" << cnt;
	else	cout << "SAD";
}