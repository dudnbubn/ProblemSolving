#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, D;
pair<int, int> segments[100000];		// { Å« ÁÂÇ¥, ÀÛÀº ÁÂÇ¥ }
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	int h, o;
	for (int i = 0; i < N; i++) {
		cin >> h >> o;
		segments[i].first = h > o ? h : o;
		segments[i].second = h < o ? h : o;
	}
	cin >> D;

	sort(segments, segments + N);
	
	int result = 0;
	int right, left, left_end, sz;

	for (int i = 0; i < N; i++) {
		right = segments[i].first;
		left = segments[i].second;
		
		pq.push(left);
		left_end = right - D;
		while (!pq.empty() && pq.top() < left_end) {
			pq.pop();
		}
		
		sz = pq.size();
		result = result > sz ? result: sz;
	}
	cout << result;
	
	return 0;
}