//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
#define rep2(X,L,R) for(int X=L;X<=R;X++)
#define dep(X,R,L) for(int X=R;X>=L;X--)
#define clr(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> vii;
typedef vector<int> vi;
int a[10001];
map<int,int>ms;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    scanf("%d",&n);
    int x;
    rep(i,10000){
        a[i] = (((rand() % 1024) << 10) | (rand() % 1024)) % n;
    }
    sort(a,a+10000);
    int num = unique(a,a+10000) - a;
    int now = 0;
    a[num] = -1;
    rep(i,n){
        scanf("%d",&x);
        if(i == a[now])ms[x]++,now++;
    }
    int ans;
    int maxx = 0;
    for(map<int,int>::iterator it = ms.begin();it != ms.end();it++){
        if(it->second > maxx){
            ans = it->first;
            maxx = it->second;
        }
    }
    printf("%d\n",ans);
    return 0;
}


