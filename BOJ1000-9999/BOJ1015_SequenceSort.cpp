#include <iostream>
using namespace std;

int n;
int A[1001];
int cnt[1001] = { 0, };
int index[1001] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		cnt[A[i]]++;
	}
	int prev = 0;
	for (int i = 1; i <= 1000; i++) {
		if (cnt[i] != 0) {
			index[i] = prev;
			prev += cnt[i];
		}
	}
	for (int i = 0; i < n; i++) {
		cout << index[A[i]] << " ";
		index[A[i]]++;
	}
	return 0;
}