#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ü���ǿ��� ���� ĭ�� ��ġ�� ����� ��� �� ĭ���� ������ ��ĥ �� ����. ���� ����� �ʿ䰡 ����.
// �׷��Ƿ� ����� ��ġ�� �� �ִ� �ڸ��� ���� ĭ�� �� ĭ���� ������ ����Ѵ�. ���� ĭ�� ��ǥ�� ���� Ȧ��, �� ĭ�� ��ǥ�� ���� ¦��.

vector<pair<int, int>> odd_list, even_list;	// ���� Ȧ���� �ڸ��� ¦���� �ڸ��� ������ ����Ʈ
bool ascending[19];		// ����� �밢���� ��� ���� ����
bool descending[19];	// �»��� �밢���� ��� ���� ����
int odd_result, even_result;

void play(int index, int number_of_bishop, bool is_odd) {
	int asc, desc;
	if (is_odd) {
		if (index == odd_list.size()) {
			odd_result = odd_result > number_of_bishop ? odd_result : number_of_bishop;
			return;
		}
		asc = odd_list[index].first;
		desc = odd_list[index].second;
	}
	else {
		if (index == even_list.size()) {
			even_result = even_result > number_of_bishop ? even_result : number_of_bishop;
			return;
		}
		asc = even_list[index].first;
		desc = even_list[index].second;
	}


	play(index + 1, number_of_bishop, is_odd);
	if (!ascending[asc] && !descending[desc]) {
		ascending[asc] = true;
		descending[desc] = true;

		play(index + 1, number_of_bishop + 1, is_odd);

		ascending[asc] = false;
		descending[desc] = false;
	}
}


int main() {
	int N, input;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input;
			if (input) {
				if ((i + j) % 2) odd_list.push_back({ i - j + 9, i + j });
				else even_list.push_back({ i - j + 9, i + j });
			}
		}
	}
			

	play(0, 0, true);
	play(0, 0, false);
	cout << odd_result + even_result;

	return 0;
}