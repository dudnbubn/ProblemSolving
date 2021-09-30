// x축과 y축을 독립적으로 계산하면 풀 수 있다고 한다...

#include <iostream>
using namespace std;

int main() {
	int w, h, p, q, t;
	cin >> w >> h >> p >> q >> t;

	int tw = t % (2 * w);
	int th = t % (2 * h);

	p = p + tw;
	q = q + th;

	if (p > w)	p = 2 * w - p;
	if (q > h)	q = 2 * h - q;
	if (q < 0)	q = (-1) * q;
	if (p < 0) p = (-1) * p;
	cout << p << " " << q;

	return 0;
}