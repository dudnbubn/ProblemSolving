#include <iostream>

using namespace std;
int m, v,u,d,i;
int main() {
	for (i = 0; i < 10; i++) {
		cin >> u >> d;
		v += d-u;
		m = m > v ? m : v;
	}
	cout << m;
}