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
const int maxn = 100010;
ll num[maxn * 4];
ll sum[maxn * 16];
ll key[maxn * 16];
ll laz[maxn * 16];
int zuo[maxn * 16], you[maxn * 16];
//ll len[maxn];
//int size[maxn*16];
int a[maxn], b[maxn], c[maxn];
int d[maxn * 4];
bool mix[maxn * 16];

void pushup(int cur) {
    if (key[cur << 1] == key[cur << 1 | 1])key[cur] = key[cur << 1];
    else mix[cur] = 1;
    sum[cur] = (you[cur << 1] - zuo[cur << 1] + 1) * key[cur << 1] +
               (you[cur << 1 | 1] - zuo[cur << 1 | 1] + 1) * key[cur << 1 | 1];
    if ((zuo[cur << 1 | 1] - you[cur << 1] - 1) > 0)sum[cur] += (zuo[cur << 1 | 1] - you[cur << 1] - 1) * laz[cur];
//	if(zuo[cur<<1|1]==you[cur])
    cout << sum[cur] << " " << cur << endl;
}

void build(int l, int r, int cur) {
    zuo[cur] = d[l];
    you[cur] = d[r];
    key[cur] = 2;
    laz[cur] = 2;
    mix[cur] = 0;
    if (r < l)return;
    if (l == r) {
        num[l] = d[l];
        key[cur] = 2;
        sum[cur] = 2;
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, cur << 1);
    build(mid + 1, r, cur << 1 | 1);
    /*if(num[l])*/
    /*if(num[r+1])*/
//	zuo[cur]=zuo[cur<<1];
//	you[cur]=you[cur<<1|1];
//	else you[cur]=num[r];
//	cout<<zuo[cur]<<" "<<you[cur]<<" "<<cur<<endl;
//	sum[cur]=(you[cur]-zuo[cur]+1)*2;
//	cout<<sum[cur]<<endl;
    pushup(cur);
}

void pushdown(int cur) {
    if (!mix[cur])
        key[cur << 1] = key[cur << 1 | 1] = key[cur];
    //key[cur]=0;

}

void update(int curl, int curr, int l, int r, int cur, int inc) {
    if (curl > r || curr < l)return;
    int mid = (l + r) / 2;
    if (curl <= mid && curr > mid) {
        laz[cur] = inc;
    }
    if (curl <= l && curr >= r) {
        key[cur] = inc;
        cout << zuo[cur] << " " << you[cur] << " " << cur << endl;
        sum[cur] = (you[cur] - zuo[cur] + 1) * key[cur];
        cout << sum[cur] << endl;
        mix[cur] = 0;
        return;
    }
    pushdown(cur);
    if (curl <= mid)update(curl, curr, l, mid, cur << 1, inc);
    if (curr > mid)update(curl, curr, mid + 1, r, cur << 1 | 1, inc);
    pushup(cur);
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    while (cin >> n >> m) {
        int id = 0;
        for (int i = 0; i < m; i++) {
            cin >> a[i] >> b[i] >> c[i];
            d[id++] = a[i];
            d[id++] = b[i];
        }
        CLR(num, 0);
        CLR(sum, 0);
        sort(d, d + id);
        id = unique(d, d + id) - d;
        int temp = id;
        for (int i = 1; i < temp; i++) {
            if (d[i] != d[i - 1] + 1)d[id++] = d[i - 1] + 1;
            //	if(d[i]-d[i-1]>2)d[id++]=d[i]-1;
        }
        sort(d, d + id);
        //d[id]=d[id-1];
        //	d[id]=d[id-1];
        //	for(int i=0;i<id;i++)
        //	{
        //		cout<<d[i]<<endl;
        //	}
        build(0, id - 1, 1);
        //	update(0,id-1,0,id-1,1,2);
        for (int i = 0; i < m; i++) {
            int l = lower_bound(d, d + id, a[i]) - d;
            int r = lower_bound(d, d + id, b[i]) - d;
            update(l, r, 0, id - 1, 1, c[i]);
        }
        //	cout<<sum[1]<<" "<<zuo[1]<<" "<<you[1]<<endl;
        cout << sum[1] - (you[1] - zuo[1] + 1) * 2 << endl;
    }

    return 0;
}


