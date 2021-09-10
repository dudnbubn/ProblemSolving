// algorithm 을 include 하여 쓸 수 있는 set_difference 함수를 사용
// 5번째 인자로 inserter라는 함수라는 것을 사용한다. 해당 컨테이너의 insert 함수를 호출한다고 한다.
// inserter함수 대신에 vector의 begin iterator를 넣고 (임의로 v.begin() 라고하자) 결과값을 vector iterator에(임의로 ls) 저장하는 방법도 있다.
// 그러고 난 후 또 다른 vector iterator iter를 v.begin() 부터 iter < ls 까지 iter++ 하면서 값을 구하면  차집합 값이 나온다. 차집합의 사이즈는 ls - v.begin() 이다.

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

set<int> a, b, result;
set<int>::iterator iter;
int n, m, num;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num;
		a.insert(num);
	}
	for (int i = 0; i < m; i++) {
		cin >> num;
		b.insert(num);
	}
	set_difference(a.begin(), a.end(), b.begin(), b.end(),
		inserter(result, result.end()));
	cout << result.size() << "\n";
	for (iter = result.begin(); iter != result.end(); iter++)
		cout << *iter << " ";
	return 0;
}