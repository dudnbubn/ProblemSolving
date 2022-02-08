#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	int start = 1, end = m, x;
	int move = 0;
	for (int i = 0; i < k; i++) {
		cin >> x;
		if (start <= x && x <= end)	continue;
		
		if (x < start) {
			move += (start - x);
			end -= (start - x);
			start -= (start - x);
		}
		else {
			move += (x - end);
			start += (x - end);
			end += (x - end);
		}
	}
	cout << move;
	return 0;
}