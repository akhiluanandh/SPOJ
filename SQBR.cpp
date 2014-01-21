/*
AUTHOR: Akhilesh Anandh
Solution for "Square Brackets" (www.spoj.com/problems/SQBR)
Algorithm: DP
*/

#include<stdio.h>
#include<string.h>

int dp[40][40], op[40];

int main(){
	int d,n,i,j,k,x;
	for(scanf("%d",&d);d--;)
	{
		scanf("%d %d",&n,&k);
		n<<=1;
		memset(dp,0,sizeof(dp));
		memset(op,0,sizeof(op));
		for(i=0;i<k;i++){
			scanf("%d",&x);
			op[x] = 1;
		}
		dp[1][1] = 1;
		for(i=2;i<=n;i++){
			if(!op[i]) dp[i][0] = dp[i-1][1];
			dp[i][n] = dp[i-1][n-1];
			for(j=1;j<n;j++){
				dp[i][j] = dp[i-1][j-1];
				if(!op[i]) dp[i][j] += dp[i-1][j+1];
			}
		}
		printf("%d\n",dp[n][0]);
	}
	return 0;
}
