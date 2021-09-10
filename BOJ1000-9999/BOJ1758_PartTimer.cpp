// n과 tip의 범위를 잘 생각해보도록 하자

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[100000];

bool compare(int a, int b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	sort(arr, arr + n, compare);
	long long tot = 0, tip;
	for (int i = 0; i < n; i++) {
		tip = max(0, arr[i] - i);
		tot += tip;
	}
	cout << tot;
	return 0;
}