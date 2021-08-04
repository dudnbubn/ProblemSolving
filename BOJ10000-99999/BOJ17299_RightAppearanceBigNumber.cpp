//#include <iostream>
//#include <stack>
//using namespace std;
//
//int A[1000001];
//int appear[1000001] = { 0, };
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int n;
//	stack<int> stk;	// A[i]의 오른쪽 숫자를 저장
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> A[i];
//		appear[A[i]]++;
//	}
//
//	for (int i = n - 1; i >= 0; i--) {
//		if (stk.empty()) {
//			stk.push(A[i]);
//			A[i] = -1;
//		}
//		else {
//			// A[i] 오른쪽의 등장횟수가 A[i] 보다 큰 경우
//			if (appear[stk.top()] > appear[A[i]]) {
//				int temp = stk.top();
//				stk.push(A[i]);
//				A[i] = temp;
//			}
//			else {
//				// A[i] 오른쪽의 등장횟수가 A[i] 보다 작은 경우 스택을 비우면서 찾음
//				while ((!stk.empty()) && (appear[stk.top()] <= appear[A[i]]))
//					stk.pop();
//				// A[i] 보다 등장횟수가 큰 수가 없으므로 A[i] = -1
//				if (stk.empty()) {
//					stk.push(A[i]);
//					A[i] = -1;
//				}
//				// A[i] 보다 등장횟수가 큰 수를 A[i]에 넣음
//				else {
//					int temp = stk.top();
//					stk.push(A[i]);
//					A[i] = temp;
//				}
//			}
//		}
//	}
//	for (int i = 0; i < n; i++)
//		cout << A[i] << " ";
//
//	return 0;
//}