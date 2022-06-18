#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<int, vector<int>> pq;

int main() {
	cin >> N;

	int one, other;
	cin >> one;
	for (int i = 1; i < N; i++) {
		cin >> other;
		pq.push(other);
	}

	int result = 0;
	while (!pq.empty() && one <= pq.top()) {
		result++;
		one++;
		pq.push(pq.top() - 1);
		pq.pop();
	}
	cout << result;
	
	return 0;
}