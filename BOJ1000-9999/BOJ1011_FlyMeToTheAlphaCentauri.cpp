#include <iostream>
using namespace std;

long long jump[100000] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; jump[i - 1] + i < 2100000000; i++) {
		jump[i] = jump[i - 1] + i;
	}

	long long t, x, y;
	cin >> t;
	while (t--) {
		cin >> x >> y;
		y -= x;
		x = 0;
		if (y == 1)
			cout << 1 << "\n";
		else {
			long long index = 1;
			while (jump[index] * 2 <= y)
				index++;
			index--;
			y -= jump[index] * 2;
	
			if (y == 0)	index *= 2;
			else if (y <= index + 1)	index = index * 2 + 1;
			else	index = index * 2 + 2;
			cout << index << "\n";
		}
	}
	return 0;
}