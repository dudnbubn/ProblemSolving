#include <iostream>
using namespace std;

int main() {
	unsigned int s, i = 0;
	cin >> s;
	while (i <= s) {
		s -= i;
		i++;
	}
	cout << i - 1;
	return 0;
}