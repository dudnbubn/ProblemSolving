#include <iostream>
using namespace std;

bool check[2001] = { 0, };
int n, num;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		check[num + 1000] = true;
	}
	for (int i = 0; i <= 2000; i++)
		if (check[i])	cout << i - 1000 << " ";
	return 0;
}