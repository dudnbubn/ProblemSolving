#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

long long root[1001];
pair<long long, long long> arr[1001];

typedef pair<double, pair<long long, long long>> info;
priority_queue<info, vector<info>, greater<info>> pq;

long long Find(long long x) {
	if (x == root[x])	return x;
	return root[x] = Find(root[x]);
}

void Union(long long x, long long y) {
	x = Find(x);
	y = Find(y);

	root[y] = x;
}

double distance(pair<long long, long long> a, pair<long long, long long> b) {
	long long dx = a.first - b.first;
	long long dy = a.second - b.second;
	long long result = dx * dx + dy * dy;
	return sqrt(result);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> arr[i].first >> arr[i].second;
		root[i] = i;
	}
	long long x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		Union(x, y);
	}
	
	for (long long i = 1; i <= n; i++) {
		for (long long j = i + 1; j <= n; j++) {
			if (Find(i) != Find(j)) {
				pq.push({ distance(arr[i],arr[j]), {i, j} });
			}
		}
	}

	info cur;
	double result = 0;

	while (!pq.empty()) {
		cur = pq.top();
		pq.pop();
		if (Find(cur.second.first) != Find(cur.second.second)) {
			result += cur.first;
			Union(cur.second.first, cur.second.second);
		}
	}
	
	std::cout.precision(2);
	std::cout << fixed << result;
	return 0;
}