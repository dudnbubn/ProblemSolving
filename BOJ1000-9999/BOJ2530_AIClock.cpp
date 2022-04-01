#include <iostream>

using namespace std;

int main() {
	int h, m, s, d;
	cin >> h >> m >> s >> d;

	s += h * 3600 + m * 60 + d;
	cout << (s / 3600) % 24 << " " << (s / 60) % 60 << " " << s % 60;
	return 0;
}