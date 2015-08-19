#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
typedef long long LL;
const int MAXN = 100000 + 10;

char op[MAXN];
bool vs[MAXN];

void exit(const char *s, int status) {
  printf("%s\n", s);
  exit(status);
}

int main(int argc, char **argv) {
  FILE *fin = fopen(argv[1], "r");
  int T;
  fscanf(fin, "%d", &T);
  for (int cas = 1; cas <= T; ++ cas) {
    int n, m; fscanf(fin, "%d%d", &n, &m);
    LL sum = (LL)n * (n + 1) / 2;
    if (sum % m == 0 && n >= m * 2 - 1) {
      scanf("%s", op); sum /= m;
      if (strcmp(op, "YES") != 0) exit("WA", 0);
      for (int i = 1; i <= n; ++ i) vs[i] = 0;
      for (int i = 0; i < m; ++ i) {
        int sz; scanf("%d", &sz);
        if (sz < 1 || sz > n) exit("sz range error", 0);
        LL tmp(0);
        while (sz --) {
          int x; scanf("%d", &x);
          if (x < 1 || x > n) exit("number range error", 0);
          if (vs[x]) exit("duplicated number", 0);
          tmp += x; vs[x] = 1;
        }
        if (tmp != sum) exit("sum not equal", 0);
      }
    }
    else {
      scanf("%s", op);
      if (strcmp(op, "NO") == 0) continue;
      exit("WA", 0);
    }
  }
  exit("AC", 0);
}