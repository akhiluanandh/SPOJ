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

int n, mat[11][11];
int main() {
  TCASE {
    n = read_int();
    REP(i, n) {
      REP(j, n) {
        mat[i][j] = read_int();
      }
    }
    VI order(n);
    REP(i, n) {
      order[i] = i;
    }
    int ans = 0x7FFFFFFF;
    do {
      VI nums(n);
      int S = 0;
      REP(i, n) {
        nums[i] = mat[i][order[i]];
        S += nums[i];
      }
      int W = S / 2;
      VVI dp(n, VI(W + 1));
      REP(i, n) {
        REP(j, W + 1) {
          if (i == 0) {
            if (j >= nums[0]) {
              dp[i][j] = nums[0];
            } else {
              dp[i][j] = 0;
            }
          } else {
            dp[i][j] = dp[i - 1][j];
            if (j >= nums[i]) {
              dp[i][j] = max(dp[i][j], nums[i] + dp[i - 1][j - nums[i]]);
            }
          }
        }
      }
      int poss = abs(S - 2 * dp[n - 1][W]);
      ans = min(ans, poss);
    } while (next_permutation(ALL(order)));
    cout << ans << endl;
  }
  return 0;
}
