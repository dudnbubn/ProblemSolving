// 첫 시도에서 line 12 처럼 k 의 부호를 고려하지 않고 그냥 team 에서 뺐었다.
// 그러면 line 16에서 team 에서 음수를 빼는 연산을 하게 되어 이상한 답이 나오게 된다. ex) input : 100 0 0
#include <iostream>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int team = (n >= 2 * m) ? m : n / 2;
	n -= 2 * team;
	m -= team;
	k -= (n + m);
	if (k < 0)
		cout << team;
	else {
		team -= (k + 2) / 3;
		cout << team;
	}
	return 0;
}