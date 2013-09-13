#include<cstdio>
#include<map>
#include<stdlib.h>
using namespace std;

typedef long long unsigned LL;

map<LL,LL> x;

LL mod = 1000000007L;

LL pow_of_3(LL n){
	LL t = n;
	if(x[n]) return x[n];
	LL res = 1, base = 3;
	while(n>0){
		if(n%2==1) {res = (res*base)%mod;}
		base = (base*base)%mod;
		n = n>>1;
	}
	return x[t] = res;
}

int main(){
	LL t,ans,n,n1,c;
	char s[15];
	gets(s);
	t = atoi(s);
	while(t--){
		gets(s);
		n = atoi(s);
		if(n==1){
			ans=1;
			goto l;
		}
		c = n%3;
		if(c==2) n1 = (n-2)/3;
		else if(c==1) n1 = (n-4)/3;
		else n1 = n/3;
		ans = pow_of_3(n1);
		if(n%3==2) ans = (ans*2)%mod;
		else if(n%3==1)  ans = (ans*4)%mod;
		l:
		printf("%llu\n",ans);
	}
	return 0;
}
