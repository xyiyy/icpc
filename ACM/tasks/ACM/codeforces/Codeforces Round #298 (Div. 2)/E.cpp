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
ll a[200010];
int b[200010];
int c[200010];
int tmp[110];
int main()
{
	ios::sync_with_stdio(false);
    int n,m;
    ll ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cin>>m;
    int t=0;
    for(int i=1;i<=m;i++){
        cin>>t;
        b[t]++;
    }
    if(m==1){
        cout<<0<<endl;
        return 0;
    }
    int num=0;
    int x=1;
    tmp[0]=1;
    tmp[1]=n;
    num=2;
    for(int i=2;i<=n-1;i++){
        if(b[i]>b[i-1]||b[i]>b[i+1])tmp[num++]=i;
    }
    int gao=-1;
    bool check=0;
    while(num--){
        x=tmp[num];
        int f=0;
        int tot=1;
        for(int i=1;i<=n;i++)c[i]=b[i];
        ans=0;
        if(!c[x])continue;
        c[x]--;
        int last=x;
        x++;
        if(x<1){x+=2;f=0;}
        if(x>n){x-=2;f=1;}
        while(tot<m){
            if(!c[x])break;
            ans+=abs(a[x]-a[last]);
            c[x]--;
            tot++;
            last=x;
            if(f)x--;
            else x++;
            if(x<1){x+=2;f=0;}
            if(x>n){x-=2;f=1;}
        }
        if(tot==m){
            //cout<<" as"<<endl;
              //  cout<<tmp[num]<<" "<<ans<<endl;
            if(!check){
                gao=ans;
                check=1;
            }
            else{
                if(gao!=ans){
                    gao=-1;
                    break;
                }
            }
        }
        //cin>>f;
       /* f=1;
        ans=0;
        tot=1;
        x=tmp[num];
        last=x;
        for(int i=1;i<=n;i++)c[i]=b[i];
        x--;
        if(x<1){x+=2;f=0;}
        if(x>n){x-=2;f=1;}
        while(tot<m){
           // if(tmp[num]==1)cout<<x<<endl;
            if(!c[x])break;
            ans+=abs(a[x]-a[last]);
            c[x]--;
            //cout<<x<<endl;
            tot++;
            last=x;
            if(f)x--;
            else x++;
            if(x<1){x+=2;f=0;}
            if(x>n){x-=2;f=1;}
        }
        if(tot==m){
            //    cout<<tmp[num]<<" "<<ans<<endl;
            if(!check){
                gao=ans;
                check=1;
            }
            else{
                if(gao!=ans){
                    gao=-1;
                    break;
                }
            }
        }*/
    }

    cout<<gao<<endl;
	return 0;
}



