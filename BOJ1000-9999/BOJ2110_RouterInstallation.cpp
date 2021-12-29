#include <iostream>
#include <algorithm>
using namespace std;

int n, m, answer;
int arr[200001];

bool check(int length) {
	int router = 1;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (router <= arr[i]) {
			router = arr[i] + length;
			cnt++;
		}
		if (cnt == m)
			return true;
	}
	return false;
}

int solution(int left, int right) {
	int middle;
	if (left == right)
		return left;
	if (left + 1 == right) {
		if (check(right))
			return right;
		else
			return left;
	}
	middle = (left + right) / 2;
	if (check(middle))
		return solution(middle, right);
	else
		return solution(left, middle - 1);
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)	cin >> arr[i];
	sort(arr + 1, arr + n + 1);
	answer = solution(1, arr[n] - 1);
	cout << answer;
	return 0;
}