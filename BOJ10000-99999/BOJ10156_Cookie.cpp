#pragma warning (disable:4996)
#include <ios>
int k,n,m;int main(){scanf("%d%d%d",&k,&n,&m);k=k*n-m;
	printf("%d", k > 0 ? k : 0);
}