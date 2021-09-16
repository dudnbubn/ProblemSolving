#include <iostream>
using namespace std;

bool isPrime[1001];

void Eratos() {
	for (int i = 2; i <= 1000; i++)	isPrime[i] = true;

	for (int i = 2; i <= 1000; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= 1000; j += i)
				isPrime[j] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int testcase, k, fir, sec;
	cin >> testcase;
	Eratos();
	while (testcase--) {
		cin >> k;
		fir = 0;	sec = 0;
		for (int i = 2; i < k / 2; i++) {
			if (isPrime[i]) {
				if (isPrime[k - 2 * i]) {
					fir = i;	sec = i;
					break;
				}
				else {
					for (int j = i + 1; j < k / 2; j++) {
						if (isPrime[j] && isPrime[k - (i + j)]) {
							fir = i;	sec = j;
							break;
						}
					}
				}
				if (fir && sec)	break;
			}
		}
		if (fir && sec)
			cout << fir << " " << sec << " " << k - (fir + sec) << "\n";
		else
			cout << 0 << "\n";
	}
	return 0;
}