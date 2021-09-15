#include <iostream>
#include <algorithm>
using namespace std;

int A[20001];
int B[20001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase, n, m, index, cnt;
	cin >> testcase;
	while (testcase--) {
		cin >> n >> m;
		index = 0;
		cnt = 0;
		for (int i = 0; i < n; i++)	cin >> A[i];
		for (int i = 0; i < m; i++)	cin >> B[i];
		sort(A, A + n);
		sort(B, B + m);
		for (int i = 0; i < n; i++) {
			for (int j = index; j < m; j++) {
				if (A[i] > B[j])	index++;
				else {
					cnt += index;
					break;
				}
			}
			if (index == m) {
				cnt += (index * (n - i));
				break;
			}
		}
		cout << cnt << "\n";
	}
}