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

map<pair<II, int>, int> queries;
map<int, int> nums;
int arr[30010], BIT[300010], n, q;

void upd(int x, int val) {
  for (x += 2; x <= 300005; x += (x & -x)) {
    BIT[x] += val;
  }
}

int get(int x) {
  int val = 0;
  for (x += 2; x > 0; x -= x & -x) {
    val += BIT[x];
  }
  return val;
}

int res[200010];

int main() {
  n = read_int();
  REP(i, n) {
    arr[i] = read_int();
    nums[arr[i]] = 0;
  }
  q = read_int();
  REP(i, q) {
    int a = read_int(), b = read_int(), k = read_int();
    a--, b--;
    nums[k] = 0;
    queries[MP(MP(a, b), k)] = i;
  }
  int pos = 300000;
  for (map<int, int> :: iterator it = nums.begin(); it != nums.end(); it++) {
    it -> second = pos--;
  }
  int i = 0, j = 0;
  upd(nums[arr[0]], 1);
  for (map<pair<II, int>, int> :: iterator it = queries.begin(); it != queries.end(); it++) {
    pair<II, int> p = it -> first;
    int a = p.first.first, b = p.first.second, k = p.second, qnum = it -> second;
    cout << a << " " << b << " " << k << " " << nums[k] << " " << qnum << endl;
    while (j < b) {
      upd(nums[arr[++j]], 1);
      cout << "updated " << nums[arr[j]] << endl;
    }
    while (i < a) {
      cout << "updating " << nums[arr[i]] << endl;
      upd(nums[arr[i++]], -1);
    }
    res[qnum] = get(nums[k] - 1);
  }
  REP(i, q) {
    printf("%d\n", res[i]);
  }
  return 0;
}
