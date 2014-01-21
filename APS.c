/*
AUTHOR: AKHILESH ANANDH
Problem: Amazing prime sequence (www.spoj.com/problems/APS)
*/

#include<stdio.h>
 
typedef long long L;
 
L factor[10000001],a[10000001];
 
int main(){
    L i,j;
    for(i=2;i<=10000000;i++){
        if(factor[i]==0){
            factor[i] = i;
            for(j=i*i;j<=10000000;j+=i){
                if(factor[j]==0) factor[j] = i;
            }
        }
        a[i] = a[i-1] + factor[i];
    }
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&i);
        printf("%lld\n",a[i]);
    }
    return 0;
}

