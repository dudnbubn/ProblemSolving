#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_M 500'000

bool is_contained[MAX_M + 1];

typedef pair<pair<long long, long long>, int> plli;

vector<plli> v;
bool compare(plli a, plli b) {
	if (a.first.first == b.first.first)
		return a.first.second > b.first.second;
	return a.first.first < b.first.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	
	long long a, b;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		b = a < b ? b : b + N;
		v.push_back({ {a, b}, i });
		v.push_back({ {a + N, b + N}, i });
	}

	sort(v.begin(), v.end(), compare);

	long long start, end = -1;
	for (plli bus : v) {
		if (bus.first.second > end) {
			start = bus.first.first;
			end = bus.first.second;
		}
		else {
			if (start <= bus.first.first && bus.first.second <= end)
				is_contained[bus.second] = true;
		}
	}

	for (int i = 1; i <= M; i++) {
		if (is_contained[i])	continue;
		cout << i << " ";
	}
	return 0;
}