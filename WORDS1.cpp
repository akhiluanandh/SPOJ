/*
AUTHOR: Akhilesh Anandh
Solution for "Play on Words" (www.spoj.com/WORDS1)
Algorithm: Euler path
*/

#include<cstdio>
#include<cstring>

int in_d[26],out_d[26],edge[26][26],v[26],traversed[26];
char s[1002];

void traverse(int a){
	traversed[a] =1 ;
	int j;
	for(j=0;j<26;j++){
		if((edge[a][j]||edge[j][a])&&!traversed[j]) traverse(j);
	}
}

int main(){
	int t,n,i,j,v1,v2,exists,connected;
	for(scanf("%d",&t);t--;){
		scanf("%d",&n);
		exists = 1;
		v1 = v2 = -1;
		for(i=0;i<26;i++) {
			for(j=0;j<26;j++) edge[i][j] = 0;
			in_d[i] = out_d[i] = v[i] = traversed[i] = 0;
		}
		for(i=0;i<n;i++){
			scanf("%s",s);
			j = strlen(s);
			out_d[s[0]-'a']++;
			in_d[s[j-1]-'a']++;
			v[s[0]-'a'] = v[s[j-1]-'a'] = 1;
			edge[s[0]-'a'][s[j-1]-'a'] = 1;
			edge[s[j-1]-'a'][s[0]-'a'] = 1;
		}
		connected = 1;
		for(i=0;!v[i];i++);
		traverse(i);
		for(i=0;i<26;i++){
			if(v[i]&&!traversed[i]){
				connected = 0;
				break;
			}
		}
		if(!connected) goto xyz;
		for(i=0;i<26;i++){
			if(in_d[i]!=out_d[i]){
				if(v1==-1) v1 = i;
				else if(v2==-1) v2 = i;
				else{
					exists =  0;
				}
			}
		}
		xyz:
		if(!connected||!exists){
			printf("The door cannot be opened.\n");
			continue;
		}
		exists = 0;
		if(v1==-1) exists = 1;
		if((out_d[v1]==in_d[v1]+1)&&(in_d[v2] = out_d[v2]+1)) exists = 1;
		else
		if((out_d[v2]==in_d[v2]+1)&&(in_d[v1] = out_d[v1]+1)) exists = 1;
		if(exists) printf("Ordering is possible.\n");
		else printf("The door cannot be opened.\n");
	}
	return 0;
}
