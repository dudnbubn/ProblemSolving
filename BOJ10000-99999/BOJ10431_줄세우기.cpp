#include <iostream>
#include <algorithm>

using namespace std;

int arr[20];

int main() {
	int TC;
	cin >> TC;
	
	int tc;
	while(TC--) {
		cin >> tc;

		int result = 0;
		for (int i = 0; i < 20; i++)	cin >> arr[i];

		for (int i = 1; i < 20; i++) {
			int index = lower_bound(arr, arr + i, arr[i]) - arr;
			result += i - index;
			sort(arr, arr + i + 1);
		}

		cout << tc << " " << result << "\n";
	}
}