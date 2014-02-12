/*
AUTHOR: Akhilesh Anandh
Solution for "Blueberries" (www.spoj.com/problems/RPLB)
Algorithm: DP
*/

#include<cstdio>

int max,k,n;
bool done[1001][1001];
int val[1000];

void solve(int i, int acc){
	if(acc>k) return;
	if(acc>max) max = acc;
	done[i][acc] = true;
	if(i<n-1 && !done[i+1][acc]) solve(i+1,acc);
	acc+=val[i];
	if(acc>k) return;
	if(acc>max) max = acc;
	if(i<n-2 && !done[i+2][acc]) solve(i+2,acc);
}

int main(){
	int t,i,j,c;
	for(scanf("%d",&t),c=1;c<=t;c++){
		max = 0;
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++){
			for(j=0;j<=k;j++) done[i][j] = false;
			scanf("%d",val+i);
		}
		solve(0,0);
		printf("Scenario #%d: %d\n",c,max);
	}
	return 0;
}

