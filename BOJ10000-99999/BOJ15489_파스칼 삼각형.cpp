#include <iostream>

using namespace std;

int arr[31][31];
		
int main(){
	int R,C,W;
	cin >> R>>C>>W;
	
	arr[1][1] = arr[2][1] = arr[2][2] = 1;
	for(int i=3;i<=30;i++) {
		for(int j=1;j<=i;j++) {
			arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
		}
	}
	
	int result = 0;
	for(int w=1;w<=W;w++) {
		for(int c=0;c<w;c++) {
			result += arr[R+w-1][C+c];
		}
	}
	cout << result << "\n";
	
	return 0;
}
