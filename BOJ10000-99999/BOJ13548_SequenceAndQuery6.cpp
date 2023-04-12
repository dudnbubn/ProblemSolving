#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define MAX_N 100'000
#define MAX_M 100'000

int N, M;
int arr[MAX_N + 1];
int maximum;
int counts[MAX_N + 1];
int equal_counts[MAX_N + 1];
int results[MAX_M];

int sqrtN;

struct Query {
	int index, first, second;
	bool operator < (Query& x) {
		if (first / sqrtN != x.first / sqrtN)	return first/sqrtN < x.first / sqrtN;
		return second < x.second;
	}
};

vector<Query> queries;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	sqrtN = sqrt(N);
	for (int i = 1; i <= N; i++)	cin >> arr[i];

	cin >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		queries.push_back({ i, a, b });
	}
	sort(queries.begin(), queries.end());

	int start, end;
	int index = queries[0].index;
	a = queries[0].first;
	b = queries[0].second;
	for (int i = a; i <= b; i++) {
		equal_counts[counts[arr[i]]]--;
		counts[arr[i]]++;
		if (maximum < counts[arr[i]])
			maximum = counts[arr[i]];
		equal_counts[counts[arr[i]]]++;
	}
	results[index] = maximum;

	start = a;
	end = b;

	for (int i = 1; i < M; i++) {
		index = queries[i].index;
		a = queries[i].first;
		b = queries[i].second;

		while (start < a) {
			equal_counts[counts[arr[start]]]--;
			if (counts[arr[start]] == maximum && equal_counts[counts[arr[start]]] == 0) {
				maximum--;
			}
			counts[arr[start]]--;
			equal_counts[counts[arr[start]]]++;
			start++;
		}

		while (end > b) {
			equal_counts[counts[arr[end]]]--;
			if (counts[arr[end]] == maximum && equal_counts[counts[arr[end]]] == 0) {
				maximum--;
			}
			counts[arr[end]]--;
			equal_counts[counts[arr[end]]]++;
			end--;
		}

		while (start > a) {
			start--;
			equal_counts[counts[arr[start]]]--;
			counts[arr[start]]++;
			if (maximum < counts[arr[start]]) {
				maximum = counts[arr[start]];
			}
			equal_counts[counts[arr[start]]]++;
		}

		while (end < b) {
			end++;
			equal_counts[counts[arr[end]]]--;
			counts[arr[end]]++;
			if (maximum < counts[arr[end]]) {
				maximum = counts[arr[end]];
			}
			equal_counts[counts[arr[end]]]++;
		}
		results[index] = maximum;
	}

	for (int i = 0; i < M; i++)
		cout << results[i] << "\n";
	return 0;
}