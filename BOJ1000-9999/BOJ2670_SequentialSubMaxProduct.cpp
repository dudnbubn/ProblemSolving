// 결과값의 소숫점 아래가 3자리 미만이더라도 소숫점 이하 셋째 자리까지 출력해주어야한다.. ex)32 -> 32.000

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
double arr[10000];
double dp[10000];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	double maximum = arr[0];
	dp[0] = arr[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(arr[i], dp[i - 1] * arr[i]);
		maximum = max(maximum, dp[i]);
	}
	
	maximum = round(maximum * 1000) / 1000;
	cout.precision(3);
	cout << fixed << maximum;
	return 0;
}