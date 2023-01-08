#pragma warning(disable:4996)
#include<stdio.h>
int t = 4, o, i, s, m;
int main() {
	while (t--) {
		scanf("%d%d", &o, &i);
		s += i - o;
		m = m > s ? m : s;
	}
	printf("%d",m);
}