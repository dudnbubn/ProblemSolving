#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int w, h, cut, dir, num;
	vector<int> hori, vert;

	cin >> w >> h;
	cin >> cut;
	for (int i = 0; i < cut; i++) {
		cin >> dir >> num;
		if (dir == 0)	hori.push_back(num);
		else	vert.push_back(num);
	}
	sort(hori.begin(), hori.end());
	sort(vert.begin(), vert.end());
	hori.push_back(h);
	vert.push_back(w);
	int max_w = 0, max_h = 0;
	for (int i = hori.size() - 1; i >= 0; i--) {
		if (i != 0)	hori[i] -= hori[i - 1];
		max_h = max(max_h, hori[i]);
	}
	for (int i = vert.size() - 1; i >= 0; i--) {
		if (i != 0)	vert[i] -= vert[i - 1];
		max_w = max(max_w, vert[i]);
	}
	if (max_w == 0)	max_w = w;
	if (max_h == 0)	max_h = h;

	cout << max_w * max_h;
	return 0;
}