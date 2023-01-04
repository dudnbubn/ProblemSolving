#include <iostream>
#include <set>

using namespace std;

int N;
int candy_count[1000001];
set<int> box;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	int A, B, C;
	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		if (A == 1) {
			for (int candy : box) {
				if (candy_count[candy] >= B) {
					cout << candy << "\n";
					candy_count[candy]--;
					if (candy_count[candy] == 0)
						box.erase(candy);
					break;
				}
				B -= candy_count[candy];
			}
		}
		else {
			cin >> C;
			if (candy_count[B] == 0)	box.insert(B);
			candy_count[B] += C;
			if (candy_count[B] == 0)	box.erase(B);
		}
	}
	return 0;
}