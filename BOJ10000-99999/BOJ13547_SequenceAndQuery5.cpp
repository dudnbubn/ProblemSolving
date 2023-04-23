#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAX_N 100'000
#define MAX_M 100'000
#define MAX_VALUE 1'000'000

int sqrt_N;
int arr[MAX_N + 1];
int duplicates[MAX_VALUE + 1];

typedef pair<pair<int, int>, int> piii;
piii queries[MAX_M];

int results[MAX_M];

bool order_by_sqrt_N(piii a, piii b) {
	if (a.first.first / sqrt_N == b.first.first / sqrt_N)
		return a.first.second < b.first.second;

	return a.first.first / sqrt_N < b.first.first / sqrt_N;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	sqrt_N = sqrt(N);

	for (int i = 1; i <= N; i++)	cin >> arr[i];

	int M;
	cin >> M;

	int start, end, index;
	for (int i = 0; i < M; i++) {
		cin >> start >> end;
		queries[i] = { {start, end}, i };
	}

	sort(queries, queries + M, order_by_sqrt_N);
	
	start = queries[0].first.first;
	end = queries[0].first.second;
	index = queries[0].second;

	int number_count = 0;
	for (int i = start; i <= end; i++) {
		if (duplicates[arr[i]]++ == 0)	number_count++;
	}
	results[index] = number_count;

	int next_start, next_end;
	for (int i = 1; i < M; i++) {
		next_start = queries[i].first.first;
		next_end = queries[i].first.second;
		index = queries[i].second;

		while (start < next_start) {
			if (--duplicates[arr[start]] == 0)	number_count--;
			start++;
		}

		while (start > next_start) {
			start--;
			if (duplicates[arr[start]]++ == 0)	number_count++;
		}

		while (end < next_end) {
			end++;
			if (duplicates[arr[end]]++ == 0)	number_count++;
		}

		while (end > next_end) {
			if (--duplicates[arr[end]] == 0)	number_count--;
			end--;
		}

		results[index] = number_count;
	}

	for (int i = 0; i < M; i++)
		cout << results[i] << "\n";
	
	return 0;
}