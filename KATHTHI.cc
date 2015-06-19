#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
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

char grid[1010][1010];
bool vis[1010][1010];
int com[1010][1010];
tr1::unordered_set<int> adj[1000010];
int tm[1000010];

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int r, c;

bool val(int x, int y) {
  return x >= 0 && y >= 0 && x < r && y < c;
}

int main() {
  TCASE {
    r = read_int(), c = read_int();
    REP(i, r) {
      REP(j, c) {
        do {
          grid[i][j] = GC();
        } while (grid[i][j] < 'a' || grid[i][j] > 'z');
      }
    }
    CLR(vis);
    REP(i, 1000010) {
      adj[i].clear();
    }
    memset(com, -1, sizeof(com));
    int ncom = 0;
    REP(i, r) {
      REP(j, c) {
        if (!vis[i][j]) {
          vis[i][j] = true;
          com[i][j] = ncom++;
          queue<II> q;
          q.push(MP(i, j));
          while (!q.empty()) {
            II p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            REP(_i, 4) {
              int nx = x + dx[_i], ny = y + dy[_i];
              if (val(nx, ny)) {
                if (!vis[nx][ny] && grid[x][y] == grid[nx][ny]) {
                  vis[nx][ny] = true;
                  com[nx][ny] = com[x][y];
                  q.push(MP(nx, ny));
                } else if (vis[nx][ny]) {
                  if (com[x][y] != com[nx][ny]) {
                    adj[com[x][y]].insert(com[nx][ny]);
                    adj[com[nx][ny]].insert(com[x][y]);
                  }
                }
              }
            }
          }
        }
      }
    }
    queue<int> q;
    memset(tm, -1, sizeof(tm));
    tm[com[0][0]] = 0;
    q.push(com[0][0]);
    while (!q.empty()) {
      int c = q.front();
      q.pop();
      for (tr1::unordered_set<int> :: iterator it = adj[c].begin(); it != adj[c].end(); it++) {
        int u = *it;
        if (tm[u] == -1) {
          tm[u] = tm[c] + 1;
          q.push(u);
        }
      }
    }
    cout << tm[com[r - 1][c - 1]] << endl;
  }
  return 0;
}
