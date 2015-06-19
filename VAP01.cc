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

int keys[26];

int main() {
  TCASE {
    int n = read_int();
    string S;
    cin >> S;
    memset(keys, 0, sizeof(keys));
    int ans = 0;
    for (int i = 0; i < ((n - 1) << 1); i++) {
      if (!(i & 1)) {
        keys[S[i] - 'a']++;
      } else {
        if (keys[S[i] - 'A']) {
          keys[S[i] - 'A']--;
        } else {
          ans++;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
