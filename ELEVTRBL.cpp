/*
AUTHOR: Akhilesh Anandh
Solution for "Elevator Trouble" (www.spoj.com/problems/ELEVTRBL)
Algorithm: BFS
*/

#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

struct node{
	int pos;
	int steps;
};

typedef struct node Node;

Node newState(int p, int s){
	Node n;
	n.pos = p;
	n.steps = s;
	return n;
}

bool reached[1000001];

int main(){
	int f,s,g,u,d,i=-1;
	cin >> f >> s >> g >> u >> d;
	queue<Node> q;
	q.push(newState(s,0));
	while(!q.empty()){
		Node *cur = &(q.front());
		q.pop();
		if(cur->pos==g){
			i=cur->steps;
			break;
		}
		if(cur->pos+u<=f && !reached[cur->pos+u]){
			reached[cur->pos+u] = true;
			q.push(newState(cur->pos+u,cur->steps+1));
		}
		if(cur->pos-d>=1 && !reached[cur->pos-d]){
			reached[cur->pos-d] = true;
			q.push(newState(cur->pos-d,cur->steps+1));
		}
	}
	if(i==-1) printf("use the stairs");
	else printf("%d",i);
	return 0;
}
