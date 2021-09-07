#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<pair<int, int>, int> ppiii;

ppiii info[100];
int n;
int full[101] = { 0, };

bool compare(ppiii a, ppiii b) {
	return a.second > b.second;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> info[i].first.first >> info[i].first.second >> info[i].second;
	sort(info, info + n, compare);
	
	int cnt = 3;
	for (int i = 0; cnt; i++) {
		if (full[info[i].first.first] < 2) {
			full[info[i].first.first]++;
			cnt--;
			cout << info[i].first.first << " " << info[i].first.second << "\n";
		}
	}
	return 0;
}