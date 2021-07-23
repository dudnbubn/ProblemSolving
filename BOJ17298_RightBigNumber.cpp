//#include <iostream>
//#include <stack>
//using namespace std;
//
//int A[1000000];
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int n;
//	stack<int> stk;
//	cin >> n;
//	for (int i = 0; i < n; i++)	
//		cin >> A[i];
//
//	// 배열의 뒤부터 루프를 돔. 스택에는 A[i]보다 오른쪽에 있는 수가 저장됨
//	for (int i = n - 1; i >= 0; i--) {
//		// 스택이 비어있으면 오른쪽에 큰 수가 없으므로 -1
//		if (stk.empty()) {
//			stk.push(A[i]);
//			A[i] = -1;
//		}
//		else {
//			// A[i]의 오른쪽에 있으면서 A[i]보다 큰 수 중에서 가장 왼쪽에 있는 수
//			if (stk.top() > A[i]) {
//				int temp = stk.top();
//				stk.push(A[i]);
//				A[i] = temp;
//			}
//			else {
//				// A[i]보다 작은 수는 없애버림
//				while ((!stk.empty()) && (stk.top() <= A[i]))
//					stk.pop();
//				// 스택이 비어있으면 오른쪽에 큰 수가 없으므로 -1
//				if (stk.empty()) {
//					stk.push(A[i]);
//					A[i] = -1;
//				}
//				// A[i]보다 작은 값은 지웠으므로 남은 값은 
//				// A[i]의 오른쪽에 있으면서 A[i]보다 큰 수 중에서 가장 왼쪽에 있는 수
//				else {
//					int temp = stk.top();
//					stk.push(A[i]);
//					A[i] = temp;
//				}
//			}
//		}
//	}
//	
//	for (int i = 0; i < n; i++)
//		cout << A[i] << " ";
//
//	return 0;
//}