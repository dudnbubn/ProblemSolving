#include <stdio.h>
int N,r;int m[6]={500,100,50,10,5,1};int main(){scanf("%d",&N);N=1000-N;for(int i:m){r+=N/i;N%=i;}printf("%d",r);}