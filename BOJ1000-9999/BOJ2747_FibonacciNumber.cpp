#include<iostream>
using namespace std;int main(){int N,a=0,b=1;cin>>N;for(int i=1;i<N;i++)i%2?a+=b:b+=a;cout<<(N%2?b:a);}