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

int mat[310][310];
short BIT[300][100010];

void update(short *bit, int idx) {
  for (; idx <= 100005; idx += idx & -idx) {
    bit[idx]++;
  }
}

int get(short *bit, int idx) {
  int ans = 0;
  for (; idx; idx -= idx & -idx) {
    ans += (int) bit[idx];
  }
  return ans;
}

// a > b => ulta(a) < ulta(b)
int ulta(int n) {
  return 100002 - n;
}

int main() {
  int n = read_int(), m = read_int();
  REP(i, n) {
    REP(j, m) {
      mat[i][j] = read_int();
    }
  }
  LL inv = 0;
  REP(i, n) {
    REP(j, m) {
      REP(k, j + 1) {
        inv += get(BIT[k], ulta(mat[i][j] + 1));
      }
      update(BIT[j], ulta(mat[i][j]));
    }
  }
  cout << inv << endl;
  return 0;
}
