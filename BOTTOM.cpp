/*
AUTHOR: Akhilesh Anandh
Solution for "The Bottom of a Graph" (www.spoj.com/problems/BOTTOM)
Algorithm: Tarjan's algo. for strongly connected components
*/

#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int low[5001],dfsn[5001];

typedef vector<int> Alist;

Alist adj[5001];
bool inSt[5001];

int ind = 0;
stack<int> st;

void strConnect(int v){
	low[v] = dfsn[v] = ind++;
	st.push(v);
	inSt[v] = true;
	for(int i=0;i<adj[v].size();i++){
		if(dfsn[adj[v][i]]==-1){
			strConnect(adj[v][i]);
			low[v] = min(low[v],low[adj[v][i]] );
		}
		else if(inSt[adj[v][i]]){
			low[v] = min(low[v],dfsn[adj[v][i]]);
		}
	}
	if(low[v]==dfsn[v]){
		while(!st.empty()){
			int temp = st.top();
			st.pop();
			inSt[temp] = false;
			low[temp] = dfsn[v];
			if(temp==v) break;
		}
	}
}


void tarjan(int n){
	ind = 0;
	while(!st.empty()) st.pop();
	memset(low,-1,sizeof(low));
	memset(dfsn,-1,sizeof(dfsn));
	memset(inSt,0,sizeof(inSt));
	for(int i=1;i<=n;i++){
		if(dfsn[i]==-1){
			strConnect(i);
		}
	}
}

void printBottoms(int n){
	for(int i=0;i<=n;i++) inSt[i] = true;
	for(int i=1;i<=n;i++){
		for(int j=0;j<adj[i].size();j++){
			if(low[i]!=low[adj[i][j]]){
				inSt[low[i]] = false;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(inSt[low[i]]) printf("%d ",i);
	}
	printf("\n");
}

int main(){
	int n,e,i,j,k;
	while(1){
		scanf("%d",&n);
		if(!n) break;
		scanf("%d",&e);
		for(i=1;i<=n;i++) adj[i].clear();
		while(e--){
			scanf("%d %d",&j,&k);
			adj[j].push_back(k);
		}
		tarjan(n);
		printBottoms(n);
	}
	return 0;
}
