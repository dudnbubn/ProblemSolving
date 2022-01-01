#include <iostream>
#include <vector>
using namespace std;

int arr[1025];
vector<int> v[10];

void BinarySearch(int start, int end, int depth) {
	if (start > end)	return;

	int mid = (start + end) / 2;
	v[depth].push_back(arr[mid]);
	BinarySearch(start, mid - 1, depth + 1);
	BinarySearch(mid+1, end, depth + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n;
	k = 1;
	for (int i = 0; i < n; i++)	k *= 2;
	k -= 1;
	for (int i = 0; i < k; i++)	cin >> arr[i];
	
	BinarySearch(0, k - 1, 0);

	for (int i = 0; i < n; i++) {
		for (int j : v[i])
			cout << j << " ";
		cout << "\n";
	}
	return 0;
}