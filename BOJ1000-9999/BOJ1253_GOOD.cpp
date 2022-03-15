#include <iostream>
#include <algorithm>

using namespace std;

int arr[2000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	sort(arr, arr + n);

	int result = 0;
	for (int i = 0; i < n; i++) {
		int start = 0, end = n - 1, sum;
		while (start < end) {
			if (start == i) {
				start++;
				continue;
			}
			if (end == i) {
				end--;
				continue;
			}
			sum = arr[start] + arr[end];
			if (sum < arr[i])	start++;
			else if (sum > arr[i])	end--;
			else {
				result++;
				break;
			}
		}
	}
	cout << result;
	return 0;
}