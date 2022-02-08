#include <iostream>
#include <map>
using namespace std;

map<int, string> fibo;

string strAdd(string a, string b) {
	string result = "";
	int num_a, num_b, sum, carry = 0;
	for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; i--, j--) {
		num_a = 0;	num_b = 0;
		if (i >= 0)	num_a = a[i] - '0';
		if (j >= 0)	num_b = b[j] - '0';
		sum = num_a + num_b + carry;
		carry = sum / 10;
		sum %= 10;
		result = (char)(sum + '0') + result;
	}
	if (carry)	result = '1' + result;
	return result;
}

string Fibonacci(int n) {
	if (fibo.find(n) != fibo.end())	return fibo[n];
	return fibo[n] = strAdd(Fibonacci(n - 1), Fibonacci(n - 2));
}

int main() {
	int n;
	cin >> n;
	fibo[1] = "1";	fibo[2] = "1";
	cout << Fibonacci(n);
	return 0;
}