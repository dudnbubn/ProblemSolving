#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

pair<int, int> input[200000];

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> input[i].first >> input[i].second;
	sort(input, input + n, compare);

	for (int i = 0; i < n; i++) {
		if (pq.empty())	pq.push(input[i].second);
		else {
			if (pq.top() <= input[i].first) 
				pq.pop();
			pq.push(input[i].second);
		}
	}
	cout << pq.size();
	return 0;
}