/*
AUTHOR: Akhilesh Anandh
Solution for "Paradox" (www.spoj.com/problems/PARADOX)
Algorithm: DFS
*/

#include<cstdio>
#include<cstring>

struct st{
	int s_no;
	bool val;
};

typedef struct st Statement;

bool contra = false;

Statement sts[101];
int vals[101];

int fr[101];
int from;

void traverse(int sn){
	fr[sn] = from;
	Statement s = sts[sn];
	if((vals[sn]==1&&s.val)||(vals[sn]==0&&!s.val)){
		if(vals[s.s_no]==0){
			contra = true;
			return;
		}
		else if(vals[s.s_no]==-1){
			vals[s.s_no] = 1;
			traverse(s.s_no);
		}
	}
	else{
		if(vals[s.s_no]==1){
			contra = true;
			return;
		}
		else if(vals[s.s_no]==-1){
			vals[s.s_no]=0;
			traverse(s.s_no);
		}
	}
}

int main(){
	int n,j,i;
	char str[10];
	while(1){
		scanf("%d",&n);
		if(!n) break;
		for(i=1;i<=n;i++){
			scanf("%d",&(sts[i].s_no));
			scanf("%s",str);
			if(strcmp(str,"false")){
				sts[i].val = true;
			}
			else sts[i].val = false;
			vals[i] = -1;
		}
		for(j=1;j<=100;j++){
			if(vals[j]!=-1) continue;
			contra = false;
			vals[j] = 1;
			from = j;
			traverse(j);
			if(contra){
				for(i=1;i<=n;i++) if(fr[i]==j) vals[i] = -1;
				vals[j] = 0;
				contra = false;
				traverse(j);
			}
			if(contra) break;
		}
		if(!contra) printf("NOT ");
		printf("PARADOX\n");
		
	}
	return 0;
}
