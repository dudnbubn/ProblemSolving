// min 우선순위 큐에 수를 저장하면서 큐의 크기가 n을 넘으면 pop을 해서 가장 작은 수를 빼낸다.
// 모든 입력에 대해 위 과정을 거치면 큐에는 n개의 수가 있고 큐의 top은 n개 중 가장 작은 수이므로
// 입력값 중 n번째로 큰 수가 된다.

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