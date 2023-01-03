/* 
y가 작은 순으로 정렬하고 y가 같은 경우 x가 작은 순으로 정렬한다
*/

#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;

int N;
pair<int, int> coordinates[100001];
pair<int, int> start;
bool is_same[100001];
stack<pair<int, int>> stk;
stack<pair<int, int>> save;

long long get_distance_to_start(pair<int, int> a) {
	long long fir = a.first, sec = a.second;
	return (fir - start.first) * (fir - start.first) + (sec - start.second) * (sec - start.second);
}

bool by_gradient(pair<int, int> a, pair<int, int> b) {
	double arct1 = atan2(a.second - start.second, a.first - start.first);
	double arct2 = atan2(b.second - start.second, b.first - start.first);

	if (arct1 == arct2) {
		if (a.second == b.second)	return a.first < b.first;
		return a.second < b.second;
	}

	return arct1 < arct2;
}

long long ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
	long long x1 = p1.first, y1 = p1.second;
	long long x2 = p2.first, y2 = p2.second;
	long long x3 = p3.first, y3 = p3.second;
	
	long long result = x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3;
	if (result > 0)	return 1;
	else if (result == 0)	return 0;
	else	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	
	start = { 40001, 40001 };
	for (int i = 1; i <= N; i++) {
		cin >> coordinates[i].first >> coordinates[i].second;

		if (coordinates[i].second < start.second) {
			start = coordinates[i];
		}
		else if (coordinates[i].second == start.second && coordinates[i].first < start.first) {
			start.first = coordinates[i].first;
		}
	}

	sort(coordinates + 1, coordinates + N + 1, by_gradient);
	
	stk.push(coordinates[1]);
	stk.push(coordinates[2]);
	pair<int, int> fir, sec, thi;
	for (int i = 3; i <= N; i++) {
		sec = stk.top();
		stk.pop();
		fir = stk.top();
		stk.push(sec);

		while (ccw(fir, sec, coordinates[i]) < 0) {
			stk.pop();

			sec = stk.top();
			stk.pop();
			fir = stk.top();
			stk.push(sec);
		}

		stk.push(coordinates[i]);
	}

	int result = stk.size();

	while (!stk.empty()) {
		save.push(stk.top());
		stk.pop();
	}

	fir = save.top();
	save.pop();
	sec = save.top();
	save.pop();
	while (!save.empty()) {
		thi = save.top();
		save.pop();

		if (ccw(fir, sec, thi) == 0)	result--;
		fir = sec;
		sec = thi;
	}
	cout << result;

	return 0;
}