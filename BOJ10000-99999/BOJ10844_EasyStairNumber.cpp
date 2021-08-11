// 무난한 DP 문제이다. 다만 처음에는 길이를 증가시키면서 dp값을 구할 때 모듈러를 하지 않고 결과값을 구할 때만 더해주면서 모듈러를 해줬다.
// 그랬더니 틀렸고 dp값을 계산할 때 마다 모듈러를 해주니 맞았다고 나왔다.
// dp값을 구하면서 모듈러를 취하면 결과값에 영향을 주지 않을까? 라고 생각했었는데 모듈러를 취해줘도 답이 옳게 나왔다.. 왜 그럴까
#include <iostream>
using namespace std;

long long dp[101][10] = { 0, };

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < 10; i++)
		dp[1][i] = 1;
	
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j != 0)	dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % 1000000000;
			if (j != 9) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % 1000000000;
		}
	}

	long long answer = 0;
	for (int i = 0; i < 10; i++)
		answer = (answer + dp[n][i]) % 1000000000;
	cout << answer;

	return 0;
}