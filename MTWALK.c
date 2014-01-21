/*
AUTHOR: Akhilesh Anandh
Solution for "Mountain Walking" (www.spoj.com/problems/MTWALK)
Algorithm: DFS + Binary Search
*/

#include<stdio.h>
int p,h[100][100],reached[100][100];
#define abs(a) a>0? a:(0-a);

void dfs(int y, int x,int n, int min, int max){
	if(p) return;

	reached[y][x] = 1;

	if(y==n-1 && x==n-1){
		p=1;
		return;
	}

	if(x>0 && !reached[y][x-1] && h[y][x-1]>=min && h[y][x-1]<=max){
		dfs(y,x-1,n,min,max);
		if(p) return;
	}
	if(x<n-1 && !reached[y][x+1] && h[y][x+1]>=min && h[y][x+1]<=max){
		dfs(y,x+1,n,min,max);
		if(p) return;
	}
	if(y>0 && !reached[y-1][x] && h[y-1][x]>=min && h[y-1][x]<=max){
		dfs(y-1,x,n,min,max);
		if(p) return;
	}
	if(y<n-1 && !reached[y+1][x] && h[y+1][x]>=min && h[y+1][x]<=max){
		dfs(y+1,x,n,min,max);
		if(p) return;
	}

}

int possible(int d,int n,int min){
	int i,j,k;
	p = 0;
	for(k=0;k<=min && !p ;k++){
		for(i=0;i<n;i++) for(j=0;j<n;j++) reached[i][j] = 0;
		dfs(0,0,n,k,k+d);
		if(p) return 1;
	}
	return p;
}

int main(){
	int n,d,lo,hi,mid,min,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%d",h[i]+j);
	hi = 110;
	lo = abs(h[0][0]-h[n-1][n-1]);
	min = h[0][0]<h[n-1][n-1]? h[0][0]:h[n-1][n-1];
	while(lo<=hi){
		mid = (lo+hi)/2;
		if(possible(mid,n,min))	hi = mid-1;
		else lo = mid + 1;
	}
	printf("%d\n",++hi);
	return 0;
}
