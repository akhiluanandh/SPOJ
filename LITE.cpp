/*
Author: Akhilesh Anandh
solution for "Light Switching" (www.spoj.com/problems/LITE)
Algorithm: Segment Trees
*/

#include<cstdio>

int tree[270000];
bool lazy[270000];

void flip(int node, int st, int en, int a, int b){
	if(lazy[node]){
		lazy[node] = false;
		tree[node] = en-st+1 - tree[node];
		if(st<en){
			lazy[node<<1] = !lazy[node<<1];
			lazy[1+(node<<1)] = !lazy[1+(node<<1)];
		}
	}
	if(st>en || a > en || b < st) return ;
	if(a<=st && en<=b){
		tree[node] = en-st+1 - tree[node];
		if(st<en){
			lazy[node<<1] = !lazy[node<<1];
			lazy[1+(node<<1)] = !lazy[1+(node<<1)];
		}
		return;
	}
	int mid = (st+en)/2;
	flip((node<<1),st,mid,a,b);
	flip((node<<1)+1,mid+1,en,a,b);
	if(st<en) tree[node] = tree[node<<1] + tree[(node<<1)+1];
}

int query(int node, int st, int en, int a, int b){
	
	if(st>en || a > en || b < st) return 0;
	
	if(lazy[node]){
		lazy[node] = false;
		tree[node] = en-st+1-tree[node];
		if(st<en){
			lazy[node<<1] = !lazy[node<<1];
			lazy[(node<<1)+1] = !lazy[(node<<1)+1];
		}
	}
	
	if(a<=st && en<=b){
		return tree[node];
	}
	int mid = (st+en)/2;
	int t1 = 0, t2 = 0;
	t1 = query((node<<1),st,mid,a,b);
	t2 = query((node<<1)+1,mid+1,en,a,b);
	return t1+t2;
}


int main(){
	int n,m,q,a,b;
	scanf("%d %d",&n,&m);
	while(m--){
		scanf("%d %d %d",&q,&a,&b);
		if(q==1) printf("%d\n",query(1,1,n,a,b));
		else flip(1,1,n,a,b);
	}
	return 0;
}
