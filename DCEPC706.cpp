/*
AUTHOR: Akhilesh Anandh
Solution for "Meeting for Pary" (www.spoj.com/problems/DCEPC706)
Algorithm: BFS
*/

#include<cstdio>
#include<queue>
using namespace std;

#define max(a,b) (a>b?a:b)

bool traversed[202][202][3];
int dist[202][202][3];
char array[202][202];

int n,m;

void cl(){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			traversed[i][j][0] = traversed[i][j][1] = traversed[i][j][2] = false;
			dist[i][j][0] = dist[i][j][1] = dist[i][j][2] = 0;
		}
	}
}

void bfs(int f, int i, int j){
	queue <int > q;
	q.push(i*m+j);
	traversed[i][j][f] = true;
	while(!q.empty()){
		int t = q.front();
		int x = t/m,y = t - x*m;
		q.pop();
		if(x>0 && !traversed[x-1][y][f] && array[x-1][y]!='#'){
			dist[x-1][y][f] = dist[x][y][f] + 1;
			traversed[x-1][y][f] = true;
			q.push((x-1)*m + y);
		}
		if(y>0 && !traversed[x][y-1][f] && array[x][y-1]!='#'){
			dist[x][y-1][f] = dist[x][y][f] + 1;
			traversed[x][y-1][f] = true;
			q.push(x*m + y-1);
		}
		if(x<(n-1) && !traversed[x+1][y][f] && array[x+1][y]!='#'){
			dist[x+1][y][f] = dist[x][y][f] + 1;
			q.push((x+1)*m + y);
			traversed[x+1][y][f] = true;
		}
		if(y<(m-1) && !traversed[x][y+1][f] && array[x][y+1]!='#'){
			dist[x][y+1][f] = dist[x][y][f] + 1;
			q.push((x*m + y+1));
			traversed[x][y+1][f] = true;
		}
	}
}

int main(){
	int t,i,j;
	int homes[3][2];
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		n+=2;
		m+=2;
		cl();
		for(j=0;j<m;j++) array[n-1][j]=array[0][j]='.';
		for(i=1;i<n-1;i++){
			getchar_unlocked();
			array[i][0] = array[i][m-1] = '.';
			for(j=1;j<m-1;j++){
				array[i][j] = getchar_unlocked();
				if(array[i][j]=='1'){
					homes[0][0] = i;
					homes[0][1] = j;
				}
				if(array[i][j]=='2'){
					homes[1][0] = i;
					homes[1][1] = j;
				}
				if(array[i][j]=='3'){
					homes[2][0] = i;
					homes[2][1] = j;
				}
			}
		}
		bfs(0,homes[0][0],homes[0][1]);
		bfs(1,homes[1][0],homes[1][1]);
		bfs(2,homes[2][0],homes[2][1]);
		int min = 999999999;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(!(traversed[i][j][0]&&traversed[i][j][1]&&traversed[i][j][2])) continue;
				int temp = max(max(dist[i][j][0],dist[i][j][1]),dist[i][j][2]);
				if(temp<min) min = temp;
			}
		}
		printf("%d\n",min);
	}
	return 0;
}


