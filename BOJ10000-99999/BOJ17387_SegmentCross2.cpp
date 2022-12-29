#include <iostream>

using namespace std;

int get_ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
	long long result = x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3;

	if (result > 0)	return 1;
	else if (result == 0)	return 0;
	else	return -1;
}

bool in_range(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	if (x1 < x2) {
		if ((x3 < x1 && x4 < x1) || (x3 > x2 && x4 > x2))	return false;
	}
	else {
		if ((x3 < x2 && x4 < x2) || (x3 > x1 && x4 > x1))	return false;
	}
	if (y1 < y2) {
		if ((y3 < y1 && y4 < y1) || (y3 > y2 && y4 > y2))	return false;
	}
	else {
		if ((y3 < y2 && y4 < y2) || (y3 > y1 && y4 > y1))	return false;
	}

	return true;
}

bool is_cross(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	int ccw1 = get_ccw(x1, y1, x2, y2, x3, y3) * get_ccw(x1, y1, x2, y2, x4, y4);
	int ccw2 = get_ccw(x3, y3, x4, y4, x1, y1) * get_ccw(x3, y3, x4, y4, x2, y2);

	if (ccw1 == 0 && ccw2 == 0) 
		return in_range(x1, y1, x2, y2, x3, y3, x4, y4);
	return ccw1 <= 0 && ccw2 <= 0;
}

int main() {
	int x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	cout << is_cross(x1, y1, x2, y2, x3, y3, x4, y4) ? 1 : 0;
}