#include<iostream>
using namespace std;
int a[201];main(){int N,x;cin>>N;while(N--){cin>>x;a[x+100]++;}cin>>x;cout<<a[x+100];}