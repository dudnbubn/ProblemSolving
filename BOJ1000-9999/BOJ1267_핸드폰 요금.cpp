#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	int Y = 0, M = 0;

	int cost;
	for (int n = 0; n < N; n++) {
		cin >> cost;
		Y += (cost / 30 + 1) * 10;
		M += (cost / 60 + 1) * 15;
	}

	if (Y == M)		cout << "Y M " << Y;
	else if (Y < M)		cout << "Y " << Y;
	else	cout << "M " << M;
}