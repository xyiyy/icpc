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
const int MAXN = 1000010;
char a[MAXN];
char b[MAXN];
int p[MAXN];

void get_next() {
    int len = strlen(b + 1);
    p[1] = 0;
    int j = 0;
    for (int i = 2; i <= len; i++) {
        while (j && b[j + 1] != b[i])j = p[j];
        if (b[j + 1] == b[i])j++;
        p[i] = j;
    }
}

int kmp() {
    int lena = strlen(a + 1);
    int lenb = strlen(b + 1);
    int j = 0, ret = 0;
    get_next();
    for (int i = 1; i <= lena; i++) {
        while (j && b[j + 1] != a[i])j = p[j];
        if (b[j + 1] == a[i])j++;
        if (j == lenb) {
            ret++;
            j = p[j];
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", b + 1);
        scanf("%s", a + 1);
        printf("%d\n", kmp());
    }
    return 0;
}



