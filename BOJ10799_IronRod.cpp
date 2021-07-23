//#include <iostream>
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	string input;
//	cin >> input;
//	int cnt = 0;
//	int rod = 0;
//	for (int i = 0; i < input.size(); i++) {
//		// '(' 일 때 다음 괄호가 ')' 이면 레이저, 아니면 쇠막대기
//		if (input[i] == '(') {
//			if (input[i + 1] == ')') {
//				cnt += rod;
//				i++;
//			}
//			else
//				rod++;
//		}
//		// ')' 일 때 쇠막대기 끝. 레이저의 닫는 괄호는 17행에서 처리
//		else {
//			cnt++;
//			rod--;
//		}
//	}
//	cout << cnt;
//
//	return 0;
//}