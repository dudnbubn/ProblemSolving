#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int N;
string input;
int is_palindrome[2500][2500];
int dp[2501];

int check_palindrome(int left, int right) {
	if (is_palindrome[left][right] != -1)	return is_palindrome[left][right];
	if (left == right)	return true;
	if (input[left] != input[right])	return is_palindrome[left][right] = 0;
	if (left + 1 == right) return true;

	return is_palindrome[left][right] = check_palindrome(left + 1, right - 1);
}

int get_minimum_palindrome_count(int start) {
	if (dp[start] != -1)	return dp[start];
	if (start == N)	return dp[start] = 0;

	int result = 2500;
	for (int i = start; i < N; i++) {
		if (check_palindrome(start, i))	result = min(result, 1 + get_minimum_palindrome_count(i + 1));
	}
	return dp[start] = result;
}

int main() {
	cin >> input;
	memset(dp, -1, sizeof(dp));
	memset(is_palindrome, -1, sizeof(is_palindrome));
	N = input.size();

	cout << get_minimum_palindrome_count(0);
	return 0;
}