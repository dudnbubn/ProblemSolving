#include <iostream>
using namespace std;

int arr[10] = { 0, };
string s;

int main() {	
	cin >> s;
	for (int i = 0; i < s.size(); i++)	arr[s[i] - '0']++;
	arr[6] = (arr[6] + arr[9] + 1) / 2;

	int cnt = 0;
	for (int i = 0; i < 9; i++) {
		if (cnt < arr[i])	cnt = arr[i];
	}
	cout << cnt;
	return 0;
}