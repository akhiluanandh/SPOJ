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
int dis[1010][1010];

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int r, c;

inline bool val(int x, int y) {
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
    REP(i, r)
      REP(j, c)
        dis[i][j] = 100000000;
    dis[0][0] = 0;
    set<pair<int, II> > q;
    q.insert(MP(0, MP(0, 0)));
    while (!q.empty()) {
      II p = (*(q.begin())).second;
      q.erase(q.begin());
      int x = p.first, y = p.second;
      REP(_i, 4) {
        int nx = x + dx[_i], ny = y + dy[_i];
        if (val(nx, ny)) {
          int d = (grid[x][y] != grid[nx][ny]);
          if (dis[x][y] + d < dis[nx][ny]) {
            q.erase(MP(dis[nx][ny], MP(nx, ny)));
            dis[nx][ny] = d + dis[x][y];
            q.insert(MP(dis[nx][ny], MP(nx, ny)));
          }
        }
      }
    }
    cout << dis[r - 1][c - 1] << endl;
  }
  return 0;
}
