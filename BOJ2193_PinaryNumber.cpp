//#include <iostream>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	long long pn[91][2] = { 0, };
//	pn[1][0] = 0;
//	pn[1][1] = 1;
//	for (int i = 2; i <= n; i++) {
//		pn[i][0] = pn[i - 1][0] + pn[i - 1][1];
//		pn[i][1] = pn[i - 1][0];
//	}
//	cout << pn[n][0] + pn[n][1];
//	return 0;
//}