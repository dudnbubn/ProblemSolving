// 배열 A와 B를 정렬한 후 맨 앞 숫자를 비교하여 작은 값을 정답 배열에 하나씩 넣는다.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int A[1000001], B[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)	cin >> A[i];
	for (int i = 0; i < m; i++)	cin >> B[i];
	
	sort(A, A + n);
	sort(B, B + m);
	vector<int> answer;
	int index_A = 0, index_B = 0;
	while ((index_A != n) || (index_B != m)) {
		if (index_A == n) {
			answer.push_back(B[index_B]);
			index_B++;
		}
		else if (index_B == m) {
			answer.push_back(A[index_A]);
			index_A++;
		}
		else {
			if (A[index_A] <= B[index_B]) {
				answer.push_back(A[index_A]);
				index_A++;
			}
			else {
				answer.push_back(B[index_B]);
				index_B++;
			}
		}
	}
	for (int i : answer)
		cout << i << " ";
	return 0;
}