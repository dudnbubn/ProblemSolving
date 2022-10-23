#include <iostream>

using namespace std;

int arr[100001];
int tree[400000];

int getTree(int start, int end, int node) {
	if (start == end)	return tree[node] = arr[start];

	int mid = (start + end) / 2;
	return tree[node] = getTree(start, mid, node * 2) * getTree(mid + 1, end, node * 2 + 1);
}

int getSign(int start, int end, int node, int left, int right) {
	if (start > right || end < left)	return 1;
	if (left <= start && end <= right)	return tree[node];

	int mid = (start + end) / 2;
	
	return getSign(start, mid, node * 2, left, right) * getSign(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, int change) {
	if (start > index || index > end)	return;

	if (start == end) {
		tree[node] = change;
	}
	else {
		int mid = (start + end) / 2;
		update(start, mid, node * 2, index, change);
		update(mid + 1, end, node * 2 + 1, index, change);
		
		tree[node] = tree[node * 2] * tree[node * 2 + 1];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K;
	while (cin >> N >> K) {
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
			if (arr[i] < 0)	arr[i] = -1;
			else if (arr[i] > 0)	arr[i] = 1;
		}
		string result = "";
		char cmd;
		int a, b;
		getTree(1, N, 1);
		for (int i = 0; i < K; i++) {
			cin >> cmd >> a >> b;
			if (cmd == 'C') {
				if (b > 0)	b = 1;
				else if (b < 0)	b = -1;
				if (arr[a] != b) {
					arr[a] = b;
					update(1, N, 1, a, b);
				}
			}
			else {
				int sign = getSign(1, N, 1, a, b);
				switch (sign) {
				case -1:	result += '-';	break;
				case 0:		result += '0';	break;
				case 1:		result += '+';	break;
				}
			}
		}
		cout << result << "\n";
	}
	return 0;
}