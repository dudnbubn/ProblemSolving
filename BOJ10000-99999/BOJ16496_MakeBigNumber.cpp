#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 1000
string arr[MAX_N];

bool compare(string a, string b) {
	string ab = a + b;
	string ba = b + a;
	return ba < ab;
}

int main() {
	int N;
	cin >> N;

	bool zeros = true;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] != "0")	zeros = false;
	}

	if (zeros)	cout << "0";
	else {
		sort(arr, arr + N, compare);
		for (int i = 0; i < N; i++)
			cout << arr[i];
	}
	return 0;
}