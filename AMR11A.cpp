/*
AUTHOR: Akhilesh Anandh
Solution for "Magic Grid" (www.spoj.com/problems/AMR11A)
Algorithm: DP, Binary search
*/

#include<cstdio>

#define max(x,y) (x>y?x:y)
#define gc getchar_unlocked
void gi(int *p){
	register int c = gc(),x=0;
	bool neg = false;
	while((c<48 || c>57) && (c!='-')) c = gc();
	if(c=='-'){
		neg = true;
		c = gc();
	}
	while(c>=48&&c<=57){
		x = (x<<1) + (x<<3) + c-48;
		c = gc();
	}
	if(neg) x = -x;
	*p = x;
}

int a[500][500],dp[500][500];

int r,c;

inline bool possible(int init){
	dp[0][0] = init;
	int i,j;
	for(i=1;i<c;i++){
		if(dp[0][i-1]>0)
			dp[0][i] = dp[0][i-1] + a[0][i];
		else
			dp[0][i] = -1;
	}
	for(i=1;i<r;i++){
		if(dp[i-1][0]>0)
			dp[i][0] = dp[i-1][0] + a[i][0];
		else
			dp[i][0] = -1;
		for(j=1;j<c;j++){
			int x1 = -1, x2 = -1;
			if(dp[i-1][j]>0) x1 = dp[i-1][j];
			if(dp[i][j-1]>0) x2 = dp[i][j-1];
			if(x1>0 || x2>0) dp[i][j] = max(dp[i][j-1],dp[i-1][j]) + a[i][j];
			else dp[i][j] = -1;
		}
	}
	return dp[r-1][c-1]>0;
}

int main(){
	int t,i,j;
	gi(&t);
	while(t--){
		gi(&r);
		gi(&c);
		for(i=0;i<r;i++) for(j=0;j<c;j++) gi(a[i]+j);
		int lo = 1,hi = 1000000,mid,ans=0;
		while(lo<=hi){
			mid = (lo+hi)/2;
			if(possible(mid)){
				if(!possible(mid-1)){
					ans=mid;
					break;
				}
				else hi = mid-1;
			}
			else{
				if(possible(mid+1)){
					ans = mid+1;
					break;
				}
				lo = mid+1;
			}
		}
		if(!ans) ans = mid;
		printf("%d\n",ans);
	}
}
