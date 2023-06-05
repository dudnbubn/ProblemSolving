#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

#define MAX_N 300'000
#define MAX_M 10'000
#define MAX_C 10'000

int sqrt_N;
int arr[MAX_N + 1];
int color_counts[MAX_C + 1];
int tree[MAX_C * 4];
int results[MAX_M];

typedef pair<pair<int, int>, int> Query;
Query queries[MAX_M];

priority_queue<pair<int, int>, vector<pair<int, int>>> pq;

bool order_by_sqrt(Query a, Query b) {
	if (a.first.first / sqrt_N == b.first.first / sqrt_N)
		return a.first.second < b.first.second;
	return a.first.first / sqrt_N < b.first.first / sqrt_N;
}

bool order_by_index(Query a, Query b) {
	return a.second < b.second;
}

void set_tree(int start, int end, int node) {
	if (start == end) {
		tree[node] = start;
		return;
	}

	int mid = (start + end) / 2;
	set_tree(start, mid, node * 2);
	set_tree(mid + 1, end, node * 2 + 1);

	int left = tree[node * 2];
	int right = tree[node * 2 + 1];
	tree[node] = color_counts[left] > color_counts[right] ? left : right;
}

void update(int start, int end, int node, int index) {
	if (start > index || end < index)	return;
	if (start == end)	return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index);
	update(mid + 1, end, node * 2 + 1, index);
	
	int left = tree[node * 2];
	int right = tree[node * 2 + 1];
	
	tree[node] = color_counts[left] > color_counts[right] ? left : right;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, C;
	cin >> N >> C;
	sqrt_N = sqrt(N);
	for (int n = 1; n <= N; n++)	cin >> arr[n];

	int M;
	cin >> M;
	int start, end;
	for (int m = 0; m < M; m++) {
		cin >> start >> end;
		queries[m] = { {start, end}, m };
	}

	sort(queries, queries + M, order_by_sqrt);

	start = queries[0].first.first;
	end = queries[0].first.second;
	int color;
	for (int i = start; i <= end; i++) {
		color = arr[i];
		++color_counts[color];
	}
	set_tree(1, MAX_C, 1);
	int K = queries[0].first.second - queries[0].first.first + 1;
	results[queries[0].second] = color_counts[tree[1]] > K / 2 ? tree[1] : 0;
	
	for (int m = 1; m < M; m++) {
		
		while (start < queries[m].first.first) {
			--color_counts[arr[start]];
			start++;
		}

		while (start > queries[m].first.first) {
			start--;
			++color_counts[arr[start]];
		}

		while (end < queries[m].first.second) {
			end++;
			++color_counts[arr[end]];
		}

		while (end > queries[m].first.second) {
			--color_counts[arr[end]];
			end--;
		}

		set_tree(1, MAX_C, 1);
		K = queries[m].first.second - queries[m].first.first + 1;
		results[queries[m].second] = color_counts[tree[1]] > K / 2 ? tree[1] : 0;
	}

	for (int m = 0; m < M; m++) {
		if (results[m])	cout << "yes " << results[m] << "\n";
		else	cout << "no\n";
	}
}