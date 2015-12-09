#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
const int inf = 0xfffffff;
int preminv[21];
int ri[21], hi[21];
int total, floornum;
int ans;

int dfs(int n, int v, int s, int maxr, int maxh) {
    int res;
    int i, tmpr, tmph, tmpsum;
    if (n > floornum) {
        if (v == total && s + ri[1] * ri[1] < ans) {
            ans = s + ri[1] * ri[1];
            return 1;
        }
    }
    for (ri[n] = maxr - 1; ri[n] >= floornum - n + 1; ri[n]--) {
        res = 2.0 * (total - v) / ri[n] + ri[1] * ri[1];
        if (res + s >= ans) continue;
        for (hi[n] = maxh - 1; hi[n] >= floornum - n + 1; hi[n]--) {
            if (v + ri[n] * ri[n] * hi[n] + preminv[floornum - n] > total) continue;
            tmpr = ri[n], tmph = hi[n], tmpsum = 0;
            for (i = n; i <= floornum; i++) {
                tmpsum += tmpr * tmpr * tmph;
                tmpr--, tmph--;
            }
            if (v + tmpsum < total) continue;
            dfs(n + 1, v + ri[n] * ri[n] * hi[n], s + 2 * ri[n] * hi[n], ri[n], hi[n]);
        }
    }
    return 1;
}

int main() {
    int tmpv, tmpr, tmph;
    int i;
    tmpv = 0;
    for (i = 1; i < 21; i++) {
        tmpv += i * i * i;
        preminv[i] = tmpv;
    }
    while (cin >> total >> floornum) {
        ans = inf;
        tmpv = total - preminv[floornum - 1];
        if (tmpv > 0) {
            tmpr = sqrt(1.0 * tmpv / floornum) + 1;
            tmph = 1.0 * tmpv / (floornum * floornum) + 1;
            dfs(1, 0, 0, tmpr, tmph);
        }
        if (ans == inf) {
            ans = 0;
        }
        cout << ans << endl;
    }
    return 0;
}
