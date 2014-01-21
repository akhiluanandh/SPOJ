/*
AUTHOR: Akhilesh Anandh
Solution for "" (www.spoj.com/problems/EKO)
Algorithm: Binary Search
*/

#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long LL;
LL a[1000001],sum[1000001];

#define gc getchar_unlocked

void gLL(LL *p){
	register int c = gc();
	LL x  = 0;
	while(c<48 || c>57) c = gc();
	while(c>=48 && c<=57){
		x = (x<<1) + (x<<3) + c - 48;
		c = gc();
	}
	*p = x;
}

inline int bs(LL e, int n){
	int lo = 0,hi = n,mid;
	while(lo<hi){
		mid = (lo+hi)/2;
		if(a[mid]==e) return mid;
		if(a[mid]<e){
			if(a[mid+1]>=e) return mid;
			lo = mid+1;
		}
		if(a[mid]>e){
			hi=mid;
		}
	}
	return mid;
}

inline bool poss(LL h,LL m, int n){
	int i = bs(h,n);
	LL d = sum[n] - sum[i] - h*(n-i);
	if(d<m) return false;
	return true;
}

int main()
{
	int n,i;
	LL m,x;
	scanf("%d",&n);
	gLL(&m);
	for(i=1;i<=n;i++){
		gLL(a+i);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		sum[i] = sum[i-1] + a[i];
	}
	LL lo = 0,hi = a[n],mid;
	LL ans = 0;
	while(lo<=hi){
		mid = (lo+hi)/2;
		if(poss(mid,m,n)){
			if(poss(mid+1,m,n)) lo = mid+1;
			else {
				ans =	mid;
				break;
			}
		}
		else{
			if(poss(mid-1,m,n)){
				ans = mid-1;
				break;
			}
			else hi = mid-1;
		}
	}
	if(!ans) ans = mid;
	printf("%lld",ans);
	return 0;
}
