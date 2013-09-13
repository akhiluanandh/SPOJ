/*
AUTHOR: Akhilesh Anandh
Solution for "RPLN" (www.spoj.com/problems/RPLN)
Algorithm: Segment tree (RMQ)
*/

#include<cstdio>
#define min(a,b) (a<b?a:b)
int nos[100000],tree[500000];
void initialize(int node,int st, int en){
	if(st==en){
		tree[node]=st;
		return;
	}
	initialize(node*2+1,st,(st+en)/2);
	initialize(node*2+2,(st+en)/2+1,en);
	if(nos[tree[node*2+1]]<nos[tree[node*2+2]])
		tree[node] = tree[node*2+1];
	else tree[node] = tree[node*2+2];
}

//called with min_in_range(0,0,n-1,i,j), where i,j is the range
int min_in_range(int node,int st,int en,int i,int j){
	if(i>en||j<st) return -1;
	if(st>=i&&en<=j) return tree[node];
	int mid = (st+en)/2;
	int p1 = min_in_range(node*2+1,st,mid,i,j);
	int p2 = min_in_range(node*2+2,mid+1,en,i,j);
	if(p1==-1) return p2;
	if(p2==-1) return p1;
	if(nos[p1]<nos[p2]) return p1;
	return p2;
}

int main(){
	int t,n,q,i,j,c;
	for(scanf("%d",&t),c=1;c<=t;c++){
		scanf("%d %d",&n,&q);
		for(i=0;i<n;i++) scanf("%d",nos+i);
		initialize(0,0,n-1);
		printf("Scenario #%d:\n",c);
		while(q--){
			scanf("%d %d",&i,&j);
			printf("%d\n",nos[min_in_range(0,0,n-1,--i,--j)]);
		}
	}
	return 0;
}
