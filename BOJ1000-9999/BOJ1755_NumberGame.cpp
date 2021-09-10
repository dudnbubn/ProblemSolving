#include <iostream>
#include <algorithm>
using namespace std;

int arr[100];

string read(int a) {
	switch (a) {
	case 0:	return "zero";
	case 1:	return "one";
	case 2:	return "two";
	case 3:	return "three";
	case 4:	return "four";
	case 5:	return "five";
	case 6:	return "six";
	case 7:	return "seven";
	case 8:	return "eight";
	case 9:	return "nine";
	}
}

bool compare(int a, int b) {
	string sa, sb;
	if (a < 10)	sa = read(a);
	else	sa = read(a / 10) + " " + read(a % 10);
	if (b < 10)	sb = read(b);
	else	sb = read(b / 10) + " " + read(b % 10);
	return sa < sb;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n;
	cin >> m >> n;
	for (int i = 0; i < n - m + 1; i++)	arr[i] = m + i;
	sort(arr, arr + n - m + 1, compare);
	for (int i = 0; i < n - m + 1; i++) {
		cout << arr[i] << " ";
		if (i % 10 == 9)	cout << "\n";
	}
	return 0;
}