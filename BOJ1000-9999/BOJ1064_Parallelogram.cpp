#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int x[3];
int y[3];
double r[3];
double d[2];

double getR(int x1, int y1, int x2, int y2, int x3, int y3) {
	double r1 = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	double r2 = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
	return r1 + r2;
}

int main() {
	for (int i = 0; i < 3; i++)
		cin >> x[i] >> y[i];

	double result = -1;
	if (x[0] != x[1] || x[1] != x[2]) {
		for (int i = 0; i < 2; i++)
			d[i] = ((double)y[i + 1] - y[i]) / (x[i + 1] - x[i]);
	}

	if (d[0] != d[1]) {
		for (int i = 0; i < 3; i++)
			r[i] = getR(x[i], y[i], x[(i + 1) % 3], y[(i + 1) % 3], x[(i + 2) % 3], y[(i + 2) % 3]);
		
		sort(r, r + 3);
		result = (r[2] - r[0]) * 2;
	}

	cout.precision(10);
	cout << fixed << result;
	return 0;
}