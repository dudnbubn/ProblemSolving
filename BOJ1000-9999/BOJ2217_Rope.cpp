#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int maximum = 0;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)	maximum = max(maximum, arr[i] * (n - i));

	cout << maximum;
	return 0;
}