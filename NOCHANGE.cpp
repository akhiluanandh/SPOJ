/*
AUTHOR: Akhilesh Anandh
Solution for "No Change" (www.spoj.com/problems/NOCHANGE)
Algorithm: DP
*/

#include<cstdio>
using namespace std;
int vals[5];
int possible[100001];
int w[100001][5][5];

int main(){
	int x,k,i,j,p,l,m;
	scanf("%d",&x);
	scanf("%d",&k);
	for(i=0;i<k;i++) scanf("%d",vals+i);
	possible[0] = 1;
	for(i=1;i<=x;i++){
		for(j=0;j<k;j++) w[i][j][0] = 1234567890;
		for(j=0;j<k;j++){
			if(i>=vals[j] && possible[i-vals[j]]){
				if(j==0){
					possible[i] = 1;
					for(p=0;p<k;p++){
						w[i][p][0] = w[i-vals[j]][p][0] + 1;
						for(l=1;l<k;l++) w[i][p][l] = w[i-vals[j]][0][l];
					}
				}
				m = w[i-vals[j]][j][j] - w[i-vals[j]][j][j-1];
				if(m>=0) continue;
				for(p=0;p<j;p++){
					if(w[i][p][0]==1234567890){
						for(l=0;l<k;l++) w[i][p][l] = w[i-vals[j]][p][l];
						w[i][p][j]++;
					}
				}
				for(p=j;p<k;p++) {
					for(l=0;l<k;l++) w[i][p][l] = w[i-vals[j]][j][l];
					w[i][p][j]++;
				}
				possible[i] = 1;
			}
		}
	}
	printf(possible[x]?"YES":"NO");
}
