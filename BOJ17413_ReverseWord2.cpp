//#include <iostream>
//#include <string>
//#include <stack>
//
//std::stack<char> stk;
//std::string s, answer = "";
//
//// ���ÿ� ������ �ܾ� ������
//void emptyStack() {
//	while (!stk.empty()) {
//		answer += stk.top();
//		stk.pop();
//	}
//}
//
//int main() {
//	bool toStack = true;
//	getline(std::cin, s);
//	for (int i = 0; i < s.size(); i++) {
//		// ������ �������� �ܾ �����Ƿ�, ������ �� ���ÿ� ������ �ܾ� ������
//		if (s[i] == ' ') {
//			emptyStack();
//			answer += ' ';
//		}
//		else if (s[i] == '<') {
//			// �±״� �ܾ �ƴϹǷ� ������ �ʴ´�.
//			emptyStack();
//			answer += s[i];
//			toStack = false;
//		}
//		else if (s[i] == '>') {
//			answer += s[i];
//			toStack = true;
//		}
//		else {
//			// toStack = true : �ܾ��̹Ƿ� ���������, toStack = false : �±��̹Ƿ� ������ ����
//			if (toStack)
//				stk.push(s[i]);
//			else
//				answer += s[i];
//		}
//	}
//	// ���ÿ� ����Ǿ��ִ� �ܾ ������ ������
//	emptyStack();
//
//	std::cout << answer;
//
//	return 0;
//}