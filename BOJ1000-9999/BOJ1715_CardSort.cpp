// key point : 가장 적은 수의 카드 묶음끼리 계속 더해줄 때가 최소 비교

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