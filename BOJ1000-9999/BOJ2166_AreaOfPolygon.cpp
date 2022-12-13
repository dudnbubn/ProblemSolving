#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> positions[10000];

double get_area(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
	double x1 = p1.first, y1 = p1.second;
	double x2 = p2.first, y2 = p2.second;
	double x3 = p3.first, y3 = p3.second;
	return ((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)) / 2;
}

int main() {
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> positions[i].first >> positions[i].second;

	double result = 0;
	for (int i = 1; i < N - 1; i++) {
		result += get_area(positions[0], positions[i], positions[i + 1]);
	}
	
	cout.precision(1);
	cout << fixed <<(result < 0 ? -result : result);

	return 0;
}