#include <iostream>
#include <algorithm>
using namespace std;

int crane[50];
int index[50];
int box[10010];
bool complete[10010] = { 0, };

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> crane[i];
	cin >> m;
	for (int i = 0; i < m; i++)	cin >> box[i];

	sort(crane, crane + n, compare);
	sort(box, box + m, compare);
	
	if (crane[0] < box[0]) {
		cout << -1;
	}
	else {
		for (int i = 0; i < n; i++) {
			int j = 0;
			while (crane[i] < box[j]) {
				j++;
				index[i] = j;
			}
		}

		int t = 0;
		int cnt = 0;
		while (cnt < m) {
			t++;
			for (int i = 0; i < n; i++) {
				while ((index[i] < m) && complete[index[i]])	index[i]++;
				if (index[i] >= m)	break;
				complete[index[i]] = true;
				cnt++;
			}
		}
		cout << t;
	}
	return 0;
}