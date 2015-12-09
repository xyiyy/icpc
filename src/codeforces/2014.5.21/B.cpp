#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>

using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X, Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X, N) for(int X=0;X<N;X++)
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long ll;
int a[5] = {0, 1, 2, 3, 4};
int b[5][5];

int main() {
    ios::sync_with_stdio(false);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> b[i][j];
        }
    }
    int maxn = 0;
    do {
        int temp = 0;
        temp = b[a[0]][a[1]] + b[a[1]][a[0]] + 2 * (b[a[2]][a[3]] + b[a[3]][a[2]]);
        temp += b[a[1]][a[2]] + b[a[2]][a[1]] + 2 * (b[a[3]][a[4]] + b[a[4]][a[3]]);
        if (temp > maxn)
            maxn = temp;
    } while (next_permutation(a, a + 5));
    cout << maxn << endl;
    return 0;
}

