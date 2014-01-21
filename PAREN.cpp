/*
AUTHOR: Akhilesh Anandh
Solution for "Count Paren" (www.spoj.com/problems/PAREN)
Algorithm: DP
*/

#include<stdio.h>
#include<string.h>
typedef long long L;
char val[50],op[50],exp[100];
L ways[50][50][2];

L w(L n){
	L i,j,k;
	for(i=0;i<n;i++){
		ways[i][i][0] = (val[i]=='T')?1:0;
		ways[i][i][1] = 1 - ways[i][i][0];
		for(j=i-1;j>=0;j--){
			ways[j][i][0] = ways[j][i][1] = 0;
			for(k=j;k<i;k++){
				switch(op[k]){
					case('a'): //and
						ways[j][i][0] += (ways[j][k][0]*ways[k+1][i][0]);
						ways[j][i][1] += ((ways[j][k][0]+ways[j][k][1])*(ways[k+1][i][0]+ways[k+1][i][1])-(ways[j][k][0])*(ways[k+1][i][0]));
						break;
					case('o'): //or
						ways[j][i][0] += ((ways[j][k][0]+ways[j][k][1])*(ways[k+1][i][0]+ways[k+1][i][1])-(ways[j][k][1])*(ways[k+1][i][1]));
						ways[j][i][1] += (ways[j][k][1]*ways[k+1][i][1]);
						break;
					case('x'): //xor
						ways[j][i][0] += ((ways[j][k][0]*ways[k+1][i][1]) + (ways[j][k][1]*ways[k+1][i][0]));
						ways[j][i][1] += ((ways[j][k][0]*ways[k+1][i][0]) + (ways[j][k][1]*ways[k+1][i][1]));
						break;
				}
			}
		}
	}
	return ways[0][n-1][0];
}

int main(){
	int t,i,j,l;
	char c;
	for(scanf("%d\n",&t);t--;){
		gets(exp);
		for(i=0,j=0,l=strlen(exp);i<l;i++){
			c = exp[i];
			if(c=='T'||c=='F'){
				val[j] = c;
				if(i<l-3){
					i+=2;
					c = exp[i];
					op[j] = c;
					i+=2;
				}
				j++;
			}
		}
		printf("%lld\n",w(j));
	}
	return 0;
}
