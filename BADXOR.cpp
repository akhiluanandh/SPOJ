/*
AUTHOR: Akhilesh Anandh
Solution for "Bad XOR" (www.spoj.com/problems/BADXOR)
Algorithm: DP
*/

#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <string.h> 
using namespace std;

#define EPS 0.0000001

typedef long long LL;

#define gc getchar_unlocked

int read_int(){
	register int x = 0, c = gc();
	int sign = 1;
	while(c!='-' && (c<48 || c>57) ) c = gc();
	if(c=='-')
		sign = -1, c = gc();
	while(c>=48 && c<=57) 
		x = (x<<1) + (x<<3) + c - 48, c = gc();
	return sign*x;
}

int dp[1025][1025];
//dp[i][j] -> ways to get xor value of j, using 
// first i elements of the array A

int A[1025], B[1025];
bool inB[1025];

#define mod 100000007

int main()
{
	int t,n,m,i,j,c=1;
	for(t=read_int();c<=t;c++){
		n = read_int();
		m = read_int();
		for(i=0;i<n;i++)
			A[i] = read_int();
		memset(inB,0,sizeof(inB));
		for(j=0;j<m;j++){
			B[j] = read_int();
			inB[B[j]] = true;
		}
		memset(dp,0,sizeof(dp));
		dp[0][0] = 1;
		for(i=1;i<=n;i++){
			int a = A[i-1];
			for(j=0;j<1024;j++){
				dp[i][j] = dp[i-1][j] + dp[i-1][j^a];
				if(dp[i][j]>=mod)
					dp[i][j] -= mod;
			}
		}
		int ans = 0;
		for(j=0;j<1024;j++){
			if(!inB[j]){
				ans += dp[n][j];
				if(ans>=mod) ans -= mod;
			}
		}
		printf("Case %d: %d\n",c,ans);
	}
	return 0;
}
