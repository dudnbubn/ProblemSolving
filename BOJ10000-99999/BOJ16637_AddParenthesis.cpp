#include <iostream>
#include <queue>

using namespace std;

int N, result = -2147483648;
int numbers[11];
char opers[11];
bool visited[11];

int calc(int a, int b, char oper) {
	switch (oper) {
	case '+':	return a + b;
	case '-':	return a - b;
	case '*':	return a * b;
	}
}

void subs(int depth) {
	if (depth == N / 2) {
		queue<int> num_q;
		queue<char> op_q;

		op_q.push(opers[0]);

		for (int i = 1; i < N / 2; i++) {
			if (visited[i])
				num_q.push(calc(numbers[i], numbers[i + 1], opers[i]));
			else if (visited[i - 1])
				op_q.push(opers[i]);
			else {
				num_q.push(numbers[i]);
				op_q.push(opers[i]);
			}
		}

		num_q.push(numbers[N / 2]);

		int res = numbers[0];
		while (!op_q.empty()) {
			res = calc(res, num_q.front(), op_q.front());
			num_q.pop();
			op_q.pop();
		}
		result = result > res ? result : res;
		return;
	}

	if (!visited[depth - 1]) {
		visited[depth] = true;
		subs(depth + 1);
	}
	visited[depth] = false;
	subs(depth + 1);
}

int main() {
	cin >> N;

	string s;
	cin >> s;
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0)	numbers[i / 2] = s[i] - '0';
		else	opers[i / 2] = s[i];
	}

	if (N == 1)	cout << numbers[0];
	else {
		subs(1);
		cout << result;
	}

	return 0;
}