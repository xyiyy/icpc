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
/*ll a[100010];
void push_down(int cur){
    int lx=cur<<1;
    int rx= cur<<1|1;
    a[lx]=a[lx]/__gcd(a[cur],a[lx])*a[cur];
    a[rx]=a[rx]/__gcd(a[cur],a[rx])*a[cur];
    a[cur]=1;
}
void update(int l,int r,int lx,int rx,int cur,ll inc){
    if(lx<=l&&rx>=r){
        a[cur]=a[cur]/__gcd(a[cur],inc)*inc;
        return;
    }
    if(lx>r||rx<l)return;
    push_down(cur);
    int mid =(l+r)>>1;
    if(lx<=mid)update(l,mid,lx,rx,cur<<1,inc);
    if(rx>mid)update(mid+1,r,lx,rx,cur<<1|1,inc);
}*/
ll ans[10010];
int l[10010],r[10010];
ll a[10010];
int p[10010];
bool cmp(int x,int y){
    if(r[x]==r[y]){
        if(l[x]==l[y])return a[x]>a[y];
        return l[x]<l[y];
    }
    return r[x]<r[y];
}
int main()
{
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        /*int n,q;
        for(int i=0;i<10000;i++)a[i]=1;
        cin>>n>>q;
        int len=1;
        while(len<=n)len<<=1;
        for(int i=0;i<q;i++){
            cin>>l>>r;
            update(l,r,1,n,1);
        }
        for(int i=0;i<len;i++){
            push_down(i);
        }*/
        int n,q;
        cin>>n>>q;
        for(int i=0;i<q;i++){
            cin>>l[i]>>r[i]>>a[i];
            p[i]=i;
        }
        sort(p,p+q,cmp);
        for(int i=1;i<=n;i++)ans[i]=1;
        bool flag=0;
        for(int i=0;i<q;i++){
            int k=p[i];
            if(i&&r[p[i]]==r[p[i-1]]){
                if(a[p[i]]<a[p[i-1]])flag=1;
            }
            if(flag)break;
            //cout<<l[k]<<endl;
            //cout<<a[k]<<endl;
            for(int j=l[k];j<=r[k];j++){
                ans[j]=ans[j]/__gcd(ans[j],a[k])*a[k];
                //cout<<ans[j]<<endl;
            }
        }
        if(flag){
            cout<<"Stupid BrotherK!"<<endl;
            continue;
        }
        for(int i=0;i<n;i++){
            if(i)cout<<" ";
            cout<<ans[i+1];
        }
        cout<<endl;


    }
	return 0;
}




