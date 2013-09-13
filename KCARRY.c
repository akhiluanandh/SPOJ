/*
AUTHOR: Akhilesh Anandh
Solution for "Yet another electronic device" (www.spoj.com/problems/KCARRY)
Algorithm: DP
*/

#include<stdio.h>
typedef long long L;
L mod = 1000000007;
L ways[1001][1001][2];

int main(){
	ways[1][0][1] = 0;
	ways[1][0][0] = 55; 
	ways[1][1][1] = 45;
	ways[1][1][0] = 0;
	L t,n,i,j;
	for(i=2;i<=1000;i++){
		ways[i][0][1] = 0;
		ways[i][0][0] = (ways[i-1][0][0]*55)%mod;
		for(j=1;j<=i;j++){
			ways[i][j][1] = (ways[i-1][j-1][0]*45 + ways[i-1][j-1][1]*55)%mod;
			ways[i][j][0] = (ways[i-1][j][0]*55 + ways[i-1][j][1]*45)%mod;
		}
	}
	scanf("%lld",&t);
	while(t--){
		scanf("%lld %lld",&n,&i);
		printf("%lld\n",(ways[n][i][0] + ways[n][i][1])%mod);
	}
	return 0;
}
