// key point : dp 
// dp[i] : i 일 부터 상담했을 때 받을 수 있는 최대 금액

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int t[1500002] = { 0, };
int p[1500002] = { 0, };
int dp[1500002] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> t[i] >> p[i];
	for (int i = n; i >= 1; i--) {
		// i 일에 상담을 하지 않는 경우 i + 1 일부터 상담했을 때 받을 수 있는 최대 금액과 같음
		dp[i] = dp[i + 1];

		// i 일에 상담을 진행하여 퇴사 전에 마칠 수 있는 경우
		if (i + t[i] <= n + 1) {
			// i 일에 상담을 진행하지 않을 때의 최댓값과 (dp[i] (= dp[i + 1]))
			// i 일에 상담을 진행하여 받은 상담 금액 + (i + t[i]) 일부터 상담했을 때 받을 수 있는 최대 금액 비교 (p[i] + dp[i + t[i]])
			dp[i] = max(dp[i], p[i] + dp[i + t[i]]);
		}
	}
	cout << dp[1];
	return 0;
}