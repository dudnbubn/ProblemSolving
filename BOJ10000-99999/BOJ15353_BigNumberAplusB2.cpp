#include <iostream>
using namespace std;

int main() {
	string A, B;
	cin >> A >> B;
	string result = "";
	int asz = A.size(), bsz = B.size();
	int a, b, carry = 0, sum;
	for (int aidx = asz - 1, bidx = bsz - 1; aidx >= 0 || bidx >= 0; aidx--, bidx--) {
		a = 0, b = 0;
		if (aidx >= 0)	a = A[aidx] - '0';
		if (bidx >= 0)	b = B[bidx] - '0';
		sum = a + b + carry;
		carry = sum / 10;
		sum %= 10;
		result = (char)(sum + '0') + result;
	}
	if (carry)	result = '1' + result;
	cout << result;
	return 0;
}