/*
AUTHOR: Akhilesh Anandh
Solution for "Ololo" (www.spoj.com/problems/OLOLO)
*/

#include<cstdio>
#define gc getchar_unlocked

void get_int(int *p){
	register int c = gc();
	int x = 0;
	while(c<48||c>57) c = gc();
	while(c>=48&&c<=57){
		x = x*10 + c-48;
		c = gc();
	}
	*p = x;
}

int main(){
	int n,cur,x=0;
	get_int(&n);
	while(n--){
		get_int(&cur);
		x = x^cur;
	}
	printf("%d",x);
	return 0;
}
