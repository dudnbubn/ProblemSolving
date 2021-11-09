#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[100];
vector<int> result;

int Euclid(int a, int b) {
	int temp = min(a, b);
	a = max(a, b);
	b = temp;
	int n = a % b;
	while (n != 0) {
		a = b;
		b = n;
		n = a % b;
	}
	return b;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	sort(arr, arr + n);
	for (int i = n - 1; i >= 1; i--)	arr[i] -= arr[i - 1];
	int gcd = arr[1];
	for (int i = 2; i < n; i++)	gcd = Euclid(gcd, arr[i]);
	
	for (int i = 1; i * i <= gcd; i++) {
		if (gcd % i == 0)
			result.push_back(i);
	}
	int sz = result.size();
	for (int i = sz - 1; i >= 0; i--) {
		if (gcd / result[i] == result[i])	continue;

		result.push_back(gcd/result[i]);
	}
	for (int i = 1; i < result.size(); i++)
		cout << result[i] << " ";

	return 0;
}