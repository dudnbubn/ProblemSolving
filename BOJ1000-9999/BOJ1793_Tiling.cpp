// n == 0 일 때도 1가지...?

#include <iostream>
using namespace std;

string dp[251][3];

string add_str(string a, string b) {
	string result = "";
	int index_a, index_b;
	int int_a, int_b, carry = 0, sum = 0;
	for (int index_a = a.size() - 1, index_b = b.size() - 1; index_a >= 0 || index_b >= 0; index_a--, index_b--) {
		int_a = 0;	int_b = 0;
		if (index_a >= 0)	int_a = a[index_a] - '0';
		if (index_b >= 0)	int_b = b[index_b] - '0';
		sum = int_a + int_b + carry;
		carry = (sum / 10);
		sum %= 10;
		result = (char)(sum + '0') + result;
	}
	if (carry == 1)	result = "1" + result;
	
	return result;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 251; i++)
		for (int j = 0; j < 3; j++)
			dp[i][j] = "";

	dp[0][0] = "0";		dp[0][1] = "0";		dp[0][2] = "1";
	dp[1][0] = "0";		dp[1][1] = "1";		dp[1][2] = "0";
	dp[2][0] = "1";		dp[2][1] = "1";		dp[2][2] = "1";

	for (int i = 3; i <= 250; i++) {
		dp[i][0] = add_str(add_str(dp[i - 2][0], dp[i - 2][1]), dp[i - 2][2]);
		dp[i][1] = add_str(add_str(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
		dp[i][2] = add_str(add_str(dp[i - 2][0], dp[i - 2][1]), dp[i - 2][2]);
	}
	
	int n;
	while(true){
		cin >> n;
		if (cin.eof() == true)	break;
		cout << add_str(add_str(dp[n][0], dp[n][1]), dp[n][2]) << "\n";
	}
	
	return 0;
}