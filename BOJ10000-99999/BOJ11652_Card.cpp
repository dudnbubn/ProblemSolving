// üũ�ؾ� �� ������ ������ �ʹ� Ŀ�� �迭�� ������ ������ �� ����.
// �׷��� map �� �̿��ߴ��� �ٷ� �ذ�Ǿ���.
#include <iostream>
#include <map>
using namespace std;

int n;
map<long long, int> m;
map<long long, int>::iterator iter;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		if (m.find(x) == m.end()) {
			m[x] = 1;
		}
		else
			m[x]++;
	}
	int maximum = 0;
	long long answer = 0;
	for (iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second > maximum) {
			maximum = iter->second;
			answer = iter->first;
		}
	}
	cout << answer;
	return 0;
}