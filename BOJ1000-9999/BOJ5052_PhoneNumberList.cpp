#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 10'000

struct Node {
	char number;
	bool is_end;
	Node* nexts[10];
	Node(char number) {
		this->number = number;
		this->is_end = false;
		for (int i = 0; i < 10; i++)
			this->nexts[i] = nullptr;
	}
};

string numbers[MAX_N];
Node* starts[10];

bool check(string s) {
	int index = s[0] - '0';
	if (starts[index] == nullptr)	starts[index] = new Node(s[0]);

	Node* current = starts[index];
	if (current->is_end)	return false;
	int s_size = s.size();
	for (int i = 1; i < s_size; i++) {
		index = s[i] - '0';
		if (current->nexts[index] == nullptr)	current->nexts[index] = new Node(s[i]);
		current = current->nexts[index];
		if (current->is_end)	return false;
	}
	current->is_end = true;

	return true;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int TC;
	cin >> TC;

	int N;
	while (TC--) {
		cin >> N;
		for (int i = 0; i < 10; i++)	starts[i] = nullptr;

		for (int i = 0; i < N; i++)	cin >> numbers[i];
		sort(numbers, numbers + N);
		
		bool result = true;
		for (int i = 0; i < N; i++) {
			result &= check(numbers[i]);
		}
		
		if (result)	cout << "YES\n";
		else	cout << "NO\n";
	}
	return 0;
}