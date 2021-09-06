// 연속된 같은 숫자는 1회에 다 뒤집을 수 있기 때문에 그냥 하나의 숫자로 생각했다.
// 또한 0 또는 1로만 뒤집힐 수 있으므로 그냥 뒤집힌 수를 세고 +1 을 하여 반으로 나누었다. 
// ( 만약 cnt = 3 이라면 다른 수 덩어리가 2개이므로 최소 (3+1)/2 번 뒤집어야 모두 같은 수가 나온다. ex) 11001100 )

#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] != s[i - 1])	cnt++;
	}
	cout << (cnt + 1) / 2;
	return 0;
}