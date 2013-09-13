/*
AUTHOR: Akhilesh Anandh
Solution for Dark Roads (www.spoj.com/problems/ULM09)
Algorithm: Kruskal's algo for MST
*/

#include<cstdio>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

#define MAX 200000

struct e{
	int a;
	int b;
	int cost;
};
typedef struct e Edge;

Edge list[MAX];

bool comp(Edge e1, Edge e2){
	return e1.cost<e2.cost;
}

struct subset
{
    int parent;
    int rank;
};

struct subset subsets[MAX];

// A utility function to find set of an element i
// (uses path compression technique)
int find(int i)
{
    // find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets[i].parent);
 
    return subsets[i].parent;
}
 
// A function that does union of two sets of x and y
// (uses union by rank)
void Union(int x, int y)
{
    int xroot = find(x);
    int yroot = find(y);
 
    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
 
    // If ranks are same, then make one as root and increment
    // its rank by one
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int main(){
	int m,n,i,j,sum,e;
	while(1){
		sum = 0;
		e = 0;
		scanf("%d %d",&m,&n);
		if(!(m&&n)) break;
		for(i=0;i<n;i++){
			scanf("%d %d %d",&(list[i].a),&(list[i].b),&(list[i].cost));
			sum += list[i].cost;
		}
		for(i=0;i<m;i++){
			subsets[i].parent = i;
			subsets[i].rank = 0;
		}
		sort(list,list+n,comp);
		j = 0;
		i = 0;
		while(e<m-1){
			Edge ed = list[i++];
			int x = find(ed.a);
			int y = find(ed.b);
			if(x!=y){
				e++;
				j += ed.cost;
				Union(x,y);
			}
		}
		printf("%d\n",sum-j);
	}
	return 0;
}



