#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Node {
	char alphabet;
	vector<Node*> nexts;
	bool is_end;
	Node(char alphabet) {
		this->alphabet = alphabet;
		this->is_end = false;
	}
};

string words[100000];

int get_index(Node* current, char alphabet) {
	for (int i = 0; i < current->nexts.size(); i++) {
		if (current->nexts[i]->alphabet == alphabet)
			return i;
	}
	return -1;
}

double get_score(Node* start, string word) {
	double result = 1;
	int index = get_index(start, word[0]);
	Node* current = start->nexts[index];

	int nexts_size;
	int word_size = word.size();
	for (int i = 1; i < word_size; i++) {
		nexts_size = current->nexts.size();
		index = get_index(current, word[i]);

		if (nexts_size == 1) {
			if (current->is_end) {
				result++;
			}
		}
		else {
			result++;
		}
		current = current->nexts[index];
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	int index;
	
	while (cin >> N) {
		Node* start = new Node('A');
		Node* current;
		
		for (int i = 0; i < N; i++) {
			cin >> words[i];
			index = get_index(start, words[i][0]);
			if (index == -1) {
				start->nexts.push_back(new Node(words[i][0]));
				index = start->nexts.size() - 1;
			}

			current = start->nexts[index];
			for (int j = 1; j < words[i].size(); j++) {
				index = get_index(current, words[i][j]);
				if (index == -1) {
					current->nexts.push_back(new Node(words[i][j]));
					index = current->nexts.size() - 1;
				}
				current = current->nexts[index];
			}
			current->is_end = true;
		}

		double result = 0;
		for (int i = 0; i < N; i++) {
			result += get_score(start, words[i]);
		}

		cout.precision(2);
		cout << fixed << round(result / N * 100) / 100 << "\n";
	}
}