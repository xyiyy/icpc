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
vector<int>G[20];
int a[100010];
int b[100010][10];
int f[100];

int main()
{
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int cas=1;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=0;i<=3;i++)G[i].clear();
        for(int i=0;i<n;i++){
            cin>>a[i];
            G[a[i]].PB(i);
            for(int j=1;j<=3;j++){
                if(j==a[i]){
                    b[i][j]=b[i-1][j]+1;
                }else{
                    b[i][j]=b[i-1][j];
                }
            }
        }
        /*for(int i=0;i<n;i++){
            for(int j=1;j<=3;j++){
                cout<<b[i][j]<<" ";
            }
            cout<<endl;
        }*/
        //cout<<"ok"<<endl;
        ll ans =INF;
        int num=0;
        ll tmp =0;//123
        for(int i=0;i<G[1].size();i++){
            tmp+=G[1][i]-i;
            //cout<<tmp<<endl;
        }
        num = G[1].size();
        for(int i=0;i<G[2].size();i++){
            tmp+=G[2][i]+num-b[G[2][i]][1]-(num+i);
            //cout<<tmp<<endl;
        }
        ans = min(tmp,ans);
       // cout<<"123ok"<<"  "<<ans<<endl;
        tmp =0;//132
        for(int i=0;i<G[1].size();i++){
            tmp+=G[1][i]-i;
        }
        num = G[1].size();
        for(int i=0;i<G[3].size();i++){
            tmp+=G[3][i]+num-b[G[3][i]][1]-(num+i);
        }
        ans = min(tmp,ans);
        tmp =0;//213
        for(int i=0;i<G[2].size();i++){
            tmp+=G[2][i]-i;
        }
        num = G[2].size();
        for(int i=0;i<G[1].size();i++){
            tmp+=G[1][i]+num-b[G[1][i]][2]-(num+i);
        }
        ans = min(tmp,ans);
        tmp =0;//231
        for(int i=0;i<G[2].size();i++){
            tmp+=G[2][i]-i;
        }
        num = G[2].size();
        for(int i=0;i<G[3].size();i++){
            tmp+=G[3][i]+num-b[G[3][i]][2]-(num+i);
        }
        ans = min(tmp,ans);
        //cout<<"231ok"<<"  "<<ans<<endl;
        tmp =0;//312
        for(int i=0;i<G[3].size();i++){
            tmp+=G[3][i]-i;
        }
        num = G[3].size();
        for(int i=0;i<G[1].size();i++){
            tmp+=G[1][i]+num-b[G[1][i]][3]-(num+i);
        }
        ans = min(tmp,ans);
       // cout<<"312ok"<<"  "<<ans<<endl;
        tmp =0;//321
        for(int i=0;i<G[3].size();i++){
            tmp+=G[3][i]-i;
        }
        num = G[3].size();
        for(int i=0;i<G[2].size();i++){
            tmp+=G[2][i]+num-b[G[2][i]][3]-(num+i);
        }
        ans = min(tmp,ans);
        //cout<<"321ok"<<"  "<<ans<<endl;
        cout<<"Case #"<<cas++<<": "<<ans<<endl;
    }
	return 0;
}


