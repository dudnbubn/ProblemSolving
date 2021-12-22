#include <iostream>
#include <algorithm>
using namespace std;

int height[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int l, h, max_l = 0, max_h = 0;
	for (int i = 0; i < n; i++) {
		cin >> l >> h;
		height[l] = h;
		max_l = max(max_l, l);
		max_h = max(max_h, h);
	}
	int area = 0;
	int left, right;
	for (int i = 1; i <= max_h; i++) {
		left = -1;	right = -1;
		for (int j = 0; j <= max_l; j++) {
			if (height[j] >= i) {
				if (left == -1)	left = j;
				right = j;
			}
		}
		area += (right - left + 1);
	}
	cout << area;
	return 0;
}