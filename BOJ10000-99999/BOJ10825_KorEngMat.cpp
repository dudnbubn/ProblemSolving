// sort �Լ��� �Ķ���ͷ� �� compare �Լ��� �������� �־��� ���� ���ǿ� ���缭 ¥�ָ� �ذ�Ǵ� �����̴�.
#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<string, pair<int, pair<int, int>>> students[100001];	// �̸�, ��, ��, �� �� �����ϴ� �迭

bool compare(pair<string, pair<int, pair<int, int>>> a, pair<string, pair<int, pair<int, int>>> b) {
	if (a.second.first == b.second.first) {
		if (a.second.second.first == b.second.second.first) {
			if (a.second.second.second == b.second.second.second)
				return a.first < b.first;
			return a.second.second.second > b.second.second.second;
		}
		return a.second.second.first < b.second.second.first;
	}
	return a.second.first > b.second.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> students[i].first >> students[i].second.first >> students[i].second.second.first >> students[i].second.second.second;

	sort(students, students + n, compare);
	for (int i = 0; i < n; i++)
		cout << students[i].first << "\n";
	return 0;
}