/*
	AUTHOR: Akhilesh Anandh
	Solution to "Feynman" (www.spoj.com/problems/SAMER08F)
*/

#include<stdio.h>

int main(void){
	long long unsigned count;
	unsigned int i,n;
	while(1){
		count=0;
		scanf("%d",&n);
		if(n==0) break;
		for(i=1;i<=n;i++){
			count+=i*i;
		}
		printf("%llu\n",count);
	}
	return 0;
}
