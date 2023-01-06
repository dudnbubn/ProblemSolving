#pragma warning(disable : 4996)
#include<stdio.h>

int t = 7, i, m = 100, s;
int main() {	
	while (t--) {
		scanf("%d", &i);
		if (i % 2) {
			s += i;
			m = m < i ? m : i;
		}
	}
	if (m == 100)	printf("-1");
	else printf("%d\n%d", s, m);
}