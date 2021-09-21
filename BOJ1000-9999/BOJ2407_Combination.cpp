// 최댓값으로 나올 수 있는 n = 100, m = 50 의 경우 long long 의 범위를 초과한다.

#include <iostream>
#include <string>
using namespace std;

string ncr[101][101];

string strPlus(string a, string b) {
	int asz = a.size(), bsz = b.size();
	int carry = 0;
	int aint, bint, sum;
	string result = "";
	for (int aidx = asz - 1, bidx = bsz - 1; aidx >= 0 || bidx >= 0; aidx--, bidx--) {
		aint = 0;	bint = 0;
		if (aidx >= 0)	aint = a[aidx] - '0';
		if (bidx >= 0)	bint = b[bidx] - '0';
		sum = aint + bint + carry;
		carry = sum / 10;
		sum %= 10;
		result = (char)(sum + '0') + result;
	}
	if (carry)	result = '1' + result;
	return result;
}

string nCr(int n, int r) {
	if (ncr[n][r] != "")	return ncr[n][r];
	if (n == r || r == 0)	return "1";
	if (n < r) return "0";
	ncr[n][r] = strPlus(nCr(n - 1, r), nCr(n - 1, r - 1));
	ncr[n][n - r] = ncr[n][r];
	return ncr[n][r];
}

int main() {
	int n, m;
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			ncr[i][j] = "";
	cin >> n >> m;
	cout << nCr(n, m);
	return 0;
}