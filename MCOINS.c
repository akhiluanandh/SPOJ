/*
AUTHOR: Akhilesh Anandh
Solution for "Coins game" (www.spoj.com/problems/MCOINS)
Algorithm: DP
*/
#include<stdio.h>

typedef long long unsigned LLU;

int win[1000002];

int will_win(LLU k, LLU l, LLU size, LLU last_size){
    win[0] = 0;
    win[1] = 1;
    LLU i;
    for(i=last_size<2?2:last_size;i<=size;i++){
        win[i] = (win[i-1]==1)? 0:1;
        if((i>=k&&win[i-k]==0)||(i>=l&&win[i-l]==0)) win[i] = 1;
    }
  
    return win[size];
}

int main(void){
    LLU l,k,m,size=2,last_size,max_size=0;
    scanf("%llu %llu %llu",&l,&k,&m);
    while(m--){
        last_size = max_size;
        scanf("%llu",&size);
        if(size>max_size){
            max_size = size;
            printf(will_win(k,l,size,last_size)?"A":"B");
        }
        else printf(win[size]?"A":"B");
    }
    return 0;
}


