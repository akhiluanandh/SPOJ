/*
AUTHOR: Akhilesh Anandh
Solution for "XYI" (www.spoj.com/problems/XYI)
*/

#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm> 
#include <string.h> 
using namespace std;

#define EPS 0.0000001

typedef long long LL;

#define gc getchar_unlocked

int read_int(){
	register int x = 0, c = gc();
	int sign = 1;
	while(c!='-' && (c<48 || c>57) ) c = gc();
	if(c=='-')
		sign = -1, c = gc();
	while(c>=48 && c<=57) 
		x = (x<<1) + (x<<3) + c - 48, c = gc();
	return sign*x;
}

int deg[510];

int main()
{
	int t = read_int(), c=1, n,m,i,j,k;
	for(;c<=t;c++)
	{
		n = read_int();
		m = read_int();
		memset(deg,0,sizeof(deg));
		for(i=0;i<m;i++){
			j = read_int();
			k = read_int();
			deg[k]++;
			deg[j]++;
		}
		vector<int> num_deg(6,0);
		for(i=1;i<=n;i++){
			if(deg[i]<=4)
			num_deg[deg[i]]++;
		}
		//printf("%d %d %d %d\n",num_deg[1],num_deg[2],num_deg[3],num_deg[4]);
		printf("Case %d: ",c);
		if(num_deg[1]==2 && num_deg[2]==(n-2))
			printf("I\n");
		else if(num_deg[1]==3 && num_deg[3]==1 && num_deg[2]==(n-4))
			printf("Y\n");
		else if(num_deg[1]==4 && num_deg[4]==1 && num_deg[2]==(n-5))
			printf("X\n");
		else printf("NotValid\n");
	}
	return 0;
}



