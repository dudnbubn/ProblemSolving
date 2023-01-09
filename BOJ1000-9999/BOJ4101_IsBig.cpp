#pragma warning (disable:4996)
#include<stdio.h>
int a,b;
int main() {
	scanf("%d%d", &a, &b);
	while (a) {
		printf(a > b ? "Yes\n" : "No\n");
		scanf("%d%d", &a, &b);
	}
}