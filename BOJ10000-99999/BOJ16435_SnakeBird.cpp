#include <iostream>
#include <algorithm>
using namespace std;

int n, l;
int h[10000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> l;
	for (int i = 0; i < n; i++)	cin >> h[i];
	sort(h, h + n);
	for (int i = 0; i < n; i++)
		if (l >= h[i])	l++;
	cout << l;
	return 0;
}