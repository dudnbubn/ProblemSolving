#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000000] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, x;

	while (true) {
		cin >> x >> n;
		if (cin.eof())	break;
		x *= 1e7;
		for (int i = 0; i < n; i++)	cin >> arr[i];
		sort(arr, arr + n);

		int start = 0, end = n - 1, sum = 0;
		while (start < end) {
			sum = arr[start] + arr[end];
			if (sum == x)	break;
			if (sum < x) start++;
			else	end--;
		}
		if (sum == x)	cout << "yes " << arr[start] << " " << arr[end] << "\n";
		else	cout << "danger\n";
	}
	return 0;
}