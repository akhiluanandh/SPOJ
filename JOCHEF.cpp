#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


typedef long long LL;
LL ht[2][4010], n, m, f;

int main() {
	ios_base::sync_with_stdio(false);
	while(1){
		cin>>n>>m;
		if(!n && !m)
			break;
		cin>>f;
		LL i,j, area = 0;
		for (i=0; i<n; i++) {
			string row;
			cin>>row;
			stack<pair<LL, LL> > st;
			for (j=0;j<m;j++) {
				if(row[j]=='C'){
					ht[i&1][j] = 0;
				} else {
					if(i>0)
						ht[i&1][j] = ht[(i-1)&1][j] + 1;
					else ht[0][j] = 1;
				}
				LL last = j;
				while (!st.empty() && st.top().first >= ht[i&1][j]) {
					area = max(area, st.top().first * (j-st.top().second));
					last = st.top().second;
					st.pop();
				}
				st.push(make_pair(ht[i&1][j], last));
			}
			while (!st.empty()) {
				area = max(area, st.top().first * (m - st.top().second));
				st.pop();
			}
		}
		LL ans = (LL) f * (LL) area;
		cout<<ans<<endl;
	}
	return 0;
}
