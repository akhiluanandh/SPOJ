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

VI factorize(int n) {
  VI ans;
  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      ans.PB(i);
    }
  }
  return ans;
}

LL dp[55][5010];
LL coins[55][2];
int n, s;
LL ways(int fac) {
  int times = s / fac;
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int j = 1; j <= fac; j++) {
    if (coins[0][0] == j && coins[0][1] >= times) {
      dp[0][j] = 1;
    } else {
      dp[0][j] = 0;
    }
  }
  for (int i = 1; i < n; i++) {
    dp[i][0] = 1;
    for (int j = 1; j <= fac; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j >= coins[i][0] && coins[i][1] >= times) {
        dp[i][j] += dp[i - 1][j - coins[i][0]];
      }
    }
  }
  return dp[n - 1][fac];
}

int main() {
  int c = 0;
  TCASE {
    c++;
    s = read_int(), n = read_int();
    REP(i, n) {
      coins[i][0] = read_int();
      coins[i][1] = read_int();
    }
    VI f = factorize(s);
    LL res = 0;
    for (VI :: iterator it = f.begin(); it != f.end(); it++) {
      int fac = *it;
      res += ways(fac);
    }
    cout << "Case " << c << ": " << res << endl;
  }
  return 0;
}
