//#include <iostream>
//#include <string>
//#include <stack>
//
//std::stack<char> stk;
//std::string s, answer = "";
//
//// 스택에 저장한 단어 뒤집기
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
//		// 공백을 기준으로 단어가 나뉘므로, 공백일 때 스택에 저장한 단어 뒤집기
//		if (s[i] == ' ') {
//			emptyStack();
//			answer += ' ';
//		}
//		else if (s[i] == '<') {
//			// 태그는 단어가 아니므로 뒤집지 않는다.
//			emptyStack();
//			answer += s[i];
//			toStack = false;
//		}
//		else if (s[i] == '>') {
//			answer += s[i];
//			toStack = true;
//		}
//		else {
//			// toStack = true : 단어이므로 뒤집어야함, toStack = false : 태그이므로 뒤집지 않음
//			if (toStack)
//				stk.push(s[i]);
//			else
//				answer += s[i];
//		}
//	}
//	// 스택에 저장되어있는 단어가 있으면 뒤집기
//	emptyStack();
//
//	std::cout << answer;
//
//	return 0;
//}