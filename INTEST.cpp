/*
AUTHOR: Akhilesh Anandh
Solution for "Enormous Input Test" (www.spoj.com/problems/INTEST)
Algorithm: Fast I/o
*/

#include<cstdio>
#define gc getchar_unlocked

void get_int(int *p){
	register int c = gc();
	int x = 0;
	while(c<48||c>57) c = gc();
	while(c>=48&&c<=57){
		x = x*10 + c - 48;
		c = gc();
	}
	*p = x;
}

int main(){
	int n,k,i,c=0;
	get_int(&n);
	get_int(&k);
	while(n--){
		get_int(&i);
		if(i%k==0) c++;
	}
	printf("%d",c);
}
