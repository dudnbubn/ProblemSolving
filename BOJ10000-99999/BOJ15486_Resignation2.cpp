// key point : dp 
// dp[i] : i �� ���� ������� �� ���� �� �ִ� �ִ� �ݾ�

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
		// i �Ͽ� ����� ���� �ʴ� ��� i + 1 �Ϻ��� ������� �� ���� �� �ִ� �ִ� �ݾװ� ����
		dp[i] = dp[i + 1];

		// i �Ͽ� ����� �����Ͽ� ��� ���� ��ĥ �� �ִ� ���
		if (i + t[i] <= n + 1) {
			// i �Ͽ� ����� �������� ���� ���� �ִ񰪰� (dp[i] (= dp[i + 1]))
			// i �Ͽ� ����� �����Ͽ� ���� ��� �ݾ� + (i + t[i]) �Ϻ��� ������� �� ���� �� �ִ� �ִ� �ݾ� �� (p[i] + dp[i + t[i]])
			dp[i] = max(dp[i], p[i] + dp[i + t[i]]);
		}
	}
	cout << dp[1];
	return 0;
}