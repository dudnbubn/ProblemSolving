// ù �õ����� line 12 ó�� k �� ��ȣ�� ������� �ʰ� �׳� team ���� ������.
// �׷��� line 16���� team ���� ������ ���� ������ �ϰ� �Ǿ� �̻��� ���� ������ �ȴ�. ex) input : 100 0 0
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