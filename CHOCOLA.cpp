/*
AUTHOR: Akhilesh Anandh
Solution for "Chocolate" (www.spoj.com/problems/CHOCOLA)
Alorithm: DP
*/

#include<cstdio>
#include<algorithm>
using namespace std;

#define min(a,b) (((a)<(b))?(a):(b))
typedef long long LL;
bool comp(LL a, LL b){ return a>b;}

LL x[1001],y[1001],dp[1001][1001];

int main(){
	LL i,j,m,n,t;
	for(scanf("%lld",&t);t--;){
		scanf("%lld %lld",&m,&n);
		m--;
		n--;
		for(i=1;i<=m;i++)
			scanf("%lld",x+i);
		for(i=1;i<=n;i++)
			scanf("%lld",y+i);
		sort(x+1,x+1+m,comp);
		sort(y+1,y+n+1,comp);
		dp[0][0] = 0;
		for(i=1;i<=m;i++) dp[i][0] = x[i] + dp[i-1][0];
		for(i=1;i<=n;i++) dp[0][i] = y[i] + dp[0][i-1];
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				LL t1 = dp[i-1][j] + x[i]*(j+1);
				LL t2 = dp[i][j-1] + y[j]*(i+1);
				dp[i][j] = min(t1,t2);
			}
		}
		printf("%lld\n",dp[m][n]);
	}
	return 0;
}
