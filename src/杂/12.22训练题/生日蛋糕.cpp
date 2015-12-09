#include <iostream>   
#include <cmath>  

#define MIN(a, b) (a) < (b)? a : b
using namespace std;

int n, m, minv[21], mins[21];
const int inf = 1000000000;
int best = inf;

void DFS(int depth, int sumv, int sums, int r, int h) {
    if (0 == depth) {
        if (sumv == n && sums < best)
            best = sums;
        return;
    }
    if (sumv + minv[depth - 1] > n || sums + mins[depth - 1] > best || sums + 2 * (n - sumv) / r >= best)
        return;   //第一种为已经搜索到的体积与未搜索到的面积最小值的和与输入的面积相比较若大于，则不符；
    //第二种为 已经搜索到的面积与未搜索到的面积的最小值之和与最大可能面积相比较（即是否超出上限），若超出，则返回；
    //第三种为已经搜索到的面积和剩余的未利用的已给体积所能产生的最大面积与面积值的上限相比较，若超出，则返回
    for (int i = r - 1; i >= depth; i--) {
        if (depth == m)
            sums = i * i;
        int maxh = MIN((n - sumv - minv[depth - 1]) / (i * i), h - 1);
        for (int j = maxh; j >= depth; j--)
            DFS(depth - 1, sumv + i * i * j, sums + 2 * i * j, i, j);
    }
}

int main() {
    cin >> n >> m;
    int rmax = (int) sqrt((double) n);
    int hmax = n;
    minv[0] = mins[0] = 0;
    for (int i = 1; i <= m; i++) {
        minv[i] = minv[i - 1] + i * i * i;
        mins[i] = mins[i - 1] + 2 * i * i;
    }
    DFS(m, 0, 0, rmax, hmax);
    if (best == inf)
        best = 0;
    if (best == 0)
        cout << "0" << endl;
    else
        cout << best << endl;
    return 0;
}  






