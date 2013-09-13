/*
AUTHOR: Akhilesh Anandh
Solution for "Piggy-Bank" (www.spoj.com/problems/PIGBANK)
Algorithm: DP
*/

#include<stdio.h>
typedef long long LL;
LL min_val[10001];

LL p[500];
LL w[500];

LL min_value(LL empty_wt, LL full_wt,int n){
    LL inf = 100000000000000007;
    LL weight = full_wt - empty_wt;
    LL i,j;
    for(i=0;i<=weight;i++){
        min_val[i] = inf;
    }
    min_val[0] = 0;
    for(i=0;i<=weight;i++){
        for(j=0;j<n;j++){
            if(w[j]<=i){
                LL x = (min_val[i-w[j]]+p[j]);
                if(x<=min_val[i]) min_val[i] = x;
            }
        }
    }
    if(min_val[weight]!=inf) return min_val[weight];
    return -1;
}

int main(void){
    LL t,empty,full;
    int n,i;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld %lld",&empty,&full);
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%lld %lld",p+i,w+i);
        }
        LL val = min_value(empty,full,n);
        if(val>=0) printf("The minimum amount of money in the piggy-bank is %lld.",val);
        else printf("This is impossible.");
        printf("\n");
    }
    
    return 0;
}

