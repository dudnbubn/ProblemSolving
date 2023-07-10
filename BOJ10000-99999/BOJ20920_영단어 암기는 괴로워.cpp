#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

unordered_map<string, int> um;
vector<pair<string, int>> v;


bool compare(pair<string, int> a, pair<string, int> b) {
	if (a.second == b.second) {
		if (a.first.size() == b.first.size()) {
			return a.first < b.first;
		}
		return a.first.size() > b.first.size();
	}
	return a.second > b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	string word;
	for (int n = 0; n < N; n++) {
		cin >> word;
		if (word.size() >= M) {
			if (um.find(word) != um.end())	um[word]++;
			else	um[word] = 1;
		}
	}

	for (pair<string, int> item : um) {
		v.push_back(item);
	}

	sort(v.begin(), v.end(), compare);
	for (pair<string, int> item : v)
		cout << item.first << "\n";
}