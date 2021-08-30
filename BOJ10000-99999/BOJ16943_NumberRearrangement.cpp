// Brute Force
#include <iostream>
#include <algorithm>
using namespace std;

string a;
int b;
int arr[10] = { 0, };
bool isUsed[10] = { 0 }; 
int maximum = 0;


void Brute(int k, int sum) {
	if (k == a.size()) {
		if (sum < b) {
			maximum = max(maximum, sum);
		}
	}

	for (int i = 0; i < a.size(); i++) {
		if ((sum == 0) && (arr[i] == 0))
			continue;
		if (!isUsed[i]) {
			isUsed[i] = true;
			Brute(k + 1, sum * 10 + arr[i]);
			isUsed[i] = false;
		}
	}
}

int main() {	
	cin >> a >> b;
	for (int i = 0; i < a.size(); i++)
		arr[i] = a[i] - '0';
	sort(arr, arr + a.size());
	Brute(0, 0);
	if (maximum != 0)	cout << maximum;
	else	cout << -1;
	return 0;
}