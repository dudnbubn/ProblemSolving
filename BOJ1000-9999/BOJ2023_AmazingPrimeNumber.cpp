#include <iostream>
#include <queue>
using namespace std;

int n;
queue<long long> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	long long end = 1;
	for (int i = 0; i < n; i++)	end *= 10;
	long long start = end / 10;
	
	q.push(2);
	q.push(3);
	q.push(5);
	q.push(7);
	while (!q.empty()) {
		long long cur = q.front();
		if (start < cur && cur < end)	break;
		q.pop();
		long long next;
		bool flag;
		for (int i = 1; i < 10; i += 2) {
			flag = true;
			next = cur * 10 + i;
			for (int j = 2; j * j <= next; j++) {
				if (next % j == 0) {
					flag = false;
					break;
				}
			}
			if (flag)	q.push(next);
		}
	}

	while (!q.empty()) {
		long long cur = q.front();
		q.pop();
		if (start < cur && cur < end)
			cout << cur << "\n";
		else
			break;
	}
	return 0;
}