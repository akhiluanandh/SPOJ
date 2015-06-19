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

LL next_pwr_2(LL n) {
  n++;
  while (n != (n & -n)) {
    n += (n & -n);
  }
  return n;
}

LL num_e(LL n) {
  if (n < 2) {
    return 0;
  }
  LL e = next_pwr_2(n) - 1 - n;
  return e + 2LL * num_e((n - e) / 2);
}

int main() {
  TCASE {
    LL n;
    cin >> n;
    LL eve = num_e(n), odd = n + 1 - eve;
    cout << eve << " " << odd << endl;
  }
  return 0;
}
