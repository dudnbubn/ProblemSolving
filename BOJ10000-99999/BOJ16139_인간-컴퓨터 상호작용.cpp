#include <iostream>

using namespace std;

int dp[26][200'000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s;
	cin >> s;

	dp[s[0] - 'a'][0] = 1;
	int s_size = s.size();
	for (int sz = 1; sz < s_size; sz++) {
		for (int i = 0; i < 26; i++) {
			dp[i][sz] = dp[i][sz - 1];
		}
		dp[s[sz] - 'a'][sz]++;
	}

	int Q;
	cin >> Q;

	char alphabet;
	int L, R;
	while (Q--) {
		cin >> alphabet >>  L >> R;
		cout << (L == 0 ? dp[alphabet - 'a'][R] : dp[alphabet - 'a'][R] - dp[alphabet - 'a'][L - 1]) << "\n";
	}
	return 0;
}