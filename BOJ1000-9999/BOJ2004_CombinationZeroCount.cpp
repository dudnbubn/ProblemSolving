// n!, m!, k!(k = n - m) 에 2와 5가 몇 개 들어있는지 개수를 구하고 n!에서 구한 개수에서 m!, k!에서 구한 개수를 빼준다.
// 그리고 10 이 있어야 맨 뒤 수가 0 이기 때문에 남은 2와 5의 개수 중 작은 값을 출력한다.
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int k = n - m;
	int n_cnt2 = 0, n_cnt5 = 0;
	int m_cnt2 = 0, m_cnt5 = 0;
	int k_cnt2 = 0, k_cnt5 = 0;
	int mul2 = 2, mul5 = 5;
	while (mul2 <= n) {
		n_cnt2 += (n / mul2);
		m_cnt2 += (m / mul2);
		k_cnt2 += (k / mul2);
		mul2 *= 2;
	}
	while (mul5 <= n) {
		n_cnt5 += (n / mul5);
		m_cnt5 += (m / mul5);
		k_cnt5 += (k / mul5);
		mul5 *= 5;
	}
	cout << min(n_cnt2 - m_cnt2 - k_cnt2, n_cnt5 - m_cnt5 - k_cnt5);
	return 0;
}