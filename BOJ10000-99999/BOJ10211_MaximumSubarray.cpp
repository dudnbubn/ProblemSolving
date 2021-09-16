#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1001];

int main() {
	int testcase, maximum;
	cin >> testcase;
	while (testcase--) {
		cin >> n;
		for (int i = 0; i < n; i++)	cin >> arr[i];
		maximum = arr[0];
		for (int i = 1; i < n; i++) {
			arr[i] = max(arr[i], arr[i] + arr[i - 1]);
			maximum = max(arr[i], maximum);
		}
		
		cout << maximum << "\n";
	}
	return 0;
}