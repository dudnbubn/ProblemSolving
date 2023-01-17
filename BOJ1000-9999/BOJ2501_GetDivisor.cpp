#pragma warning(disable:4996)
#include<stdio.h>

int N, K,q;
int main() {
	scanf("%d%d", &N, &K);
	while (K && ++q <= N) {
		if (N % q)	continue;
		K--;
	}
	printf("%d", K ? 0 : q);
}