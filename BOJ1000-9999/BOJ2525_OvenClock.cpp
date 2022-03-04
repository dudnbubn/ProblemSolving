#include <iostream>

using namespace std;

int main() {
	int hour, minute, work;
	cin >> hour >> minute >> work;
	minute += hour * 60 + work;
	cout << (minute / 60) % 24 << " " << minute % 60;
	return 0;
}