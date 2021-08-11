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