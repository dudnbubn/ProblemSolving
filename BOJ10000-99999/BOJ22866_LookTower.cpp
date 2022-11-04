#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int N;
int arr[100001];
int left_cnt[100001];
int left_index[100001];
int right_cnt[100001];
int right_index[100001];

stack<pair<int, int>> stk;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> arr[i];

	for (int i = 1; i <= N; i++) {
		while (!stk.empty() && stk.top().first <= arr[i])
			stk.pop();

		left_cnt[i] = stk.size();
		if (!stk.empty())	left_index[i] = stk.top().second;
		stk.push({ arr[i], i });
	}
	
	stk = {};
	for (int i = N; i >= 1; i--) {
		while (!stk.empty() && stk.top().first <= arr[i])
			stk.pop();

		right_cnt[i] = stk.size();
		if (!stk.empty())	right_index[i] = stk.top().second;
		stk.push({ arr[i], i });
	}

	int l, r;
	for (int i = 1; i <= N; i++) {
		l = r = -1;
		if (left_cnt[i] > 0)	l = left_index[i];
		if (right_cnt[i] > 0)	r = right_index[i];

		if (l == -1 && r == -1)	cout << "0\n";
		else if (l == -1)	cout << right_cnt[i] << " " << right_index[i] << "\n";
		else if (r == -1)	cout << left_cnt[i] << " " << left_index[i] << "\n";
		else {
			int near_l = i - left_index[i];
			int near_r = right_index[i] - i;
			
			int nearest = near_l <= near_r ? left_index[i] : right_index[i];
			cout << left_cnt[i] + right_cnt[i] << " " << nearest << "\n";
		}
	}
	return 0;
}
