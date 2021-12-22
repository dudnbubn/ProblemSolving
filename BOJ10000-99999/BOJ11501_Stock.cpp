#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
int arr[1000000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		while (!pq.empty())	pq.pop();
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			pq.push({ arr[i], i });
		}
		long long sum = 0, cnt = 0, sell = 0, index = -1;
		long long benefit = 0;
		for (int i = 0; i < n; i++) {
			while (index < i) {
				index = pq.top().second;
				sell = pq.top().first;
				pq.pop();
			}
			if (index == i) {
				benefit += (sell * cnt - sum);
				sum = 0;
				cnt = 0;
			}
			else {
				sum += arr[i];
				cnt++;
			}
		}
		cout << benefit << "\n";
	}
	return 0;
}