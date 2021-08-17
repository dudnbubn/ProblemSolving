// prioirty_queue 를 이용하여 MaxHeap과 MinHeap을 만들고
// 양수는 MinHeap, 음수는 MaxHeap에 넣으면서 top을 비교하면 풀리는 간단한 문제이다.
#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;

	int n, cmd;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == 0) {
			if (max_heap.empty() && min_heap.empty())	
				cout << 0 << "\n";
			else if (max_heap.empty()) {
				cout << min_heap.top() << "\n";
				min_heap.pop();
			}
			else if (min_heap.empty()) {
				cout << max_heap.top() << "\n";
				max_heap.pop();
			}
			else {
				if ((max_heap.top() * (-1)) > min_heap.top()) {
					cout << min_heap.top() << "\n";
					min_heap.pop();
				}
				else {
					cout << max_heap.top() << "\n";
					max_heap.pop();
				}
			}
		}
		else {
			if (cmd > 0)	min_heap.push(cmd);
			else	max_heap.push(cmd);
		}
	}
	return 0;
}