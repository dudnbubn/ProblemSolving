#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> arr[12];

int main() {
	int k, w = 0, h = 0;
	cin >> k;
	for (int i = 0; i < 6; i++) {
		cin >> arr[i].first >> arr[i].second;
		arr[i + 6] = arr[i];
		if (arr[i].first <= 2)
			w = max(w, arr[i].second);
		else
			h = max(h, arr[i].second);
	}
	for (int i = 0; i < 6; i++) {
		if ((arr[i].first == arr[i + 2].first) && (arr[i + 1].first == arr[i + 3].first)) {
			if (arr[i].first <= 2)
				cout << k * ((w * h) - ((w - arr[i].second) * arr[i + 1].second));
			else
				cout << k * ((w * h) - ((h - arr[i].second) * arr[i + 1].second));
			return 0;
		}
	}
}