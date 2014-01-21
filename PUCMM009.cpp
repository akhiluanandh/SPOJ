/*
AUTHOR: Akhilesh Anandh
Solution for "David and his obsession" (www.spoj.com/problems/PUCMM009)
*/

#include<cstdio>
#define rep(x) for(x=0;x<=9;x++)
typedef long long LL;

LL gcd(LL a, LL b){
	return b? gcd(b,a%b):a;
}

int main(){
	LL count=0,num=0;
	LL a,b,c,d,e;
	rep(a){
		rep(b){
			if(b==a) continue;
			rep(c){
				if(c==b||c==a) continue;
				rep(d){
					if(d==c||d==b||d==a) continue;
					rep(e){
						if(e==d||e==c||e==b||e==a) continue;
						LL x = e + d*10 + c*100 + b*1000 + a*10000;
						num++;
						if((x/495)*495==x){
							count++;
						}
					}
				}
			}
		}
	}
	LL p = gcd(num,count);
	num/=p;
	count/=p;
	printf("%lld/%lld",count,num);
	return 0;
}
