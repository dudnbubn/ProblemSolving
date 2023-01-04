#include <stdio.h>
int a[]={300,60,10};main(){int T,i;scanf("%d",&T);if(T%10)printf("-1");else for(i=0;i<3;i++){printf("%d ",T/a[i]);T%=a[i];}}