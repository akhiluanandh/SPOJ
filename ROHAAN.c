/*
AUTHOR: Akhilesh Anandh
Solution for "Defend the Rohaan" (www.spoj.com/problems/ROHAAN)
Algorithm: Flloyd-Warshall
*/

#include<stdio.h>

int distances[51][51];

int min(int a, int b) {return a<b? a:b;}

void compute_min(int n){
	int i,j,k;
	for(k=0;k<n;k++){
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++){
				distances[i][j] = min(distances[i][j],distances[i][k]
													+distances[k][j]);
			}
		}
	}
}


int main(){
	int dist,total_dist;
	int n,a,b,r,i,j,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d",&n);
		for(r=0;r<n;r++)
			for(j=0;j<n;j++) scanf("%d",&(distances[r][j]));
		compute_min(n);
		scanf("%d",&r);
		dist = 0;
		while(r--){
			scanf("%d %d",&a,&b);
			dist += distances[a-1][b-1];
		}
		printf("Case #%d: %d\n",i,dist);
	}
	return 0;
}
