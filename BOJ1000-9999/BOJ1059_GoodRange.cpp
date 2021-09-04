#include <iostream>
using namespace std;

bool exist[1001] = { 0, };

int main() {
	int l, num, n;
	cin >> l;
	for (int i = 0; i < l; i++) {
		cin >> num;
		exist[num] = true;
	}
	cin >> n;
	if (exist[n])	cout << 0;
	else {
		int minimum = n, maximum = n;
		while ((minimum > 0) && !exist[minimum])	minimum--;
		while ((maximum <= 1000) && !exist[maximum])	maximum++;
		cout << (maximum - n) * (n - minimum) - 1;
	}
	return 0;
}