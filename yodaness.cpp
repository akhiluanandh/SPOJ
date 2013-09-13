/*
AUTHOR: Akhilesh Anandh

Solution for www.spoj.com/problems/YODANESS

Algorithm: Binary Indexed Tree
*/

#include<cstdio>
#include<cstring>
#include<string>
#include<tr1/unordered_map>
using namespace std;

#define MAX 30000

char strings[MAX][21];
int bit[MAX+1];
tr1::unordered_map<string,int> m;
char cur[21];
int n;
void update(int idx){
	while(idx<=n){
		bit[idx]++;
		idx += (idx & -idx);
	}
}

int cf(int idx){
	int c = 0;
	while(idx>0){
		c += bit[idx];
		idx -= (idx & -idx);
	}
	return c;
}

int main(){
	int t,i,j;
	for(scanf("%d",&t);t--;){
		m.clear();
		scanf("%d",&n);
		for(i=0;i<=n;i++) bit[i] = 0;
		for(i=0;i<n;i++) scanf("%s",strings[i]);
		for(i=1;i<=n;i++){
			scanf("%s",cur);
			m[cur] = i;
		}
		j = (n*(n-1))/2;
		for(i=0;i<n;i++){
			int p = m[strings[i]];
			j -= cf(p);
			update(p);
		}
		printf("%d\n",j);
	}
	return 0;
}
