//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int dwarfs[9];
//bool isUsed[9] = { 0, };
//vector<int> answer;
//
//void DFS(int k, int sum) {
//	if (k == 7) {
//		if (sum != 100)
//			return;
//		for (int i = 0; i < 7; i++)
//			cout << answer[i] << "\n";
//		exit(0);
//	}
//	for (int i = 0; i < 9; i++) {
//		if (!isUsed[i]) {
//			isUsed[i] = true;
//			answer.push_back(dwarfs[i]);
//			DFS(k + 1, sum + dwarfs[i]);
//			answer.erase(answer.begin() + k);
//			isUsed[i] = false;
//		}
//	}
//}
//
//int main() {
//	for (int i = 0; i < 9; i++)
//		cin >> dwarfs[i];
//	sort(dwarfs, dwarfs + 9);
//	DFS(0, 0);
//	return 0;
//}