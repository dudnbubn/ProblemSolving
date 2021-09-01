// ���������� ���������� BFS�� ���鼭 �� ���� �� ��° �̵��� ������ �����Ѵ�.(visited)
// BFS�� �� ���� ���������� ���������� �̵�Ƚ���� ���̸鼭 ������ ��θ� �����Ѵ�.

#include <iostream>
#include <queue>
#include <string>
#include <stack>
using namespace std;

int n, k;
int sec = 0;
int visited[200001];
bool flag = false;

int main() {
	cin >> n >> k;
	if (n == k) {
		cout << sec << "\n";
		cout << n;
		return 0;
	}
	for (int i = 0; i <= 100000; i++)
		visited[i] = -1;
	queue<int> q;
	q.push(n);
	visited[n] = 0;
	while (!q.empty()) {
		sec++;
		int qsz = q.size();
		for (int i = 0; i < qsz; i++) {
			int cur = q.front();
			q.pop();
			for (int j = 0; j < 3; j++) {
				int next;
				if (j == 0)	next = cur - 1;
				else if (j == 1)	next = cur + 1;
				else if (j == 2)	next = cur * 2;

				if (next < 0 || next > 200000)
					continue;
				
				if (next == k) {
					visited[next] = sec;
					flag = true;
					break;
				}
				if (visited[next] == -1) {
					visited[next] = sec;
					q.push(next);
				}
			}
			if (flag)	break;
		}
		if (flag)	break;
	}
	stack<int> answer;
	answer.push(k);
	while (sec--) {
		if (visited[k + 1] == sec) {
			k += 1;
			answer.push(k);
		}
		else if (k > 0 && visited[k - 1] == sec) {
			k -= 1;
			answer.push(k);
		}
		else if (visited[k / 2] == sec) {
			k /= 2;
			answer.push(k);
		}
	}
	cout << answer.size() - 1 << "\n";
	while (!answer.empty()) {
		cout << answer.top() << " ";
		answer.pop();
	}
	
	return 0;
}