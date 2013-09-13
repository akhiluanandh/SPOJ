/*
AUTHOR: Akhilesh Anandh
Solution for MPILOT (www.spoj.com/problems/MPILOT)
Algorithm: DP
*/

#include<stdio.h>
#define gc getchar_unlocked
#define min(a,b) a<b? a:b;

int x[10001],y[10001],sum_x[10001],cost[2][10001];

int get_int(){
	int x = 0;
	register int c = gc();
	while(c<48||c>57) c = gc();
	x = c - 48;
	c = gc();
	while(c>=48 && c<=57){
		x = x*10 + c-48;
		c = gc();
	}
	return x;
}

int main(){
	int n = get_int(),i,j;
	sum_x[0] = (x[0] = get_int());
	y[0] = get_int();
	for(i=1;i<n;i++){
		x[i] = get_int();
		y[i] = get_int();
		//scanf("%d %d",x+i,y+i);
		sum_x[i] = sum_x[i-1] + x[i];
	}
	cost[0][0] = 0;
	for(i=1;i<=n;i++){
		cost[i&1][i] = sum_x[n-1] - sum_x[n-i-1];
		cost[i&1][0] = cost[!(i&1)][1] + y[n-i];
		for(j=1;j<i;j++){
			cost[i&1][j] = min(cost[!(i&1)][j+1]+y[n-i],cost[!(i&1)][j-1]+x[n-i]);
		}
	}

	printf("%d\n",cost[n&1][0]);
	return 0;
}
