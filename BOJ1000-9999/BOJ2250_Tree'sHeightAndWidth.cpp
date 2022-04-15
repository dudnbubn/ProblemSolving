#include <iostream>
#include <algorithm>

using namespace std;

int n;
int maximum[10001];
int minimum[10001];

struct Node {
	int level;
	int column;
	int parent;
	int left;
	int right;
	Node() {
		this->level = 0;
		this->column = 0;
		this->parent = -1;
		this->left = 0;
		this->right = 0;
	}
};

Node nodeList[10001];
int column = 1;

void inOrder(int node) {
	if (nodeList[node].left != -1) {
		nodeList[nodeList[node].left].level = nodeList[node].level + 1;
		inOrder(nodeList[node].left);
	}
	nodeList[node].column = column;
	column++;
	if (nodeList[node].right != -1) {
		nodeList[nodeList[node].right].level = nodeList[node].level + 1;
		inOrder(nodeList[node].right);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i < 10001; i++)	minimum[i] = 987654321;

	int num, left, right;
	for (int i = 1; i <= n; i++) {
		cin >> num >> left >> right;
		nodeList[num].left = left;
		nodeList[num].right = right;
		nodeList[left].parent = num;
		nodeList[right].parent = num;
	}

	int p = 0;
	for (int i = 1; i <= n; i++)
		if (nodeList[i].parent == -1)
			p = i;
	nodeList[p].level = 1;
	inOrder(p);

	for (int i = 1; i <= n; i++) {
		maximum[nodeList[i].level] = max(maximum[nodeList[i].level], nodeList[i].column);
		minimum[nodeList[i].level] = min(minimum[nodeList[i].level], nodeList[i].column);
	}
	int result = 1, width = 0;
	for (int i = 1; i <= n; i++) {
		if (maximum[i] - minimum[i] > width) {
			result = i;
			width = maximum[i] - minimum[i];
		}
	}
	cout << result << " " << width + 1;
	return 0;
}