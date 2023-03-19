#pragma warning(disable:4996)
#include<stdio.h>
int t, a,i=9;
int main() {
	scanf("%d", &t);
	while (i--) {
		scanf("%d", &a);
		t -= a;
	}
	printf("%d",t);
}