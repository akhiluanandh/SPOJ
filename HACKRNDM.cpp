#include<cstdio>
#include<malloc.h>
#include<algorithm>
using namespace std;

#define gc getchar_unlocked

void get_signed_int(int *p){
	register int c = gc(),x = 0;
	bool neg = false;
	while(c!='-' && (c<48||c>57)) c = gc();
	if(c=='-'){
		neg = true;
		c = gc();
	}
	while(c>=48 && c<=57){
		x = (x<<1) + (x<<3) + c - 48;
		c = gc();
	}
	*p = neg? -x:x;
}

int main(){
	int n,k,i,j,count;
	get_signed_int(&n);
	get_signed_int(&k);
	int *a = (int *) malloc(n*sizeof(int));
	for(i=0;i<n;i++) get_signed_int(a+i);
	sort(a,a+n);
	for(i=j=count=0;i<n&&j<n;i++){
		while(a[j]<a[i]+k) j++;
		if(j>=n) break;
		if(a[j]==a[i]+k) count++;
	}
	printf("%d",count);
	return 0;
}
