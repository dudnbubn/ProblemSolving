#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
long long arr[100001];
long long tree[400001];

vector<pair<int, int>> queries1;
vector<pair<int, int>> queries2[100001];
queue<long long> results[100001];
vector<int> cmds;

long long getTree(int start, int end, int node) {
	if (start == end)	return tree[node] = arr[start];

	int mid = (start + end) / 2;
	return tree[node] = getTree(start, mid, node * 2) + getTree(mid + 1, end, node * 2 + 1);
}

long long getSum(int start, int end, int node, int left, int right) {
	if (start > right || end < left)	return 0;
	if (left <= start && end <= right)	return tree[node];

	int mid = (start + end) / 2;
	return getSum(start, mid, node * 2, left, right) + getSum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, long long dif) {
	if (index < start || index > end)	return;

	tree[node] += dif;
	if (start == end)	return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, dif);
	update(mid + 1, end, node * 2 + 1, index, dif);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> arr[i];

	cin >> M;
	int cmd, index, from, to;
	for (int i = 0; i < M; i++) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> from >> to;
			queries1.push_back({ from, to });
		}
		else {
			cin >> index >> from >> to;
			queries2[index].push_back({ from, to });
			cmds.push_back(index);
		}
	}

	getTree(1, N, 1);

	index = 0;
	for (pair<int, int> query : queries2[0]) {
		from = query.first;
		to = query.second;
		results[index].push(getSum(1, N, 1, from, to));
	}

	long prev;
	for (pair<int, int> query1 : queries1) {
		index++;
		
		from = query1.first;
		to = query1.second;
		prev = arr[from];
		arr[from] = to;
		update(1, N, 1, from, to - prev);

		for (pair<int, int> query2 : queries2[index]) {
			from = query2.first;
			to = query2.second;
			results[index].push(getSum(1, N, 1, from, to));
		}
	}

	for (int c : cmds) {
		cout << results[c].front() << "\n";
		results[c].pop();
	}

	return 0;
}