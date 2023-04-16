#pragma warning(disable:4996)
#include <stdio.h>
int m, d,s;
int main() {
	scanf("%d%d", &m, &d);
	s = m * 100 + d;
	printf("%s",s == 218 ? "Special" : s < 218 ? "Before" : "After");
}