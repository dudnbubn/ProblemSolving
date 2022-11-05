#include <iostream>

using namespace std;

int pre_order[1001];
int in_order[1001];
int in_index[1001];

void recur(int in_start, int in_end, int pre_index) {
	int root = pre_order[pre_index];
	int root_in_index = in_index[root];
	
	int left_index = pre_index + 1;
	int right_index = pre_index + 1 + (root_in_index - in_start);

	if(in_start < root_in_index)	recur(in_start, root_in_index - 1, left_index);
	if(root_in_index < in_end)	recur(root_in_index + 1, in_end, right_index);

	cout << root << " ";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		int N;
		cin >> N;
		for (int i = 1; i <= N; i++)	cin >> pre_order[i];
		for (int i = 1; i <= N; i++) {
			cin >> in_order[i];
			in_index[in_order[i]] = i;
		}

		recur(1, N, 1);
		cout << "\n";
	}
	return 0;
}