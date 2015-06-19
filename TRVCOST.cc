#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <tr1/unordered_map>
#include <tr1/unordered_set>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> II;
typedef vector<II> VII;
typedef long long LL;

#define TCASE int __t; cin >> __t; while (__t--)
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define REP(i, b) FOR(i, 0, b)
#define PB push_back
#define MP make_pair
#define ALL(a) a.begin(), a.end()
#define CLR(a) memset(a, 0, sizeof(a))
#define GC getchar_unlocked

inline int read_int() {
  register int c = GC(), x = 0;
  while ((c < 48 || c > 57) && c != '-') {
    c = GC();
  }
  int sign = 1;
  if (c == '-') {
    c = GC();
    sign = -1;
  }
  while (c >= 48 && c <= 57) {
    x = x * 10 + c - 48;
    c = GC();
  }
  return sign * x;
}

VII adj[510];
int dist[510];
int n;

void dijkstra(int src) {  
  REP(i, 505) {
    dist[i] = 500000000;
  }
  dist[src] = 0;
  set<II> q;
  q.insert(MP(dist[src], src));
  while (!q.empty()) {
    II p = *(q.begin());
    int u = p.second;
    q.erase(q.begin());
    REP(i, adj[u].size()) {
      int v = adj[u][i].first, cost = adj[u][i].second;
      if (dist[u] + cost < dist[v]) {
        q.erase(MP(dist[v], v));
        dist[v] = dist[u] + cost;
        q.insert(MP(dist[v], v));
      }
    }
  }
}

int main() {
  n = read_int();
  REP(i, n) {
    int a = read_int(), b = read_int(), c = read_int();
    adj[a].PB(MP(b, c));
    adj[b].PB(MP(a, c));
  }
  dijkstra(read_int());
  TCASE {
    int ans = dist[read_int()];
    if (ans < 500000000) {
      cout << ans << endl;
    } else {
      cout << "NO PATH" << endl;
    }
  }
  return 0;
}
