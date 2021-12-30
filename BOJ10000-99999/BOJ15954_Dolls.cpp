#include <iostream>
#include <cmath>
using namespace std;

long long arr[500];

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	long double sum = 0;
	long double result =  300000000000;

	for (int a = 0; a <= n - k; a++) {
		sum = 0;
		for (int b = a; b < a + k - 1; b++)
			sum += arr[b];
		for (int i = a + k - 1; i < n; i++) {
			sum += arr[i];
	
			long double m = sum / (i - a + 1);
			
			long double div = 0;
			for (int j = a; j <= i; j++) {
				div += (arr[j] - m) * (arr[j] - m);
			}
			div /= (i - a + 1);
			
			if (result > div)
				result = div;
		}
	}
	cout.precision(11);
	result = sqrt(result);
	cout << fixed << result;
	return 0;
}