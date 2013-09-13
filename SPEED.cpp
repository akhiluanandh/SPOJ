/*
AUTHOR: Akhilesh Anandh
Solution for SPEED (www.spoj.com/problems/speed)
*/

#include<cstdio>
#include<iostream>
using namespace std;
#define abs(a) (a>0?a:-a)

int gcd(int a, int b){
	if(a>b) return gcd(b,a);
	if(!a) return b;
	return gcd(b%a,a);
}

int main(){
	int t,a,b;
	cin >> t;
	while(t--){
		cin >> a >> b;
		int l = gcd(abs(a),abs(b));
		a/=l;
		b/=l; 
		cout << abs(a-b) << endl;
	}
	return 0;
}
