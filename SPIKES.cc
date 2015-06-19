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

char grid[45][45];
int dist[45][45][2];
int n, m, cap;

bool inside(int x, int y) {
  return x >= 0 && y >= 0 && x < n && y < m;
}

int main() {
  n = read_int(), m = read_int(), cap = read_int();
  set<pair<int, pair<pair<int, int>, bool> > > q;
  REP(i, n) {
    REP(j, m) {
      dist[i][j][0] = dist[i][j][1] = 100000000;
      do {
        grid[i][j] = GC();
      } while (grid[i][j] != '.' && grid[i][j] != 'x' && grid[i][j] != 's' && grid[i][j] != '@' && grid[i][j] != '#');
      if (grid[i][j] == '@') {
        dist[i][j][0] = 0;
        q.insert(MP(0, MP(MP(i, j), false)));
      }
    }
  }
  while (!q.empty()) {
    pair<int, pair<pair<int, int>, bool> > p = *(q.begin());
    q.erase(q.begin());
    int x = p.second.first.first, y = p.second.first.second;
    bool treasure = p.second.second;
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    REP(i, 4) {
      int nx = x + dx[i], ny = y + dy[i];
      if (inside(nx, ny) && grid[nx][ny] != '#') {
        bool ntreasure = (treasure || (grid[nx][ny] == 'x'));
        int cost = (grid[nx][ny] == 's');
        if (dist[x][y][treasure] + cost < dist[nx][ny][ntreasure]) {
          q.erase(MP(dist[nx][ny][ntreasure], MP(MP(nx, ny), ntreasure)));
          dist[nx][ny][ntreasure] = dist[x][y][treasure] + cost;
          if (dist[nx][ny][ntreasure] <= cap) {
            q.insert(MP(dist[nx][ny][ntreasure], MP(MP(nx, ny), ntreasure)));
          }
        }
      }
    }
  }
  bool poss = false;
  REP(i, n) {
    REP(j, m) {
      if (grid[i][j] == '@' && dist[i][j][1] <= cap) {
        poss = true;
        break;
      }
    }
    if (poss) break;
  }
  cout << (poss? "SUCCESS" : "IMPOSSIBLE") << endl;
  return 0;
}
