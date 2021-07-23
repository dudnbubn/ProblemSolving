// // 입력받은 수를 -2로 나눈다. 
// // 만약 나머지가 -1이 나온다면 1이 되도록 몫과 나머지를 바꿔준다. ex) -13 = (-2)*6 + (-1) = (-2)*7 + 1
//#include <iostream>
//using namespace std;
//
//int main() {
//	int n, r;
//	cin >> n;
//	string nbin = "";
//	if (n == 0) {
//		cout << 0;
//		return 0;
//	}
//	while (n != 0) {
//		r = n % -2;
//		n = n / -2;
//		if (r == -1) {
//			r = 1;
//			n++;
//		}
//		nbin = char(r + '0') + nbin;
//	}
//	cout << nbin;
//	return 0;
//}