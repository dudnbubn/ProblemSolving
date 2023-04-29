#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAX_N 100'000
#define MAX_T 100'000
#define MAX_VALUE 1'000'000

int sqrt_N;
int arr[MAX_N + 1];

typedef pair<pair<int, int>, int> piii;
piii queries[MAX_T];
long long result;
long long results[MAX_T];
long long counts[MAX_VALUE + 1];

bool compare(piii a, piii b) {
	if (a.first.first / sqrt_N == b.first.first / sqrt_N)
		return a.first.second < b.first.second;
	return a.first.first / sqrt_N < b.first.first / sqrt_N;
}

void add(int index) {
	result -= counts[arr[index]] * counts[arr[index]] * (long long)arr[index];
	counts[arr[index]]++;
	result += counts[arr[index]] * counts[arr[index]] * (long long)arr[index];
}

void sub(int index) {
	result -= counts[arr[index]] * counts[arr[index]] * (long long)arr[index];
	counts[arr[index]]--;
	result += counts[arr[index]] * counts[arr[index]] * (long long)arr[index];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, T;
	cin >> N >> T;
	sqrt_N = sqrt(N);
	for (int i = 1; i <= N; i++)	cin >> arr[i];

	int a, b;
	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		queries[i] = { {a, b}, i };
	}
	sort(queries, queries + T, compare);

	int start, end, index;
	start = queries[0].first.first;
	end = queries[0].first.second;
	index = queries[0].second;
	for (int i = start; i <= end; i++) {
		add(i);
	}
	results[index] = result;

	piii query;
	for (int i = 1; i < T; i++) {
		query = queries[i];

		while (start < query.first.first)	sub(start++);
		while (start > query.first.first)	add(--start);

		while (end < query.first.second)	add(++end);
		while (end > query.first.second)	sub(end--);

		results[query.second] = result;
	}

	for (int i = 0; i < T; i++)
		cout << results[i] << "\n";
	return 0;
}