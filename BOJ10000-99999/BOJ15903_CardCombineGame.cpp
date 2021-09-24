// 자료형을 잘 생각해봐야 한다. ex) n = 2, m = 30

#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> pq;

int main() {
	int n, m;
	cin >> n >> m;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		pq.push(num);
	}
	long long a, b;
	for (int i = 0; i < m; i++) {
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();
		pq.push(a + b);
		pq.push(a + b);
	}
	long long result = 0;
	for (int i = 0; i < n; i++) {
		result += pq.top();
		pq.pop();
	}
	cout << result;
	return 0;
}