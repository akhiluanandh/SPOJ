/*
AUTHOR: Akhilesh Anandh
Solution for "Weird Function" (www.spoj.com/problems/WEIRDFN)
Algorithm: Priority Queue
*/

#include<cstdio>
#include<queue>
using namespace std;
typedef long long unsigned L;
L f;
 
 int main(){
     L mod = 1000000007;
	  L a,b,c,n,i,tmp,sl,sr,sum;
	  int t;
	  scanf("%d",&t);
	  while(t--){
	     priority_queue < int, vector<int>, less<int> > left;
	     priority_queue < int, vector<int>, greater<int> > right;
	     scanf("%llu %llu %llu %llu",&a,&b,&c,&n);
	     left.push(1);
	     f = 1;
	     sl = 1;
	     sr = 0;
		  sum = 1;
	     for(i=2;i<=n;i++){
	         tmp = left.top();
	         f = a*tmp + (b*i) + c;
				if(f>=mod) f%=mod;
				sum += f;
	         if(sl>sr){
	              if(f<tmp){
	                 left.pop();
	                 right.push(tmp);
	                 left.push(f);
	             }
	         else right.push(f);
	         sr++;
	    		}
		 	else{
		     tmp = right.top();
		     if(f>tmp){
		        right.pop();
		        left.push(tmp);
		        right.push(f);
 		  	 }
		    else left.push(f);
			 sl++;
			}
   	}
		printf("%llu\n",sum);
	}
	return 0;
}
