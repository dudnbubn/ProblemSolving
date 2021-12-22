// 학번은 8자리의 숫자인데 맨 앞이 0 일 수도 있다.
// 따라서 int가 아닌 string으로 표현해주어야 출력에 오류가 없다.

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<string, int> mp;

bool compare(pair<string, int> a, pair<string, int> b) {
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k, l;
	cin >> k >> l;
	string num;
	for (int i = 0; i < l; i++) {
		cin >> num;
		if (mp.find(num) != mp.end())	mp[num] = i;
		else	mp.insert({ num, i });
	}
	
	vector<pair<string, int>> v(mp.begin(), mp.end());
	sort(v.begin(), v.end(), compare);
	for (int i = 0; (i < k) && (i < v.size()); i++)
		cout << v[i].first << "\n";
	return 0;
}