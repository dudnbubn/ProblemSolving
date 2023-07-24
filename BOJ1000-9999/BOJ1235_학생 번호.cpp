#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

unordered_set<string> us;
string arr[1000];

int main(){
	int N;
	cin >> N;
	for(int n=0;n<N;n++)	cin >> arr[n];
	
	int s_size = arr[0].size();
	int result = 0;
	for(int size=1;size<=s_size;size++) {
		us = {};
		for(int n=0;n<N;n++) {
			us.insert(arr[n].substr(s_size-size));
		}
		
		if(us.size() == N) {
			result = size;
			break;
		}
	}
	cout << result;
	return 0;
}
