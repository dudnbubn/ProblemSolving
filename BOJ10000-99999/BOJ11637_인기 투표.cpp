#include <iostream>

using namespace std;

int arr[11];

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int TC;
	cin >> TC;

	int N;
	int maximum, index, sum, cnt;
	while (TC--) {
		cin >> N;
		sum = maximum = index = cnt = 0;
		for (int n = 1; n <= N; n++) {
			cin >> arr[n];
			sum += arr[n];
		}

		for (int n = 1; n <= N; n++) {
			if (maximum < arr[n]) {
				maximum = arr[n];
				cnt = 1;
				index = n;
			}
			else if (maximum == arr[n]) {
				cnt++;
			}
		}

		if (cnt == 1) {
			if (maximum * 2 <= sum)	cout << "minority winner " << index << "\n";
			else	cout << "majority winner " << index << "\n";
		}
		else {
			cout << "no winner\n";
		}
	}
}