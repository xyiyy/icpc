#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <iterator>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
using namespace std;

#define si1(a) scanf("%d",&a)
#define si2(a,b) scanf("%d%d",&a,&b)
#define sd1(a) scanf("%lf",&a)
#define sd2(a,b) scanf("%lf%lf",&a,&b)
#define ss1(s)  scanf("%s",s)
#define pi1(a)    printf("%d\n",a)
#define pi2(a,b)  printf("%d %d\n",a,b)
#define mset(a,b)   memset(a,b,sizeof(a))
#define forb(i,a,b)   for(int i=a;i<b;i++)
#define ford(i,a,b)   for(int i=a;i<=b;i++)

typedef long long LL;
const int N=40000;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-7;

int n,m,cnt;
LL a[15];

LL gcd(LL a,LL b)
{
    while(b)
    {
        LL t=a%b;
        a=b;
        b=t;
    }
    return a;
}

//ÈÝ³â
void dfs(int now,int count,LL lcm,LL &ans)
{
    lcm=a[now]/gcd(lcm,a[now])*lcm;
    if(count&1) ans+=(n)/lcm;
    else        ans-=(n)/lcm;

    for(int i=now+1;i<cnt;i++)
        dfs(i,count+1,lcm,ans);
}

int main()
{
//    freopen("input.txt","r",stdin);
    int i,j;
    while(cin>>n>>m)
    {
        cnt=0;
        for(int i=0;i<m;i++)
        {
            int x;
            scanf("%d",&x);
            if(x)
                a[cnt++]=x;
        }
        LL ans=0;
        for(int i=0;i<cnt;i++)
        {
            dfs(i,1,a[i],ans);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

