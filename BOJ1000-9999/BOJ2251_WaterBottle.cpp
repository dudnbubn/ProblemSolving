#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

typedef pair<int, pair<int, int>> p;

int a, b, c;
set<p> s;
set<int> result;
set<int>::iterator iter;

void Brute(int sender, int receiver, int cur_a, int cur_b, int cur_c) {
	p temp;
	temp.first = cur_a;
	temp.second.first = cur_b;
	temp.second.second = cur_c;
	if (s.find(temp) == s.end()) {
		s.insert(temp);
		if (cur_a == 0)
			result.insert(cur_c);
	}
	else	return;

	int gap;
	if (cur_a > 0) {
		if (cur_b != b && (sender != 2 || receiver != 1)) {
			gap = min(b - cur_b, cur_a);
			Brute(1, 2, cur_a - gap, cur_b + gap, cur_c);
		}
		if (cur_c != c && (sender != 3 || receiver != 1)) {
			gap = min(c - cur_c, cur_a);
			Brute(1, 3, cur_a - gap, cur_b, cur_c + gap);
		}
	}
	if (cur_b > 0) {
		if (cur_a != a && (sender != 1 || receiver != 2)) {
			gap = min(a - cur_a, cur_b);
			Brute(2, 1, cur_a + gap, cur_b - gap, cur_c);
		}
		if (cur_c != c && (sender != 3 || receiver != 2)) {
			gap = min(c - cur_c, cur_b);
			Brute(1, 3, cur_a, cur_b - gap, cur_c + gap);
		}
	}
	if (cur_c > 0) {
		if (cur_b != b && (sender != 2 || receiver != 3)) {
			gap = min(b - cur_b, cur_c);
			Brute(3, 2, cur_a, cur_b + gap, cur_c - gap);
		}
		if (cur_a != a && (sender != 1 || receiver != 3)) {
			gap = min(a - cur_a, cur_c);
			Brute(3, 1, cur_a + gap, cur_b, cur_c - gap);
		}
	}
	
}

int main() {
	cin >> a >> b >> c;
	Brute(0, 0, 0, 0, c);
	
	for (iter = result.begin(); iter != result.end(); iter++)
		cout << *iter << " ";
	return 0;
}