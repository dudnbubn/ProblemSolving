#include <stdio.h>
char c[]={'D','C','B','A','E'};
main(){int x,a=0,i;for(i=1;i<13;i++){scanf("%d",&x);a+=x;if(i%4==0){printf("%c\n",c[a]);a=0;}}}