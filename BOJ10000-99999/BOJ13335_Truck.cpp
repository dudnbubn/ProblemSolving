#include <iostream>
#include <queue>
using namespace std;

int arr[1001];

int main() {
	int n, w, l;
	cin >> n >> w >> l;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int qsum = 0, index = 0, t = 0;
	queue<int> bridge;
	while (1) {
		t++;
		if (bridge.size() == w) {
			qsum -= bridge.front();
			bridge.pop();
		}

		if (qsum + arr[index] <= l) {
			bridge.push(arr[index]);
			qsum += arr[index];
			index++;
			if (index == n) {
				t += w;
				break;
			}
		}
		else {
			bridge.push(0);
		}
	}
	cout << t;
	return 0;
}