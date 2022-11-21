#include <iostream>
using namespace std;int m[12]={0,31,28,31,30,31,30,31,31,30,31,30};string s[7]={"SUN","MON","TUE","WED","THU","FRI","SAT"};int main(){int x,y;cin>>x>>y;while(--x)y+=m[x];cout<<s[y%7];}
