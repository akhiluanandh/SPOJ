/*
AUTHOR: Akhilesh Anandh
Solution for "Easy Programming Tutorials" (www.spoj.com/problems/EPTT)
*/

#include<cstdio>
#include<algorithm>
using namespace std;
#define gc getchar_unlocked
#define min(a,b) (a<b?a:b)

int req[1551];

void gi(int *p){
	register int x = 0,c = gc();
	while(c<48||c>57) c = gc();
	while(c<=57&&c>=48){
		x = (x<<1) + (x<<3) + c - 48;
		c = gc();
	}
	*p = x;
}

int main(){
	int r,cur,tutors = 0,t0,t1,t2,t3;
	gi(&r);
	while(r--){
		gi(&cur);
		req[cur]++;
	}
	for(r=0;r<=1410;r++){
		tutors += req[r];
		t0 = req[r];
		t1 = req[r+30];
		t2 = req[r+60];
		t3 = req[r+90];
		req[r+30] -= min(t0,t1);
		req[r+60] -= min(min(t2,t1),t0);
		req[r+90] -= min(min(t3,t2),min(t0,t1));
	}
	printf("%d\n",tutors);
	return 0;
}
