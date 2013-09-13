/*
AUTHOR: AKhilesh Anandh
Solution for "Create Collections" (www.spoj.com/problems/IITKWPCO)
*/

#include<cstdio>
#include<algorithm>
using namespace std;

int array[100];
bool used[100];

int main(){
	int t,n,i,j,c;
	for(scanf("%d",&t);t--;){
		for(scanf("%d",&n),i=0;i<n;i++) {scanf("%d",array+i);used[i] = false;}
		sort(array,array+n);
		c=0;
		j=1;
		for(i=0;i<n;i++){
			if(used[i]) continue;
			for(;j<n&&array[j]<2*array[i];j++);
			if(j>=n) break;
			if(array[j]>2*array[i]){
				continue;
			}
			c++;
			used[j++] = true;
		}
		printf("%d\n",c);
	}
	return 0;
}
