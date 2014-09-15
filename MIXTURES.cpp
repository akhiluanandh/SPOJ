/***************************
AUTHOR: Akhilesh Anandh
Solution for "Mixtures" (www.spoj.com/problems/MIXTURES)
Algorithm: DP
**************************/

#include<stdio.h>

typedef long long unsigned LLU;

LLU min_smoke[100][100];
int color[100][100];

LLU smoke(int n){
    int i,j,l;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            min_smoke[i][j]=10000000000000000;
        }
    }
    
    for(i=0;i<n;i++){
        min_smoke[i][i] = 0;
    }
    
    for(l=2;l<=n;l++){
        int e = n-l;
        for(i=0;i<=e;i++){
            int k = i+l-1;
            for(j=i;j<k;j++){
                LLU sm = min_smoke[i][j] + min_smoke[j+1][k] + color[i][j]*color[j+1][k];
                int cl = (color[i][j]+color[j+1][k])%100;
                if(sm<min_smoke[i][k]){
                    min_smoke[i][k] = sm;
                    color[i][k] = cl;
                }
            }
        }
    }
    

    
    return min_smoke[0][n-1];
}

int main(void){
    int n;
    while(scanf("%d",&n)!=EOF){
        int i;
        for(i=0;i<n;i++){
            scanf("%d",&(color[i][i]));
        }
        printf("%llu\n",smoke(n));
    }
    return 0;    
}






