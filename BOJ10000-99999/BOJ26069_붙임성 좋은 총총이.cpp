#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<string> us;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	us.insert("ChongChong");

	int N;
	cin >> N;

	string a, b;
	while (N--) {
		cin >> a >> b;
		if (us.find(a) != us.end())
			us.insert(b);
		else if (us.find(b) != us.end())
			us.insert(a);
	}

	cout << us.size();
}