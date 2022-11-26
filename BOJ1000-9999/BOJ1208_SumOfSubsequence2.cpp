#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int N, S, A, B;
int arr_a[20], arr_b[20];
unordered_map<int, int> ma, mb;

void subsA(int depth, int sum, int bit) {
	if (depth == A) {
		if (bit == 0)	return;
		if (ma.find(sum) == ma.end())	ma[sum] = 1;
		else ma[sum]++;
		return;
	}
	subsA(depth + 1, sum, bit);
	subsA(depth + 1, sum + arr_a[depth], (bit | (1 << depth)));
}

void subsB(int depth, int sum, int bit) {
	if (depth == B) {
		if (bit == 0)	return;
		if (mb.find(sum) == mb.end())	mb[sum] = 1;
		else mb[sum]++;
		return;
	}
	subsB(depth + 1, sum, bit);
	subsB(depth + 1, sum + arr_b[depth], (bit | (1 << depth)));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> S;
;
	A = N / 2;
	B = N - A;
	for (int i = 0; i < A; i++) 
		cin >> arr_a[i];
	for (int i = 0; i < B; i++) 
		cin >> arr_b[i];

	subsA(0, 0, 0);
	subsB(0, 0, 0);
	vector<pair<int, int>> va, vb;
	for (pair<int, int> item : ma) 
		va.push_back(item);
	for (pair<int, int> item : mb)
		vb.push_back(item);

	long long result = 0;
	for (pair<int, int> a : va) {
		if (mb.find(S - a.first) != mb.end())
			result += (long long)a.second * mb[S - a.first];
		if (a.first == S)
			result += a.second;
	}
	for (pair<int, int> b : vb) {
		if (b.first == S)
			result += b.second;
	}
	
	cout << result;
	return 0;
}