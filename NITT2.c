/*
AUTHOR: Akhilesh Anandh
Solution for "Hai Jolly Jolly Jolly" (www.spoj.com/problems/NITT2)
*/

#include<stdio.h>
#include<string.h>

char num[50002];

int main(){
	int map[7] = {0,3,6,2,5,1,4};
	int t,by3,by25,by9,by7,by4,x;
	long l,sum,i,j;
	scanf("%d",&t);
	getchar();
	while(t--){
		by3 = by25 = by9 = by7 = by4 = 0;
		sum = 0;
		gets(num);
		l = strlen(num);
		x = 10*((int) (num[l-2]-'0')) + ((int) (num[l-1] - '0'));
		if(x%4==0) by4 = 1;
		if(x%25==0) by25 = 1;
		for(i=0;i<l;i++){
			sum += (int) (num[i] - '0');
		}
		if(sum%3==0) by3 = 1;
		if(sum%9==0) by9 = 1;
		for(i=0;i<l-1;i++){
			if(num[i]>='7') num[i] -=7;
			if(num[i+1]>='7') num[i+1]-= 7;
			if(num[i]=='0') continue;
			x = 10*((int) (num[i]-'0')) + ((int) (num[i+1] - '0'));
			while(x>10) {
				x = map[x/10] + x%10;
				if(x%10>=7) x-=7;
			}
			num[i+1] = (char) (x + '0');
		}
		x = (int) num[i] - '0';
		if(x%7==0) by7 = 1;
		if(by4&&by9&&by7) printf("Yes ");
		else printf("No ");
		if(by3&&by25&&by7) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
