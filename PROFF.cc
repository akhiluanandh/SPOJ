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

int main() {
  while (1) {
    LL a, b;
    cin >> a >> b;
    if (a == 0 && b == 0) {
      break;
    }
    int car = 0, num = 0;
    while (a || b) {
      car = ((a % 10) + (b % 10) + car >= 10);
      num += car;
      a /= 10;
      b /= 10;
    }
    if (!num) {
      cout << "No carry operation." << endl;
    } else if (num == 1) {
      cout << "1 carry operation." << endl;
    } else {
      cout << num << " carry operations." << endl;
    }
  }
  return 0;
}
