#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int N;

struct Ball {
	int num;
	int color;
	int size;
	int sum;
	Ball() { 
		this->num = 0;
		this->color = 0;
		this->size = 0;
		this->sum = 0;
	}
};

Ball ball[200001];
int same_count[2001];
int result[200001];
map<pair<int, int>, int> m;

bool comp1(Ball a, Ball b) {
	if (a.size == b.size)
		return a.color < b.color;
	return a.size < b.size;
}

bool comp2(Ball a, Ball b) {
	return a.num < b.num;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	int color, size;
	for (int i = 1; i <= N; i++) {
		cin >> color >> size;
		ball[i].num = i;
		ball[i].color = color;
		ball[i].size = size;
	}
	
	sort(ball + 1, ball + N + 1, comp1);
	
	for (int i = 1; i <= N; i++) {
		result[0] += ball[i].size;
		result[ball[i].color] += ball[i].size;
		same_count[ball[i].size]++;
		if (m.find({ ball[i].color, ball[i].size }) == m.end()) 
			m[{ball[i].color, ball[i].size}] = 1;
		else
			m[{ball[i].color, ball[i].size}]++;

		ball[i].sum = result[0] - result[ball[i].color] - (same_count[ball[i].size] - m[{ball[i].color, ball[i].size}])* ball[i].size;
	}
	
	sort(ball + 1, ball + N + 1, comp2);

	for (int i = 1; i <= N; i++)
		cout << ball[i].sum << "\n";

	return 0;
}