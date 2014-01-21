/*
AUTHOR: Akhilesh Anandh
Solution for "Japan" (www.spoj.com/problems/MSE06H)
Algorithm: Binary Indexed Trees
*/

#include<cstdio>
#include<algorithm>
using namespace std;

struct e{
	int st;
	int en;
};
typedef struct e Edge;
typedef long long L;

Edge list[1000000];

bool comp(Edge e1,Edge e2){
	if(e1.st==e2.st) return e1.en<e2.en;
	return e1.st<e2.st;
}

L bit[1001];

L get(int idx){
	L ans = 0;
	while(idx>0){
		ans += bit[idx];
		idx -= (idx&-idx);
	}
	return ans;
}

void update(int idx,int n){
	while(idx<=n){
		bit[idx]++;
		idx += (idx & -idx);
	}
}

int main(){
	int t,n,m,k,cas,i;
	L ans;
	scanf("%d",&t);
	for(cas=1;cas<=t;cas++){
		scanf("%d %d %d",&n,&m,&k);
		for(i=1;i<=m;i++) bit[i] = 0;
		for(i=0;i<k;i++){
			scanf("%d %d",&(list[i].st),&(list[i].en));
		}
		sort(list,list+k,comp);
		ans = 0;
		for(i=0;i<k;i++){
			ans += get(m-list[i].en);
			update(m-list[i].en+1,m);
		}
		printf("Test case %d: %lld\n",cas,ans);
	}
	return 0;
}


