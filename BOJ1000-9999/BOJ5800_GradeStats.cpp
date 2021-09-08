#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int testcase, n, gap;
	int grades[50];
	cin >> testcase;

	for (int t = 1; t <= testcase; t++) {
		cin >> n;
		gap = 0;
		for (int i = 0; i < n; i++)	cin >> grades[i];

		sort(grades, grades + n, compare);

		for (int i = 0; i < n - 1; i++)	gap = max(gap, grades[i] - grades[i + 1]);

		cout << "Class " << t << "\n";
		cout << "Max " << grades[0] << ", Min " << grades[n - 1] << ", Largest gap " << gap << "\n";
	}
	return 0;
}