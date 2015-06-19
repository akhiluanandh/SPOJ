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
  while (c < 48 && c > 57 && c != '-') {
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

int occ[2][4][1010][4];
string s[2];
int n;

int main() {
  n = read_int();
  map<char, int> chars;
  chars['A'] = 0;
  chars['U'] = 1;
  chars['C'] = 2;
  chars['G'] = 3;
  cin >> s[0] >> s[1];
  for (int i = 1; i <= n; i++){
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        occ[0][j][i] = occ[0][j][i - 1][k];
        occ[1][j][i] = occ[1][j][i - 1][k];
      }
      occ[0][chars[s[0][i - 1]]][i][i % 4]++;
      occ[1][chars[s[1][i - 1]]][i][i % 4]++;
    }
  }
  for (int q = read_int(); q--; ) {
    int i1 = read_int(), i2 = read_int(), l = read_int();
    int delta1 = i1 % 4;
    int delta2 = i2 % 4;
    int ans = 0;
    for (int j = 0; j < 4; j++) {
      
    }
  }
  return 0;
}
