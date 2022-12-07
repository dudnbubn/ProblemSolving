#include <iostream>
#include <string.h>

using namespace std;

int arr[2001];
int is_palindrome[2001][2001];

int check_palindrome(int S, int E) {
	if (arr[S] != arr[E])	return is_palindrome[S][E] = 0;
	if (E - S <= 1)	return is_palindrome[S][E] = 1;
	return is_palindrome[S][E] = check_palindrome(S + 1, E - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	memset(is_palindrome, -1, sizeof(is_palindrome));

	int N, M;
	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> arr[i];

	cin >> M;
	int S, E;
	for (int i = 0; i < M; i++) {
		cin >> S >> E;
		if (is_palindrome[S][E] == -1)	check_palindrome(S, E);
		
		cout << (is_palindrome[S][E] ? 1 : 0) << "\n";
	}
	return 0;
}