/*
AUTHOR: Akhilesh Anandh
Solution for "Faridi and Yadav" (www.spoj.com/problems/CHOTU)
*/

#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	double a,b;
	while(t--){
		cin>>a>>b;
		printf("%.3lf\n",2*sqrt(a*a-b*b));
	}
	return 0;
}
