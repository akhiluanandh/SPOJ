/*
AUTHOR: Akhilesh Anandh
Solution for "Trip to London" (www.spoj.com/problems/DCEPC803)
Algorithm: Floyd Warshall
*/

#include<cstdio>
#include<algorithm>
using namespace std;

#define INF 100000000

int dir[21][21], sh[21][21], fw[21][21];

int main(){
	int n,i,j,mi,mj,k;
	for(i=0,scanf("%d",&n);i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",dir[i]+j);
			if(dir[i][j]==-1)
				dir[i][j] = INF, mi = i, mj = j;
			fw[i][j] = dir[i][j];
		}
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",sh[i]+j);
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				fw[i][j] = min(fw[i][j],fw[i][k]+fw[k][j]);
	int min_val = 0,max_val = 100,poss=1;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j) continue;
			if(fw[i][j]==sh[i][j]){
				int m = sh[i][j] - sh[i][mi] - sh[mj][j];
				if(m>max_val) poss = 0;
				min_val = max(m,min_val);
			}
			else{
				int m = sh[i][j] - sh[i][mi] - sh[mj][j];
				if(m<min_val || m>max_val) poss = 0;
				min_val = max_val = m;
			}
		}
	}
	if(min_val>max_val) poss = 0;
	printf("%d",(max_val-min_val+1)*poss);
	return 0;
}
