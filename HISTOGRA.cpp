#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm> 
#include <math.h> 
#include <vector>
#include <set>
#include <map> 
#include <string.h> 
#include <cstdlib> 
#include <limits.h> 
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#include <functional> 
#include <stack>
#include <queue>
using namespace std;

typedef long long LL;

#define gc getchar_unlocked

int read_int(){
	register int x = 0, c = gc();
	int sign = 1;
	while(c!='-' && (c<48 || c>57) ) c = gc();
	if(c=='-')
		sign = -1, c = gc();
	while(c>=48 && c<=57) 
		x = (x<<1) + (x<<3) + c - 48, c = gc();
	return sign*x;
}

typedef pair<int,int> PI;

int main()
{
	stack<PI> s;
	int tim = 0,n,i;
	while(1){
		LL max_a = 0,area;
		n = read_int();
		if(!n)
			break;
		for(i=0;i<n;i++){
			int num = read_int();
			if(s.empty()){
				s.push(make_pair(num,tim));
			}
			else{
				PI p = s.top();
				if(num>p.first){
					s.push(make_pair(num,tim));
				}
				else if(num<p.first){
					s.pop();
					if(!s.empty()){
						area = (LL)s.top().first * (LL)(tim + 1 - s.top().second);
						max_a = max(area,max_a);
					}
					s.push(make_pair(num,tim));
				}
			}
			area = (LL) s.top().first * (LL) (tim + 1 - s.top().second);
			max_a = max(area,max_a);
			tim++;
		}
		cout<<max_a<<endl;
	}
	return 0;
}




