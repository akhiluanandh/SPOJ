/*
AUTHOR: Akhilesh Anandh
Solution for Slick (www.spoj.com/problems/UCV2013H)
Algorithm: DFS/DP
*/

#include<stdio.h>

int array[251][251];
int traversed[251][251];

int splick[251][251];

int sizes[62502];
int splicks[62502];


void traverse(int i, int j, int n, int m, int splick_no){
	if(array[i][j]){
		sizes[splick_no]++;
		splick[i][j] = splick_no;
		traversed[i][j] = 1;
		if(i>0&&!(traversed[i-1][j])) traverse(i-1,j,n,m,splick_no);
		if(i<n-1&&!(traversed[i+1][j])) traverse(i+1,j,n,m,splick_no);
		if(j>0&&!(traversed[i][j-1])) traverse(i,j-1,n,m,splick_no);
		if(j<m-1&&!(traversed[i][j+1])) traverse(i,j+1,n,m,splick_no);
	}
}


int main(){

	int n,m,i,j,k,num,cur;
	while(1){
		scanf("%d %d",&n,&m);
		if(!n&&!m) break;
		for(i=0;i<n;i++) for(j=0;j<m;j++) scanf("%d",array[i] + j);
		for(i=0;i<n;i++) 
			for(j=0;j<m;j++) {
				traversed[i][j] = 0;
				splick[i][j] = -1;
			}

		for(i=0;i<62502;i++) sizes[i] = 0;
		num = 0;

		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(array[i][j]==1&&!traversed[i][j]){
					traverse(i,j,n,m,num++);
				}
			}
		}
		printf("%d\n",num);
		for(i=0;i<62502;i++) splicks[i] = 0;
		for(i=0;i<num;i++){
			splicks[sizes[i]]++;
		}
		cur = 0;
		for(i=0;i<62502;i++){
			if(cur>=num) break;
			if(splicks[i]!=0){
				printf("%d %d\n",i,splicks[i]);
			}
		}
	}
	return 0;
}
