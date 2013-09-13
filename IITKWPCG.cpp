/*
AUTHOR: Akhilesh Anandh
Solution for "Help the Old King" (http://www.spoj.com/problems/IITKWPCG/)
Algorithm: Kruskal's Algo for MST
*/

#include<cstdio>
#include<algorithm>
using namespace std;

struct e{
	int a;
	int b;
	int cost;
};
typedef struct e Edge;

struct sub{
	int parent;
	int rank;
};
typedef struct sub Subset;

Subset subs[100001];
Edge list[200001];

int log2(long long pow){
	int ans = -1;
	while(pow){
		pow>>=1;
		ans++;
	}
	return ans;
}

int find(int e){
	if(subs[e].parent!=e) subs[e].parent = find(subs[e].parent);
	return subs[e].parent;
}

int uni(int x, int y){
	int rx = find(x),ry = find(y);
	if(subs[rx].rank<subs[ry].rank){
		subs[rx].parent = ry;
	}
	else if(subs[ry].rank<subs[rx].rank)
		subs[ry].parent = rx;
	else{
		subs[ry].parent = rx;
		subs[rx].rank++;
	}
}

bool comp(Edge a, Edge b){
	return a.cost<b.cost;
}

int main(){
	int t,n,m,i,j;
	for(scanf("%d",&t);t--;){
		scanf("%d %d",&n,&m);
		for(i=1;i<=m;i++){
			long long temp;
			scanf("%d %d ",&(list[i].a),&(list[i].b));
			scanf("%lld",&temp);
			list[i].cost = log2(temp);
		}
		for(i=1;i<=n;i++){
			subs[i].parent = i;
			subs[i].rank = 0;
		}
		sort(list+1,list+m+1,comp);
		j=0;
		i=0;
		int cost = 0;
		while(j<n-1){
			Edge e = list[i++];
			int x = find(e.a),y = find(e.b);
			if(x!=y){
				j++;
				cost += e.cost;
				uni(x,y);
			}
		}
		printf("%d\n",cost+1);
	}
	return 0;
}
