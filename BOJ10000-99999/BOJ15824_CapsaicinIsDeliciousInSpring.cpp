#include <iostream>
#include <algorithm>

using namespace std;

#define MOD 1'000'000'007

int arr[300001];
int subsum[300001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> arr[i];
	sort(arr + 1, arr + N + 1);
	for (int i = 1; i <= N; i++)	subsum[i] = subsum[i - 1] + arr[i];
	
	long long dif = 0, mul = 0;
	long long result = 0;
	for (int i = 2, expo = 1; i <= N; i++, expo = (expo * 2) % MOD) {
		mul = (mul + expo) % MOD;
		dif = (dif * 2 + arr[i - 1]) % MOD;
		result = (result + (arr[i] * mul - dif) % MOD) % MOD;
	}
	cout << result;

	return 0;
}