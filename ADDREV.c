/*
AUTHOR: Akhilesh Anandh
Solution for "Adding Reversed Numbers" (www.spoj.com/problems/ADDREV)
*/

#include<stdio.h>

unsigned int reverse_int(unsigned int a);

int main(void){
    unsigned int n,sum;
    scanf("%u",&n);
    unsigned int a,b,i;
    for(i=0;i<n;i++){
        scanf("%u",&a);
        a = reverse_int(a);
        scanf("%u",&b);
        b = reverse_int(b);
        sum = a+b;
        sum = reverse_int(sum);
        printf("%u\n",sum);
    }
    return 0;
}

unsigned int reverse_int(unsigned int a){
    unsigned int rev = 0;
    while(a>0){
        rev = rev*10 + a%10;
        a/=10;
    }
    return rev;
}



