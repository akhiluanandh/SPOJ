/*
AUTHOR: Akhilesh Anandh
Solution for www.spoj.com/problems/DEFKIN
*/

#include<stdio.h>
bool r[40001],c[40001];

int main(){
	int t,n,i,j,row,col,w,h,cur,maxr,maxc;
	for(scanf("%d",&t);t--;){
		scanf("%d %d %d",&w,&h,&n);
		for(i=0;i<=40000;i++) r[i] = false;
		for(j=0;j<=40000;j++) c[j] = false;
		while(n--){
			scanf("%d %d",&row,&col);
			r[row] = c[col] = true;
		}
		maxc = 0;
		maxr = 0;
		cur = 0;
		for(i=1;i<=w;i++){
			if(!r[i]) cur++;
			if(cur>maxr) maxr = cur;
			if(r[i]) cur = 0;
		}
		cur = 0;
		for(i=1;i<=h;i++){
			if(!c[i]) cur++;
			if(cur>maxc) maxc = cur;
			if(c[i]) cur = 0;
		}
		printf("%d\n",maxc*maxr);
	}
	return 0;
}
