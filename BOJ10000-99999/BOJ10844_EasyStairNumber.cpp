// ������ DP �����̴�. �ٸ� ó������ ���̸� ������Ű�鼭 dp���� ���� �� ��ⷯ�� ���� �ʰ� ������� ���� ���� �����ָ鼭 ��ⷯ�� �����.
// �׷����� Ʋ�Ȱ� dp���� ����� �� ���� ��ⷯ�� ���ִ� �¾Ҵٰ� ���Դ�.
// dp���� ���ϸ鼭 ��ⷯ�� ���ϸ� ������� ������ ���� ������? ��� �����߾��µ� ��ⷯ�� �����൵ ���� �ǰ� ���Դ�.. �� �׷���
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