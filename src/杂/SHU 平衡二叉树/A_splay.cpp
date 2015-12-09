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
int n;
const int maxn = 100005;
int pre[maxn], key[maxn], ch[maxn][2], root, tot;

void newnode(int &r, int father, int k) {
    r = ++tot;
    pre[r] = father;
    key[r] = k;
    ch[r][0] = ch[r][1] = 0;
}

void rotate(int x, int d)//0×óÐý,1ÓÒÐý
{
    int y = pre[x];
    ch[y][!d] = ch[x][d];
    pre[ch[x][d]] = y;
    if (pre[y])
        ch[pre[y]][ch[pre[y]][1] == y] = x;
    pre[x] = pre[y];
    ch[x][d] = y;
    pre[y] = x;
}

void splay(int r, int goal) {
    while (pre[r] != goal) {
        if (pre[pre[r]] == goal)
            rotate(r, ch[pre[r]][0] == r);
        else {
            int y = pre[r];
            int d = (ch[pre[y]][0] == y);
            if (ch[y][d] == r) {//Ö®
                rotate(r, !d);
                rotate(r, d);
            }
            else {//Ò»
                rotate(y, d);
                rotate(r, d);
            }
        }
    }
    if (goal == 0)root = r;
    //cout<<"ok"<<endl;
}

int insert(int k) {
    int r = root;
    while (ch[r][k > key[r]]) {
        if (key[r] == k) {
            splay(r, 0);
            return 0;
        }
        r = ch[r][k > key[r]];
    }
    newnode(ch[r][k > key[r]], r, k);
    splay(ch[r][k > key[r]], 0);
    return 1;
}

int get_pre(int r) {
    int d = ch[r][0];
    if (d == 0)return INF;
    while (ch[d][1]) {
        d = ch[d][1];
    }
    return key[r] - key[d];
}

int get_next(int r) {
    int d = ch[r][1];
    if (d == 0)return INF;
    //cout<<"ok"<<endl;
    while (ch[d][0]) {
        d = ch[d][0];
    }
    return key[d] - key[r];
}

int main() {
    ios::sync_with_stdio(false);
    int num, ans;
    while (scanf("%d", &n) != EOF) {
        tot = ans = 0;
        for (int i = 0; i < n; i++) {
            num = 0;
            scanf("%d", &num);
            if (!i) {
                ans += num;
                newnode(root, 0, num);
            }
            else {
                if (insert(num) == 1) {
                    int x = get_pre(root);
                    //cout<<x<<endl;
                    int y = get_next(root);
                    //	cout<<x<<"  "<<y<<endl;
                    ans = (ans + min(x, y));
                    //cout<<ans<<endl;
                }
                else continue;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}


