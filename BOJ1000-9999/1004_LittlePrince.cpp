#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;
	int x1, y1, x2, y2, cx, cy, r, n;
	cin >> testcase;
	while (testcase--) {
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;
		bool flag1, flag2;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cin >> cx >> cy >> r;
			flag1 = false;	flag2 = false;
			if (r * r < (((cx - x1) * (cx - x1)) + ((cy - y1) * (cy - y1))))
				flag1 = true;
			if (r * r < (((cx - x2) * (cx - x2)) + ((cy - y2) * (cy - y2))))
				flag2 = true;

			if (flag1 != flag2)	cnt++;
		}
		cout << cnt << "\n";
	}
	return 0;
}