// �й��� 8�ڸ��� �����ε� �� ���� 0 �� ���� �ִ�.
// ���� int�� �ƴ� string���� ǥ�����־�� ��¿� ������ ����.

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