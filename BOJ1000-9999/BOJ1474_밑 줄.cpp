#include <iostream>

using namespace std;

string arr[10];

int main() {
	int N, M;
	cin >> N >> M;
	for (int n = 0; n < N; n++) {
		cin >> arr[n];
		M -= arr[n].size();
	}
	
	int Q = M / (N - 1);
	int R = M % (N - 1);

	string under = "";
	for (int q = 0; q < Q; q++)
		under.push_back('_');
	
	cout << arr[0];
	for (int n = 1; n < N; n++) {
		cout << under;
		if ((arr[n][0] > '_' && R > 0) || (N - n == R)) {
			cout << '_';
			R--;
		}
		cout << arr[n];
	}
}