// min �켱���� ť�� ���� �����ϸ鼭 ť�� ũ�Ⱑ n�� ������ pop�� �ؼ� ���� ���� ���� ������.
// ��� �Է¿� ���� �� ������ ��ġ�� ť���� n���� ���� �ְ� ť�� top�� n�� �� ���� ���� ���̹Ƿ�
// �Է°� �� n��°�� ū ���� �ȴ�.

#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int input;
	for (int i = 0; i < n * n; i++) {
		cin >> input;
		pq.push(input);
		if (pq.size() > n)
			pq.pop();
	}
	cout << pq.top();

	return 0;
}