/*
AUTHOR: Akhilesh Anandh
Solution for "C you and me" (www.spoj.com/problems/PUCMM223)
Algorithm: BFS
*/

#include<cstdio>
#include<queue>
#include<list>
#include<cstring>
using namespace std;

#define gc getchar_unlocked

char arr[20][20];
int dist[160000],n,m;

inline list<int> generate_moves(int x, int y){
	list<int> moves;
	moves.push_back(x*20+y);
	if(x>0 && !(arr[x-1][y]=='#'))
		moves.push_back((x-1)*20+y);
	if(x<(n-1) && !(arr[x+1][y]=='#'))
		moves.push_back((x+1)*20+y);
	if(y>0 && !(arr[x][y-1]=='#'))
		moves.push_back((x)*20+y-1);
	if(y<(m-1) && !(arr[x][y+1]=='#'))
		moves.push_back((x)*20+y+1);
	return moves;
}

inline int hash(int ax, int ay, int bx, int by){
	return by + bx*20 + ay*400 + ax*8000;
}

inline int scan_char(){
	register int c;
	do{
		c = gc();
	}while(c<=32);
	return c;
}

inline void bfs(int ax1, int ay1, int bx1, int by1){
	queue<int> q;
	int ha = hash(ax1,ay1,bx1,by1);
	q.push(ha);
	dist[ha] = 0;
	while(!q.empty()){
		int h1 = q.front(),h=h1;
		q.pop();
		int ax,ay,bx,by;
		by = h%20;
		h/=20;
		bx = h%20;
		h/=20;
		ay = h%20;
		h/=20;
		ax = h;
		list<int> a_moves = 	generate_moves(ax,ay);
		list<int> b_moves =	generate_moves(bx,by);
		for(list<int>::iterator i1 = a_moves.begin();i1!=a_moves.end();i1++){
			for(list<int>::iterator i2 = b_moves.begin();i2!=b_moves.end();i2++){
				int temp = (*i1)*400 + *i2;
				if((*i1)==(*i2)) continue;
				if((*i1)==(bx*20+by) && (*i2)==(ax*20+ay)) continue;
				if(dist[temp]==-1){
					dist[temp] = dist[h1]+1;
					q.push(temp);
				}
			}
		}
	}
}

inline int calc_moves(int ax, int ay, int bx, int by){
	memset(dist,-1,sizeof(dist));
	bfs(ax,ay,bx,by);
	return dist[hash(bx,by,ax,ay)];
}

int main(){
	while(1){
		scanf("%d %d",&n,&m);
		int ax,ay,bx,by;
		if(!(n||m)) break;
		int i,j;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++){
				arr[i][j] = scan_char();
				if(arr[i][j]=='a'){
					ax = i;
					ay = j;
				}
				if(arr[i][j]=='b')
				{
					bx = i;
					by = j;
				}
			}
		int moves = calc_moves(ax,ay,bx,by);
		if(moves>0){
			printf("%d\n",moves);
		}
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}

