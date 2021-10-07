#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string fibo[10001];

string sumString(string a, string b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	string result = "";
	int int_a, int_b;
	int sz_a = a.size(), sz_b = b.size(), carry = 0, sum = 0;
	for (int idx_a = 0, idx_b = 0; idx_a < sz_a || idx_b < sz_b; idx_a++, idx_b++) {
		int_a = 0;	int_b = 0;
		if (idx_a < sz_a)	int_a = a[idx_a] - '0';
		if (idx_b < sz_b)	int_b = b[idx_b] - '0';
		sum = int_a + int_b + carry;
		carry = sum / 10;
		sum %= 10;
		result = (char)(sum + '0') + result;
	}
	if (carry)	result = "1" + result;
	
	return result;
}

string Fibonacci(int n) {
	if (fibo[n] != "")	return fibo[n];
	
	return fibo[n] = sumString(Fibonacci(n - 1), Fibonacci(n - 2));
}

int main() {
	int n;
	cin >> n;
	fibo[0] = "0";	fibo[1] = "1";
	for (int i = 2; i <= 10000; i++)	fibo[i] = "";
	
	cout << Fibonacci(n);
	return 0;
}