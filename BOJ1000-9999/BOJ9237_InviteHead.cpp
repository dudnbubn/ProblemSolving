#include <iostream>
#include <algorithm>
using namespace std;

int saplings[100000];

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int n, maximum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> saplings[i];
	sort(saplings, saplings + n, compare);
	for (int i = 0; i < n; i++) maximum = max(maximum, saplings[i] + i + 1);
	cout << maximum + 1;
	return 0;
}