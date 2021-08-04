//// 카드 i 개를 구매할때의 값을 입력값과 비교하여 최댓값으로 설정해준다.
//// ex) arr[1] = 5, arr[2] = 2 라고 입력이 들어오면 arr[1]+arr[1](= 10) 과 arr[2] 를 비교하여 최댓값으로 업데이트한다.
////		-> arr[2] = arr[1]+arr[1] = 10, arr[3] = 8 로 입력이 들어오면 arr[1]+arr[2](= 15) 와 값을 비교하여 최댓값으로 업데이트한다.
////		-> arr[3] = arr[1]+arr[2] = 15, arr[4] = 16 으로 입력이 들어오면 arr[1]+arr[3](= 20), arr[2]+arr[2](= 20) 와 값을 비교하여 최댓값으로 업데이트한다.
////		-> arr[4] = arr[1]+arr[3] = arr[2]+arr[2] = 20
//#include <iostream>
//using namespace std;
//
//int arr[1001] = { 0, };
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) 
//		cin >> arr[i];
//	for (int i = 2; i <= n; i++) {
//		for (int j = 1; j <= i / 2; j++) {
//			if (arr[i] < (arr[j] + arr[i - j]))
//				arr[i] = arr[j] + arr[i - j];
//		}
//	}
//	cout << arr[n];
//
//	return 0;
//}