/*
AUTHOR: Akhilesh Anandh
Solution for "Johnny the Gambler" (www.spoj.com/problems/LCPC12F)
*/

#include<stdio.h>

typedef long long LL;

LL occurences[1001];

LL min(LL a, LL b) { return a<b? a:b; }

int main(){
	LL t,i,j,n,x,pairs,cur,upper;
	scanf("%lld",&t);
	for(i=1;i<=t;i++){
		scanf("%lld %lld",&x,&n);
		for(j=0;j<=1000;j++) occurences[j] = 0;
		for(j=0;j<n;j++){
			scanf("%lld",&cur);
			occurences[cur]++;
		}
		upper = min(1000,x/2);
		pairs = 0;
		for(j=0;j<=upper;j++){
			if(x-j>1000) continue;
			LL p = occurences[j],q = occurences[x-j];
			if(j==x-j) pairs += (p*(p-1))/2;
			else pairs+=p*q;
		}
		printf("%lld. %lld\n",i,pairs);
	}
	return 0;
}
