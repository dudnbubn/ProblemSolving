#include <iostream>
#include <algorithm>

using namespace std;

int hambergers[1000];
int side_menus[1000];
int drinks[1000];

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int B, C, D;
	cin >> B >> C >> D;

	int maximum = max(max(B, C), D);
	
	int sum = 0, discount = 0;
	for (int b = 0; b < B; b++) {
		cin >> hambergers[b];
		sum += hambergers[b];
	}
	for (int c = 0; c < C; c++) {
		cin >> side_menus[c];
		sum += side_menus[c];
	}
	for (int d = 0; d < D; d++) {
		cin >> drinks[d];
		sum += drinks[d];
	}

	sort(hambergers, hambergers + B, compare);
	sort(side_menus, side_menus + C, compare);
	sort(drinks, drinks + D, compare);

	for(int i=0;i<maximum;i++) {
		if (i >= B || i >= C || i >= D)	break;
		discount += (hambergers[i] + side_menus[i] + drinks[i]) / 10;
	}
	cout << sum << "\n" << sum - discount;
}