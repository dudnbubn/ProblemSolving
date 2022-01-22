// key point : ���� ���� ���� ī�� �������� ��� ������ ���� �ּ� ��

#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> min_pq;

int main() {
	int n;
	cin >> n;

	int card;
	for (int i = 0; i < n; i++) {
		cin >> card;
		min_pq.push(card);
	}

	int result = 0;
	int a, b;
	while (min_pq.size() > 1) {
		a = min_pq.top();
		min_pq.pop();
		b = min_pq.top();
		min_pq.pop();
		result += (a + b);
		min_pq.push(a + b);
	}
	cout << result;
	return 0;
}