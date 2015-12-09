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
const int maxn = 1010;
int s[maxn];
PII a[maxn * maxn];
int n;

int l_b(int index, int d) {
    int l = 0, r = index - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid].first >= d) {
            r = mid;
        }
        else if (a[mid].first < d) {
            l = mid + 1;
        }
    }
    return r;
}


int main() {
    ios::sync_with_stdio(false);

    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        int index = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                a[index].first = s[i] + s[j];
                a[index].second = i * 1000 + j;
                index++;
            }
        }
        sort(a, a + index);
        int ans = 0;
        bool flag = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)continue;
                int d = s[i] - s[j];
                int id = l_b(index, d);
                for (int k = id; k < index && a[k].first <= d; k++) {
                    if (a[k].first == d) {
                        int x = (a[k].second) / 1000;
                        int y = (a[k].second) % 1000;
                        if (x != i && x != j && y != i && y != j) {
                            ans = max(ans, s[i]);
                            flag = 1;
                        }
                    }
                    //			if(flag)break;
                }
                //		if(flag)break;
            }
            //	if(flag)break;
        }
        if (flag)
            cout << ans << endl;
        else
            cout << "no solution" << endl;
    }

    return 0;
}


