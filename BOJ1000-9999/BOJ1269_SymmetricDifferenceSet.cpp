#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

set<int> A, B, C;

int main() {
	int a, b, input;
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		cin >> input;
		A.insert(input);
	}
	for (int i = 0; i < b; i++) {
		cin >> input;
		B.insert(input);
	}
	set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(C, C.begin()));
	cout << A.size() + B.size() - 2 * C.size();
	return 0;
}