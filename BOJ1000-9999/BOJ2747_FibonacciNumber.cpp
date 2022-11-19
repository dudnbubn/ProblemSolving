#include <iostream>
using namespace std;

int f[46];

int main() {
	int N;
	cin >> N;
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i <= N; i++) 
		f[i] = f[i - 1] + f[i - 2];
	cout << f[N];
}