//#pragma comment(linker, "/STACK:102400000,102400000")
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
#include <cctype>

using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X, Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X, N) for(int X=0;X<N;X++)
#define REP2(X, L, R) for(int X=L;X<=R;X++)
#define DEP(X, R, L) for(int X=R;X>=L;X--)
#define CLR(A, X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
char str[1010];
bool vis[1010];
int a[1010];

int main() {
    ios::sync_with_stdio(false);
    cin >> str + 1;
    int len = strlen(str + 1);
    vis[1] = 1;
    for (int i = 2; i <= 1010; i++) {
        vis[i] = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                vis[i] = 0;
            }
        }
    }
    for (int i = 2; i * 2 <= len; i++)vis[i] = 0;//all
    for (int i = 1; i <= len; i++)a[str[i]]++;
    int k = 1;
    for (int i = 0; i < 1010; i++)
        if (a[i] > a[k])k = i;
    for (int i = 1; i <= len; i++) {
        if (!vis[i]) {
            if (!a[k]) {
                cout << "NO" << endl;
                return 0;
            }
            str[i] = k;
            a[k]--;
        }
    }
    k = 1;
    for (int i = 1; i <= len; i++) {
        if (vis[i]) {
            while (!a[k])k++;
            str[i] = k;
            a[k]--;
        }
    }
    cout << "YES" << endl;
    cout << str + 1 << endl;
    return 0;
}


