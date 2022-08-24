#include <iostream>

using namespace std;

int in_index[100001];
int post_order[100001];

void pre_order(int is, int ie, int ps, int pe) {	// inindex start, inindex end, postindex start, postindex end
	int root = post_order[pe];
	cout << root << " ";

	int root_index = in_index[root];
	int left_count = root_index - is;
	int right_count = ie - root_index;

	if (left_count > 0)		pre_order(is, root_index - 1, ps, ps + left_count - 1);
	if (right_count > 0)	pre_order(root_index + 1, ie, pe - right_count, pe - 1);
}
int main() {
	int N;
	cin >> N;

	int in_order;
	for (int i = 1; i <= N; i++) {
		cin >> in_order;
		in_index[in_order] = i;
	}
	for (int i = 1; i <= N; i++)
		cin >> post_order[i];

	pre_order(1, N, 1, N);

	return 0;
}