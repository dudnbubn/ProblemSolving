// sort 함수의 파라미터로 들어갈 compare 함수를 문제에서 주어진 정렬 조건에 맞춰서 짜주면 해결되는 문제이다.
#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<string, pair<int, pair<int, int>>> students[100001];	// 이름, 국, 영, 수 페어를 저장하는 배열

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