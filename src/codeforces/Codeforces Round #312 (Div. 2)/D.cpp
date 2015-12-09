//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
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
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
int a[100010];
ll b[100010];
ll c[100010];
int d[100010];
int p[100010];
int main(){
    int h,q;
    scanf("%d%d",&h,&q);
    for(int i=0;i<q;i++{
        scanf("%d%I64d%I64%d",&a[i],&b[i],&c[i],&d[i]);
        p[i]=i;
        b[i]=b[i]<<(h-a[i]);
        for(int j=a[i];j<h;j++){
            c[i]=(c[i]<<1)|1;
        }
}
/*ll l,r,z;
ll n,m;
map<ll,ll>ms;
map<ll,ll>::IT x,y;
void gao(int d)
{
    if(d==0){
        if(ms.lower_bound(r+1)->first!=r+1){
            x= ms.lower_bound(r+1);
            x--;
            ms.insert(MP(r+1));
        }
        x=ms.lower_bound(l);
        int k =ms.upper_bound(r)->first;
        while(k>x->first){
            ms.erase(x);
            x=ms.lower_bound(l);
        }
        ms.insert(MP(l,0));
    }
    else{
        if(ms.lower_bound(r+1)->first!=r+1){
            x=ms.lower_bound(r+1);
            x--;
            while(x->second==0&&){
                x--;
            }
            //if()
           // ms.insert(MP(r+1,x->second));
        }
        x=ms.lower_bound(l);
        int k=ms.upper_bound(r)_.first;
        while(k>x->first){

        }
    }
    if(ms.lower_bound(r+1)->first!=r+1)
    {
        x=ms.lower_bound(r+1);
        x--;
        ms.insert(MP(r+1,x->second));
    }
    x=ms.lower_bound(l);
    int k=ms.upper_bound(r)->first;
    while(k>x->first)
    {
        ms.erase(x);
        x=ms.lower_bound(l);
    }
    ms.insert(MP(l,z));

}


int main()
{
    //ios::sync_with_stdio(false);
    int h,q;
    scanf("%d%d",&h,&q);
    ms.insert(MP(1LL<<(h+1),0));
    ms.insert(MP((1<<h)-1,1));
    for(int i=0;i<q;i++{
        int a,d;
        ll b,c;
        scanf("%d%I64d%I64d%d",&a,&b,&c,&d);
        l=b<<(h-a);
        for(int j=a;j<h;j++){
            c<<=1;
            c|=1;
        }
        r= c;
        gao(d);

    }
    while(scanf("%lld%lld",&n,&m)!=EOF)
    {
        ms.clear();
        ms.insert(MP(INF,0));
        ms.insert(MP(0,0));
        for(int i=0;i<m;i++)
        {
            scanf("%lld%lld%lld",&l,&r,&z);
            z-=2;
            gao();
        }
        ll sum=0;
        for(x=ms.begin();x->first!=INF;)
        {
            y=x;
            x++;
            sum+=y->second*((x->first)-(y->first));
        //  cout<<sum<<endl;
        }
        printf("%lld\n",sum);
    }

    return 0;
}*/
