// a, b 를 문자열로 입력받고 부호를 꼼꼼히 따져서 계산해줘야 함.
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a, b;
	cin >> a >> b;
	vector<int> answer;
	int val_a = 0, val_b = 0, val = 0, asz, bsz;
	bool sign_a = true, sign_b = true, carry = false;
	if (a[0] == '-') {
		sign_a = false;
		a = a.substr(1);
	}
	if (b[0] == '-') {
		sign_b = false;
		b = b.substr(1);
	}
	asz = a.size();
	bsz = b.size();
	if (sign_a == sign_b) {
		for (int idx_a = asz - 1, idx_b = bsz - 1; idx_a >= 0 || idx_b >= 0; idx_a--, idx_b--) {
			val_a = 0, val_b = 0;
			if (idx_a >= 0) val_a = a[idx_a] - '0';
			if (idx_b >= 0) val_b = b[idx_b] - '0';
			val = val_a + val_b;
			if (carry) {
				val++;
				carry = false;
			}
			if (val >= 10) {
				val -= 10;
				carry = true;
			}
			answer.push_back(val);
		}
		if (carry)	answer.push_back(1);

		if (!sign_a)
			cout << '-';
		for (int i = answer.size() - 1; i >= 0; i--)
			cout << answer[i];
	}
	else {
		bool big_a = false;
		for (int idx_a = asz - 1, idx_b = bsz - 1; idx_a >= 0 || idx_b >= 0; idx_a--, idx_b--) {
			val_a = 0, val_b = 0;
			if (idx_a >= 0) val_a = a[idx_a] - '0';
			if (idx_b >= 0) val_b = b[idx_b] - '0';
			if (asz > bsz || ((asz == bsz) && (a >= b))) {
				val = val_a - val_b;
				big_a = true;
			}
			else
				val = val_b - val_a;
			answer.push_back(val);
		}
		for (int i = 0; i < answer.size() - 1; i++) {
			if (answer[i] < 0) {
				answer[i] += 10;
				answer[i + 1]--;
			}
		}
		if (big_a == !sign_a && a != b) {
			cout << '-';
		}
		bool flag = false;
		for (int i = answer.size() - 1; i >= 0; i--) {
			if (answer[i] != 0)
				flag = true;
			if (flag)
				cout << answer[i];
		}
		if (!flag)
			cout << 0;
	}
	return 0;
}