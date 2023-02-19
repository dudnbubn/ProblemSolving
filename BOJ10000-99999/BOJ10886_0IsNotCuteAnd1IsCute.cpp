#pragma warning(disable : 4996)
#include <stdio.h>

int N,n, a,b;
int main() {
	scanf("%d", &N);
	n = N;
	while (n--) {
		scanf("%d", &b);
		a += b;
	}
	printf("%s", a > N / 2 ? "Junhee is cute!" : "Junhee is not cute!");
}