#include <iostream>
#include <set>
#include <queue>
#include <cmath>
using namespace std;

bool isPrime[10000];
bool visited[10000];

void Eratos() {
	for (int i = 2; i < 10000; i++)
		isPrime[i] = true;

	for (int i = 2; i < 10000; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j < 10000; j += i) {
				isPrime[j] = false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Eratos();
	set<int> s;
	for (int i = 1000; i < 10000; i++) {
		if (isPrime[i])
			s.insert(i);
	}
	
	int T;
	cin >> T;
	queue<int> q;
	for (int t = 1; t <= T; t++) {
		while (!q.empty())	q.pop();
		for (int i = 1000; i < 10000; i++)	visited[i] = false;
		int start, end;
		cin >> start >> end;
		
		int result = -1;
		int qsz, cur, next, nnext, div;
		bool flag = true;
		q.push(start);
		visited[start] = true;
		while (!q.empty()) {
			result++;
			qsz = q.size();
			for (int i = 0; i < qsz; i++) {
				div = 1000;
				cur = q.front();
				q.pop();
				if (cur == end) {
					cout << result << "\n";
					flag = false;
					break;
				}
				for (int j = 0; j < 4; j++) {
					next = (cur / (div * 10)) * (div * 10) + (cur % div);
					
					for (int k = 0; k < 10; k++) {
						nnext = next + k * div;
						
						if (nnext < 1000 || nnext >= 10000)
							continue;

						if (!visited[nnext] && s.find(nnext) != s.end()) {
							visited[nnext] = true;
							q.push(nnext);
						}
					}
					div /= 10;
				}
			}
		}
		if(flag)
			cout << "Impossible\n";
	}
	return 0;
}