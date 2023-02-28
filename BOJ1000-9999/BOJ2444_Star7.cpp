#pragma warning(disable : 4996)
#include <stdio.h>
int N,i,j;int main(){scanf("%d",&N);for(i=0;i<N;i++){for(j=1;j<N-i;j++)printf(" ");for(j=0;j<2*i+1;j++)printf("*");printf("\n");}for(i=N-2;i>=0;i--){for(j=1;j<N-i;j++)printf(" ");for(j=0;j<2*i+1;j++)printf("*");printf("\n");}}