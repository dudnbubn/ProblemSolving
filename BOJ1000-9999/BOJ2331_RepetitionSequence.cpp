#include <iostream>
#include <set>
#include <vector>
using namespace std;

int a, p;
int power[10];
set<int> seq;
vector<int> v;

int disassemble(int a) {
	int result = 0;
	while (a != 0) {
		result += power[a % 10];
		a /= 10;
	}
	return result;
}

int main() {
	cin >> a >> p;
	for (int i = 1; i < 10; i++) {
		int pow = 1;
		for (int j = 0; j < p; j++)
			pow *= i;
		power[i] = pow;
	}
	while (seq.find(a) == seq.end()) {
		v.push_back(a);
		seq.insert(a);
		a = disassemble(a);
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == a) {
			cout << i;
			break;
		}
	}
	return 0;
}