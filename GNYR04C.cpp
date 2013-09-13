/*
AUTHOR: Akhilesh Anandh
Solution for "Lenny Lucky Lotto Lists" (www.spoj.com/GNYR04C)
Algorithm: DP
*/

#include<cstdio>
long long ways[10][2000];
int main(){
	int t,i,j,n,m,d;
	for(j=1;j<=2000;j++) ways[0][j-1] = j;
	for(i=2;i<=10;i++){
		ways[i-1][0] = 0;
		for(j=2;j<=2000;j++) ways[i-1][j-1] = ways[i-2][j/2-1]+ways[i-1][j-2];
	}
	for(scanf("%d",&t),d=1;d<=t;d++){
		scanf("%d %d",&n,&m);
		printf("Data set %d: %d %d %lld\n",d,n,m,ways[n-1][m-1]);
	}
	return 0;
}
