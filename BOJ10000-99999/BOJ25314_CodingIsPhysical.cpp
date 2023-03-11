#pragma warning(disable :4996)
#include <stdio.h>

int N,i;

int main() {
	scanf("%d", &N);
	for (i = 0; i < N / 4; i++)
		printf("long ");
	printf("int");
}