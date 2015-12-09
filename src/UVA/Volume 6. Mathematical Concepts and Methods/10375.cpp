#include <iostream>     
#include <fstream>     
#include <algorithm>     
#include <string>     
#include <set>     
#include <map>     
#include <queue>     
#include <utility>     
#include <stack>     
#include <list>     
#include <vector>     
#include <cstdio>     
#include <cstdlib>     
#include <cstring>     
#include <cmath>     
#include <ctime>     
#include <ctype.h>
#include <iomanip>
#include <stdio.h>

using namespace std;
#define ll long long

ll dp[1000][1000];

ll C(int m, int n) {
    if (m < 1000 && n < 1000 && dp[m][n]) return dp[m][n];
    if (m == n || n == 0)return 1;
    if (n == 1) return m;
    ll ret = C(m - 1, n - 1) * m / n;
    if (m < 1000 && n < 1000)dp[m][n] = ret;
    return ret;
}

int main() {
    int p, q, r, s;
    while (cin >> p >> q >> r >> s) {
        double xx = (double) C(p, q) / C(r, s);
        cout << fixed << setprecision(5) << xx << endl;
    }
    return 0;
}
