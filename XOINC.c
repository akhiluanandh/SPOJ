/*
AUTHOR: Akhilesh Anandh
Solution for "A coin Game" (www.spoj.com/problems/XOINC)
Algorithm: DP
*/

#include<stdio.h>

typedef long long LL;

LL values[2001];
LL sum[2001];
LL max[2001][2001];

/*
max[i][j] -> the maximum score a player can get by picking up upto j coins
when i coins are left. 
*/

LL max_2(LL a, LL b) { return a>b? a:b; }
LL min_2(LL a, LL b) { return a<b? a:b; }

int main(){
	LL n,i,j,temp;
	scanf("%lld",&n);
	values[0] = sum[0] = 0;
	for(i=0;i<n;i++)
		scanf("%lld",values+n-i);
	for(i=1;i<=n;i++){
		sum[i] = sum[i-1] + values[i];
	}
	max[1][1] = values[1];
	for(i=2;i<=n;i++){
		max[i][1] = values[i] + sum[i-1] - max[i-1][min_2(i-1,2)];
		max[i][i] = sum[i];
		for(j=2;j<i;j++){
			temp = sum[i-j] - max[i-j][min_2(i-j,2*j)] + sum[i] - sum[i-j];
			max[i][j] = max_2(max[i][j-1],temp);
		}
	}
	printf("%lld",max[n][2]);
	return 0;
}
