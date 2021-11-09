// DP
// i 자리의 맨 왼쪽 숫자가 j인 값은 i - 1 자리의 맨 왼쪽 숫자가 j 이상인 값을 모두 더한 값이 된다.
// 64자리까지 구하려면 int 값을 초과하므로 long long에 저장하도록 한다.

#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];
int maximum = 0;
long long dp[65][10];

void Dynamic(int n) {
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				dp[i][j] += dp[i - 1][k];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		cin >> arr[i];
		maximum = max(maximum, arr[i]);
	}

	for (int i = 0; i < 10; i++)	dp[1][i] = 1;
	Dynamic(maximum);

	for (int i = 0; i < testcase; i++) {
		long long result = 0;
		for (int j = 0; j < 10; j++)	result += dp[arr[i]][j];
		cout << result << "\n";
	}
	return 0;
}