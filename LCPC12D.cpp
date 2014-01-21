/*
AUTHOR: Akhilesh Anandh
Solution for "Johnny hates climbing" (www.spoj.com/problems/LCPC12D)
Algorithm: Floyd-Warshall
*/

#include<stdio.h>
typedef long long L;
L h[10][10];
L w[10][10][10][10];

L max(L a,L b) { return a>b?a:b;}

int main(){
	L n,m,t,i1,i2,j1,j2,k1,k2,c_no,by,bx,dist,min;
	scanf("%lld",&t);
	for(c_no=1;c_no<=t;c_no++){
		scanf("%lld %lld",&n,&m);
		scanf("%lld %lld",&by,&bx);
		by--;
		bx--;
		for(i1=0;i1<n;i1++)
			for(i2=0;i2<m;i2++)
				scanf("%lld",h[i1]+i2);
		for(i1=0;i1<n;i1++)for(i2=0;i2<m;i2++){
			for(j1=0;j1<n;j1++) for(j2=0;j2<m;j2++){
				w[i1][i2][j1][j2] = 123412341234134; //infinite
			}
			w[i1][i2][i1][i2] = 0;
		}
		
		
		for(i1=0;i1<n;i1++) for(i2=0;i2<m;i2++){
			if(i1>0&&h[i1-1][i2]<=h[i1][i2])
				w[i1][i2][i1-1][i2] = h[i1][i2] - h[i1-1][i2];
			if(i1<(n-1)&&h[i1+1][i2]<=h[i1][i2])
				w[i1][i2][i1+1][i2] = h[i1][i2] - h[i1+1][i2];
			if(i2>0&&h[i1][i2-1]<=h[i1][i2])
				w[i1][i2][i1][i2-1] = h[i1][i2] - h[i1][i2-1];
			if(i2<(m-1)&&h[i1][i2+1]<=h[i1][i2])
				w[i1][i2][i1][i2+1] = h[i1][i2] - h[i1][i2+1];
		}
		
		//Floyd Warshall computation
		for(k1=0;k1<n;k1++) for(k2=0;k2<m;k2++){
			for(i1=0;i1<n;i1++) for(i2=0;i2<m;i2++){
				for(j1=0;j1<n;j1++) for(j2=0;j2<m;j2++){
					dist = max(w[i1][i2][k1][k2],w[k1][k2][j1][j2]);
					L *x = &(w[i1][i2][j1][j2]);
					if(dist<(*x)) (*x = dist);
				}
			}
		}


		//scanning boundary
		min = w[0][0][by][bx];
		for(i1=0;i1<n;i1++){
			if(w[i1][0][by][bx]<min)min= w[i1][0][by][bx];
			if(w[i1][m-1][by][bx]<min) min = w[i1][m-1][by][bx];
		}
		for(i1=0;i1<m;i1++){
			if(w[0][i1][by][bx]<min) min = w[0][i1][by][bx];
			if(w[n-1][i1][by][bx]<min) min = w[n-1][i1][by][bx];
		}
		printf("%lld. ",c_no);
		if(min==123412341234134) printf("IMPOSSIBLE\n");
		else printf("%lld\n",min);
	}
	return 0;
}
