#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

unordered_map<int, int> num_map;
priority_queue<int, vector<int>> max_pq;
priority_queue<int, vector<int>, greater<int>> min_pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	
	int k, num;
	char cmd;

	while (t--) {
		num_map = {};	max_pq = {};	min_pq = {};
		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> cmd >> num;
			switch (cmd) {
			case 'I':
				max_pq.push(num);
				min_pq.push(num);
				if (num_map.find(num) == num_map.end())	num_map[num] = 1;
				else	num_map[num]++;
				break;
			case 'D':
				if (num == 1) {
					if (max_pq.empty())	break;
					num = max_pq.top();
					max_pq.pop();
					while (num_map[num] == 0 && !max_pq.empty()) {
						num = max_pq.top();
						max_pq.pop();
					}
					if (num_map[num])	num_map[num]--;
				}
				else {
					if (min_pq.empty())	break;
					num = min_pq.top();
					min_pq.pop();
					while (num_map[num] == 0 && !min_pq.empty()) {
						num = min_pq.top();
						min_pq.pop();
					}
					if (num_map[num])	num_map[num]--;
				}
			}
		}
		if (max_pq.empty() || min_pq.empty()) {
			cout << "EMPTY\n";
			continue;
		}
		int maximum = max_pq.top(), minimum = min_pq.top();
		max_pq.pop();	min_pq.pop();
		while (num_map[maximum] == 0 && !max_pq.empty()) {
			maximum = max_pq.top();
			max_pq.pop();
		}
		while (num_map[minimum] == 0 && !min_pq.empty()) {
			minimum = min_pq.top();
			min_pq.pop();
		}
		if (!num_map[maximum])	cout << "EMPTY\n";
		else	cout << maximum << ' ' << minimum << '\n';
	}
	return 0;
}