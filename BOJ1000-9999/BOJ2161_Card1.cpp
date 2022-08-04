#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	queue<int> q;
	for (int i = 1; i <= N; i++)
		q.push(i);

	while (q.size() > 1) {
		cout << q.front() << " "; 
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.front();
	return 0;
}