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
ll b[20];
ll a[110];
ll c[110];
ll ans[110];
bool f;
vector<int>G[110];
vector<int>vec[110];
int dfs(int u){
    ll sum =0;
    vec[u].clear();
    for(int i=0;i<G[u].size();i++){
        int tmp;
        tmp = dfs(G[u][i]);
        vec[u].PB(tmp);
        sum += tmp;
    }
   // cout<<u<<" "<<sum+b[u]<<endl;
    ll tot = 0;
    //sum += ;
    for(int i=0;i<G[u].size();i++){
        ll tmp = sum - vec[u][i];
        tot += tmp*(ll)vec[u][i];
    }
    tot/=2;
   // cout<<u<<" "<<tot<<endl;
    tot += b[u]*sum;
    if(tot<a[u])f=0;
    return sum+b[u];
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++)cin>>a[i];
        int u,v;
        for(int i=0;i<n;i++)G[i].clear();
        for(int i=0;i<n;i++)vec[i].clear();
        for(int i=0;i<n-1;i++){
            cin>>u>>v;
            u--;v--;
            G[u].PB(v);
        }
        int tot = 1<<n;
        f = 1;
        int minn = INF;
        for(int i=0;i<tot;i++){
            f=1;
            for(int j=0;j<n;j++){
                if((1<<j)&i)b[j]=1;
                else b[j]=0;
            }
           // for(int j=0;j<n;j++){
           //     cout<<b[j]<<" ";
           // }
          //  cout<<endl;
            dfs(0);
           // system("pause");
            if(f){
                int sum = 0;
                for(int j=0;j<n;j++)sum+=b[j];
                if(sum<minn){
                    minn = sum;
                    for(int j=0;j<n;j++)ans[j]=b[j];
                }
            }
        }
        vector<int>gao;
        if(minn==INF)cout<<-1<<endl;
        else{
            cout<<minn<<endl;
            if(minn==0);
            else {
                for(int i=0;i<n;i++){
                    if(ans[i])gao.PB(i+1);
                }
                for(int i=0;i<gao.size();i++){
                    if(i)cout<<" ";
                    cout<<gao[i];
                }
                cout<<endl;
            }
        }

    }
    return 0;
}
