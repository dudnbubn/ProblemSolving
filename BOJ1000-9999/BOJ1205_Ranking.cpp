// 동점이 있을 경우 다음 점수의 순위를 매기는 것을 잘 계산해야한다.

#include <iostream>
#include <algorithm>
using namespace std;

int n, score, p;

int main() {
	cin >> n >> score >> p;
	int rank[51] = { 0, };

	for (int i = 0; i < n; i++) {
		cin >> rank[i];
	}
	
	if ((n == p) && (score <= rank[n - 1])) {
		cout << -1;
	}
	else {
		int r = 1, eq = 1;
		for (int i = 0; i < p; i++) {
			if (i > 0) {
				if (rank[i] == rank[i - 1])
					eq++;
				else if (rank[i] < rank[i - 1]) {
					r += eq;
					eq = 1;
				}
			}
			if (score >= rank[i]) {
				cout << r;
				return 0;
			}
		}
	}
	return 0;
}