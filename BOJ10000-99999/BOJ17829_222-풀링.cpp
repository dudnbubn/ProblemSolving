#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 1024

int board[MAX_N][MAX_N];

int recur(int length, int lui, int luj) {
	vector<int> v;
	if (length == 2) {
		v.push_back(board[lui][luj]);
		v.push_back(board[lui][luj + 1]);
		v.push_back(board[lui + 1][luj]);
		v.push_back(board[lui + 1][luj + 1]);
	}
	else {
		v.push_back(recur(length / 2, lui, luj));
		v.push_back(recur(length / 2, lui + length / 2, luj));
		v.push_back(recur(length / 2, lui, luj + length / 2));
		v.push_back(recur(length / 2, lui + length / 2, luj + length / 2));
	}
	
	sort(v.begin(), v.end());
	return v[2];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	cout << recur(N, 0, 0);
	return 0;
}