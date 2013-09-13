/*
AUTHOR: Akhilesh Anandh
Solution for Minimum knight moves (www.spoj.com/problems/NAKANJ)
Algorithm: Floyd Warshall
*/

#include<stdio.h>

int dist[65][65];

int min(int x, int y) { return x<y?x:y;}

int main(){
	int i,j,k,a,b;
	char c1,c2;
	for(i=0;i<64;i++) for(j=0;j<64;j++) dist[i][j] = 32766;
	for(i=0;i<64;i++){
		dist[i][i] = 0;
		if(i/8<7&&(i%8)<6) dist[i][i+10] = dist[i+10][i] = 1;
		if(i/8<6&&(i%8)<7) dist[i][i+17] = dist[i+17][i] = 1;
		if(i/8<6&&(i%8)>0) dist[i][i+15] = dist[i+15][i] = 1;
		if(i/8<7&&(i%8)>1) dist[i][i+6] 	= dist[i+6][i]	 = 1;
	}
	for(k=0;k<64;k++)
		for(i=0;i<64;i++)
			for(j=0;j<64;j++) 
				dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);


	scanf("%d",&k);
	while(k--){
		do{
			c1 = getchar();
		}while(c1==' '||c1=='\n'||c1=='\r');
		scanf("%d",&a);
		do{
			c2 = getchar();
		}while(c2==' '||c2=='\n'||c2=='\r');
		scanf("%d",&b);
		//printf("%d\n",(a-1)*8+((int) c1 -'a'));
		printf("%d\n",dist[(a-1)*8+((int) c1 -'a')][(b-1)*8 +((int)c2 -'a')]);
	}
	return 0;
}

