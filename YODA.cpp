/*
AUTHOR: Akhilesh Anandh
Solution for "Yoda goes palindromic!" (www.spoj.com/problems/YODA)
*/

#include<cstdio>
#include<cstring>

typedef long long LL;

LL fac[22];
int occ[26];
char str[1000001];

int main(){
	fac[0] = 1;
	fac[1] = 1;
	for(int i=2;i<=20;i++)
		fac[i] = i*fac[i-1];
	while(1){
		gets(str);
		if(feof(stdin)) break;
		int i,j=0,l = strlen(str);
		memset(occ,0,sizeof(occ));
		for(i=0;i<l;i++){
			char c = str[i];
			if(c>='a'&&c<='z')
				occ[c-'a']++,j++;
			else if(c>='A'&&c<='Z')
				occ[c-'A']++,j++;
		}
		l=0;
		LL ways = fac[j/2];
		for(i=0;i<26;i++){
			int temp = occ[i];
			l += (temp&1);
			ways /= fac[temp>>1];
		}
		if(l>1) ways = 0;
		printf("%lld\n",ways);
	}
}

