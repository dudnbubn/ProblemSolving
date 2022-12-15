#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 체스판에서 검은 칸에 위치한 비숍은 어떠한 흰 칸에도 영향을 끼칠 수 없다. 따라서 고려할 필요가 없다.
// 그러므로 비숍이 위치할 수 있는 자리를 검은 칸과 흰 칸으로 나누어 계산한다. 검은 칸은 좌표의 합이 홀수, 흰 칸은 좌표의 합이 짝수.

vector<pair<int, int>> odd_list, even_list;	// 합이 홀수인 자리와 짝수인 자리를 저장할 리스트
bool ascending[19];		// 우상향 대각선상 비숍 존재 여부
bool descending[19];	// 좌상향 대각선상 비숍 존재 여부
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