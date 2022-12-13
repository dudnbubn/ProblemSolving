//#include <iostream>
//
//using namespace std;
//
//bool is_number(char c) {
//	return ('0' <= c && c <= '9');
//}
//
//bool is_uppercase(char c) {
//	return ('A' <= c && c <= 'Z');
//}
//
//int main() {
//	string s;
//	cin >> s;
//	
//	bool result = true;
//	if (!is_uppercase(s[0]) || !is_uppercase(s[7]))	result = false;
//
//	int number = 0;
//	for (int i = 1; i <= 6; i++) {
//		if (!is_number(s[i]))	break;
//		number = (number * 10) + (s[i] - '0');
//	}
//	
//	if (number < 100000 || number > 999999)	result = false;
//
//	cout << (result ? "Yes" : "No");
//	return 0;
//}