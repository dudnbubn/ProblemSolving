#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

long long s, t;
queue<pair<int, string>> q;
vector<string> v;

bool compare(string a, string b) {
	if (a.size() == b.size())
		return a < b;
	return a.size() < b.size();
}

int main() {	
	cin >> s >> t;

	if (s == t)	cout << 0;
	else if (t == 0)	cout << '-';
	else {
		q.push({ s, ""});
		q.push({ 1, "/" });

		pair<long long, string> cur;
		while (!q.empty()) {
			cur = q.front();
			q.pop();

			if (cur.first == t) {
				v.push_back(cur.second);
				continue;
			}

			if (cur.first != 1 && (cur.first * cur.first <= t))
				q.push({ cur.first * cur.first, cur.second + '*' });
			if (cur.first <= t / 2)
				q.push({ 2 * cur.first, cur.second + '+' });
		}

		if (v.empty())	cout << -1;
		else {
			sort(v.begin(), v.end(), compare);
			cout << v[0];
		}
	}

	return 0;
}