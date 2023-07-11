#include <iostream>
#include <unordered_map>

using namespace std;

int enter;
unordered_map<string, int> um;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	string chat;
	int result = 0;
	for (int n = 0; n < N; n++) {
		cin >> chat;
		if (chat == "ENTER") {
			enter = n;
		}
		else {
			if (um.find(chat) == um.end() || um[chat] < enter) {
				result++;
			}
			um[chat] = n;
		}
	}
	cout << result;
	return 0;
}