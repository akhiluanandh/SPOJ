/*
AUTHOR: Akhilesh Anandh
Solution for "GCD2" (www.spoj.com/problems/GCD2)
*/

#include<stdio.h>
#include<string.h>
char b[252];
int gcd(int a, int b){
	if(!a) return b;
	return gcd(b%a,a);
}
int main(){
	int t,a,mod,i,l;
	for(scanf("%d",&t);t--;){
		mod = 0;
		scanf("%d",&a);
		scanf("%s",b);
		if(!a){
			printf("%s\n",b);
			continue;
		}
		l = strlen(b);
		for(i=0;i<l;i++){
			mod = (mod*10 + b[i] - '0')%a;
		}
		printf("%d\n",gcd(mod,a));
	}
	return 0;
}
