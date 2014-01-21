#include<cstdio>

#define mod 1000000009
#define gc getchar_unlocked
typedef long long LL;

void get_signed_int(int *p){
	register int x =0,c = gc();
	bool neg = false;
	while((c<48 || c>57) && (c!='-')) c = gc();
	if(c=='-'){
		neg = true;
		c = gc();
	}
	while(c>=48 && c<=57){
		x = (x<<1) + (x<<3) + c - 48;
		c = gc();
	}
	*p = (neg? -x:x);
}

LL pow_2(int n){
	LL base = 2,res = 1;
	while(n>0){
		if(n&1) res *= base;
		if(res>mod) res%=mod;
		base *= base;
		if(base>mod) base%=mod;
		n>>=1;
	}
	return res;
}

int a[50000];

int main(){
	int t,n,i,max_neg,occ0;
	LL sum_pos;
	get_signed_int(&t);
	while(t--){
		sum_pos = 0;
		occ0 = 0;
		max_neg = -1000000001;
		get_signed_int(&n);
		for(i=0;i<n;i++) {
			get_signed_int(a+i);
			if(a[i]>0) sum_pos += a[i];
			if(a[i]==0) occ0++;
			if(a[i]<0 && a[i]>max_neg) max_neg = a[i];
		}
		if(sum_pos>0){
			printf("%lld %lld\n",sum_pos,pow_2(occ0));
		}
		else{
			if(occ0) printf("0 %lld\n",pow_2(occ0)-1);
			else{
				for(i=0;i<n;i++) if(a[i]==max_neg) occ0++;
				printf("%d %d\n",max_neg,occ0);
			}
		}
	}
	return 0;
}
