/*
AUTHOR: Akhilesh Anandh
Solution for "Pouring Water" (www.spoj.com/problems/POUR1)
Algorithm: BFS
*/

#include<cstdio>
#include<queue>
using namespace std;

#define max(a,b) a<b?b:a

struct node{
	int a_lit;
	int b_lit;
	int steps;
};

typedef struct node Node;

Node newState(int a, int b, int s){
	Node t;
	t.a_lit = a;
	t.b_lit = b;
	t.steps = s;
	return t;
}

int b_afull[40001],b_aempty[40001],a_bfull[40001],a_bempty[40001];

int gcd(int a, int b){
	if(a>b) return gcd(b,a);
	if(!a) return b;
	return gcd(b%a,a);
}

int main(){
	int t,a,b,c,temp,i,j;
	for(scanf("%d",&t);t--;){
		scanf("%d%d%d",&a,&b,&c);
		if(c%gcd(a,b)){
			printf("-1\n");
			continue;
		}
		if(c>a&&c>b){
			printf("-1\n");
			continue;
		}
		for(i=max(a,b);i>=0;i--){
			b_afull[i] = b_aempty[i] = a_bfull[i] = a_bempty[i] = 0;
		}
		b_aempty[0] = a_bempty[0] = 1;
		queue<Node> q;
		Node init,t;
		init.a_lit = init.b_lit = init.steps = 0;
		q.push(init);
		while(!q.empty()){
			Node *cur = &(q.front());
			q.pop();
			if(cur->a_lit==c || cur->b_lit==c){
				temp = cur->steps;
				while(!q.empty()) q.pop();
				break;
			}
			//filling a;
			if(!b_afull[cur->b_lit]){
				b_afull[cur->b_lit] = 1;
				if(cur->b_lit==0) a_bempty[a] = 1;
				q.push(newState(a,cur->b_lit,cur->steps+1));
			}
			//filling b;
			if(!a_bfull[cur->a_lit]){
				a_bfull[cur->a_lit] = 1;
				if(cur->a_lit==0) b_aempty[b] = 1;
				q.push(newState(cur->a_lit,b,cur->steps+1));
			}
			//emptying a
			if(!b_aempty[cur->b_lit]){
				b_aempty[cur->b_lit] = 1;
				if(cur->b_lit==b) a_bfull[0] = 1;
				q.push(newState(0,cur->b_lit,cur->steps+1));
			}
			//emptying b
			if(!a_bempty[cur->a_lit]){
				a_bempty[cur->a_lit] = 1;
				if(cur->a_lit==a) b_afull[0] = 1;
				q.push(newState(cur->a_lit,0,cur->steps+1));
			}
			//pouring from a to b
			if(cur->b_lit!=b&&cur->a_lit!=0){
				if(cur->a_lit < (b - cur->b_lit)){
					if(!b_aempty[cur->a_lit+cur->b_lit]){
						b_aempty[cur->a_lit+cur->b_lit] = 1;
						q.push(newState(0,cur->a_lit+cur->b_lit,cur->steps+1));
					}
				}
				else if(cur->a_lit == (b - cur->b_lit)){
					if(!b_aempty[b]){
						b_aempty[b] = a_bfull[0] = 1;
						q.push(newState(0,b,cur->steps+1));
					}
				}
				else{
					int x = cur->a_lit + cur->b_lit - b;
					if(!a_bfull[x]){
						a_bfull[x] = 1;
						q.push(newState(x,b,cur->steps+1));
					}
				}
			}

			//pouring from b to a
			if(cur->a_lit!=a&&cur->b_lit!=0){
				if(cur->b_lit < (a - cur->a_lit)){
					if(!a_bempty[cur->b_lit+cur->a_lit]){
						a_bempty[cur->b_lit+cur->a_lit] = 1;
						q.push(newState(cur->b_lit+cur->a_lit,0,cur->steps+1));
					}
				}
				else if(cur->b_lit == (a - cur->a_lit)){
					if(!a_bempty[b]){
						a_bempty[b] = b_afull[0] = 1;
						q.push(newState(a,0,cur->steps+1));
					}
				}
				else{
					int x = cur->a_lit + cur->b_lit - a;
					if(!b_afull[x]){
						b_afull[x] = 1;
						q.push(newState(a,x,cur->steps+1));
					}
				}
			}

		}
		printf("%d\n",temp);
	}
	return 0;
}
