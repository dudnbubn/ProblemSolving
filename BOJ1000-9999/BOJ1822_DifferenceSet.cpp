// algorithm �� include �Ͽ� �� �� �ִ� set_difference �Լ��� ���
// 5��° ���ڷ� inserter��� �Լ���� ���� ����Ѵ�. �ش� �����̳��� insert �Լ��� ȣ���Ѵٰ� �Ѵ�.
// inserter�Լ� ��ſ� vector�� begin iterator�� �ְ� (���Ƿ� v.begin() �������) ������� vector iterator��(���Ƿ� ls) �����ϴ� ����� �ִ�.
// �׷��� �� �� �� �ٸ� vector iterator iter�� v.begin() ���� iter < ls ���� iter++ �ϸ鼭 ���� ���ϸ�  ������ ���� ���´�. �������� ������� ls - v.begin() �̴�.

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

set<int> a, b, result;
set<int>::iterator iter;
int n, m, num;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num;
		a.insert(num);
	}
	for (int i = 0; i < m; i++) {
		cin >> num;
		b.insert(num);
	}
	set_difference(a.begin(), a.end(), b.begin(), b.end(),
		inserter(result, result.end()));
	cout << result.size() << "\n";
	for (iter = result.begin(); iter != result.end(); iter++)
		cout << *iter << " ";
	return 0;
}